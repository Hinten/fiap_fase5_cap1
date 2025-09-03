//
// Created by Lucas on 03/09/2025.
//

#ifndef API_H
#define API_H
#include <Wire.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "../conexao_wifi/conexao_wifi.h"

struct Response
{
    const int status_code;
    const String body;

    JsonDocument toJson() const
    {
        JsonDocument doc;
        const DeserializationError error = deserializeJson(doc, body);
        if (error) {
            // Retorna um documento JSON vazio em caso de erro
            return JsonDocument(nullptr);
        }
        return doc;
    }

};

class Api
{
    const String baseUrl; // Exemplo: "http://api.example.com" sem barra no final
    const String leituraUrl; // Exemplo: "/leitura"
    ConexaoWifi conexao;
    PainelLCD* lcd;

public:
    Api(const String& baseUrl, const String& leituraUrl, const ConexaoWifi& conexao, PainelLCD* lcd = nullptr)
    : baseUrl(baseUrl), leituraUrl(leituraUrl), conexao(conexao), lcd(lcd) {}

    Response get(const String &path) {
        if (!conexao.estaConectado()) {
            return {-1, "Not connected to WiFi"};
        }

        String url = baseUrl;
        if (!path.startsWith("/")) {
            url += "/";
        }
        url += path;

        HTTPClient http;
        http.begin(url);

        const int httpCode = http.GET();

        if (httpCode > 0) {
            const String payload = http.getString();
            http.end();
            return {httpCode, payload};
        } else {
            http.end();
            return {httpCode, "Request failed"};
        }
    }

    Response post(const String &path, const String &body, const String &contentType) {
        if (!conexao.estaConectado()) {
            return {-1, "Not connected to WiFi"};
        }

        String url = baseUrl;
        if (!path.startsWith("/")) {
            url += "/";
        }
        url += path;

        HTTPClient http;
        http.begin(url);
        http.addHeader("Content-Type", contentType);

        const int httpCode = http.POST(body);

        if (httpCode > 0) {
            const String payload = http.getString();
            http.end();
            return {httpCode, payload};
        } else {
            http.end();
            return {httpCode, "Request failed"};
        }
    }

    Response post_json(const String &path, const JsonDocument& json)
    {
        String jsonStr;
        serializeJson(json, jsonStr);

        return post(path, jsonStr, "application/json");
    }

    Response post_leitura(const JsonDocument& json)
    {
        return post_json(leituraUrl, json);
    }


};

#endif //API_H
