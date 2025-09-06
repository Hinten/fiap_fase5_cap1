# Greenhouse Monitoring System

**Summary**: This project implements a greenhouse monitoring system using an ESP32 microcontroller. It collects temperature and humidity data from a DHT22 sensor and soil moisture data from an analog sensor. The system connects to Wi-Fi and serves an HTML dashboard that updates automatically to display the collected data.

## Project Structure
```

# Sistema de Monitoramento de Estufa

Este projeto utiliza um ESP32 e um sensor DHT11 para coletar dados de temperatura e umidade do ar, disponibilizando essas informações em tempo real através de um dashboard web acessível pela rede Wi-Fi.

## Estrutura do Projeto

```
ir_alem_1
├── src
│   ├── greenhouse_monitor.ino      # Código principal do ESP32
│   ├── config
│   │   └── wifi_credentials.h      # SSID e senha do Wi-Fi
├── include
│   ├── sensors.h                   # Funções do sensor DHT11
│   └── web_server.h                # Rotas do servidor web
├── data
│   └── dashboard.html              # Dashboard HTML para visualização dos dados
├── platformio.ini                  # Configuração do PlatformIO
├── README.md                       # Documentação do projeto
├── LICENSE                         # Licença
```

## Funcionalidades

- Mede temperatura e umidade do ar usando o sensor DHT11.
- Conecta o ESP32 à rede Wi-Fi.
- Disponibiliza um dashboard web com atualização automática dos dados.

## Como Utilizar

1. **Monte o circuito:**
	- Conecte o DHT11 ao ESP32 (VCC, GND e DATA no pino definido em `sensors.h`).
2. **Configure o Wi-Fi:**
	- Edite o arquivo `src/config/wifi_credentials.h` com o nome e senha da sua rede Wi-Fi.
3. **Compile e envie o código para o ESP32:**
	- No VS Code, clique em "Upload" no menu do PlatformIO.
4. **Envie o dashboard para o ESP32:**
	- Coloque o arquivo `dashboard.html` na pasta `data`.
	- Clique em "Upload Filesystem Image" no menu do PlatformIO para gravar o arquivo no SPIFFS do ESP32.
5. **Acesse o dashboard:**
	- Após o ESP32 conectar ao Wi-Fi, veja o IP no monitor serial.
	- No navegador, acesse `http://<IP_DO_ESP32>/dashboard.html`.

## Observações

- O dashboard atualiza os dados automaticamente a cada 2 segundos.
- O ESP32 precisa estar na mesma rede Wi-Fi do dispositivo que acessa o dashboard.
- Se quiser adicionar mais sensores, basta criar novas funções e rotas.

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.