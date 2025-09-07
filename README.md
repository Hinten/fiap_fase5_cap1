# FIAP - Faculdade de Informática e Administração Paulista

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# Nome do projeto

## Nome do grupo

## 👨‍🎓 Integrantes: 
- <a href="">Alice C. M. Assis - RM 566233</a>
- <a href="">Leonardo S. Souza - RM 563928</a>
- <a href="">Lucas B. Francelino - RM 561409</a>
- <a href="">Pedro L. T. Silva - RM 561644</a>
- <a href="">Vitor A. Bezerra - RM 563001</a>

## 👩‍🏫 Professores:
### Tutor(a) 
- <a href="proflucas.moreira@fiap.com.br">Lucas Gomes Moreira</a>
### Coordenador(a)
- <a href="profandre.chiovato@fiap.com.br">André Godoi Chiovato</a>

# 🌾 Entrega 1 – Análise e Predição de Rendimento Agrícola

## 📄 Descrição
Este projeto tem como objetivo analisar dados de rendimento agrícola de plantações, buscando compreender os fatores que influenciam a produtividade das safras. O foco está na identificação de padrões, tendências e outliers nos dados, permitindo destacar cenários atípicos que podem afetar a produção agrícola. O fluxo de trabalho integra análise exploratória, clusterização e modelagem preditiva, oferecendo uma abordagem completa de ciência de dados aplicada ao contexto agrícola. Inicialmente, realiza-se a análise exploratória para investigar as características do dataset, incluindo estatísticas descritivas, visualizações de distribuições e relações entre variáveis, além da identificação de inconsistências ou valores discrepantes. Em seguida, aplicam-se técnicas de clusterização, como HDBSCAN, para agrupar observações com comportamentos semelhantes e detectar cenários fora do padrão, permitindo reconhecer padrões emergentes e segmentar diferentes perfis de rendimento. Por fim, são construídos cinco modelos preditivos distintos utilizando regressão, com pré-processamento, treinamento, validação e avaliação automatizados pelo PyCaret. O desempenho dos modelos é comparado por métricas como R², RMSE e MAE, garantindo a seleção de abordagens robustas para previsão da produtividade. Dessa forma, o projeto fornece uma solução completa para prever rendimento agrícola e apoiar decisões estratégicas na gestão das plantações.

---

## 🗂 Estrutura do Projeto
- `crop_yield.csv` – Base de dados com informações sobre rendimento das plantações.
- `treinamento_ia.ipynb` – Notebook com código completo, visualizações e modelagem.

---

## 🛠 Tecnologias e Bibliotecas
- **Python 3**
- Bibliotecas:
  - `numpy`
  - `pandas`
  - `matplotlib`
  - `seaborn`
  - `scikit-learn`
  - `hdbscan`
  - `pycaret`  

---

## 🚀 Etapas do Projeto

### 1️⃣ Análise Exploratória de Dados (EDA)
- Inspeção do dataset (`head`, `shape`, `columns`, `sample`).
- Visualizações:
  - Pairplots para explorar relações entre variáveis.
  - Boxplots para identificar outliers.
- Objetivo: compreender padrões, tendências e inconsistências nos dados.

### 2️⃣ Clusterização e Identificação de Outliers
- Algoritmo: **HDBSCAN** aplicado a colunas numéricas.
- Visualização de clusters para identificar agrupamentos naturais e outliers.

### 3️⃣ Modelagem Preditiva
- Pré-processamento automatizado com **PyCaret**.
- Objetivo: prever a variável `Yield` (rendimento da safra).
- Divisão treino/teste: 80/20.
- Treinamento de cinco modelos de regressão distintos.

### 4️⃣ Seleção e Avaliação dos Melhores Modelos
- Métrica principal: **R² score**.
- Outras métricas: **RMSE** e **MAE**.
- Visualizações:
  - Gráficos de erro
  - Importância das variáveis

### 5️⃣ Conclusão
- O fluxo completo permitiu identificar padrões, outliers e construir modelos robustos de previsão de rendimento.
- HDBSCAN ajudou a detectar cenários discrepantes.
- PyCaret automatizou seleção, treinamento e avaliação de múltiplos algoritmos.

---

## ▶️ Como Executar
1. Instale as dependências com `pip install numpy pandas matplotlib seaborn scikit-learn hdbscan pycaret`.
2. Abra o notebook `Entrega1_Analise_Predicao.ipynb`.
3. Execute as células na ordem apresentada para reproduzir a análise, clusterização e modelagem preditiva.

# Entrega 2 – Estimativa de Custos na AWS

## 📜 Descrição

Este projeto tem como objetivo compreender o funcionamento da computação em nuvem e justificar a escolha de recursos adequados para hospedar uma aplicação simples utilizando a AWS (Amazon Web Services). Durante a atividade, exploramos diferentes serviços da AWS, estimamos custos e comparamos preços entre regiões distintas para fundamentar a tomada de decisão.

Com a API e os modelos de Machine Learning prontos, foi necessário estimar os custos de execução na nuvem AWS.  
Para isso, foi utilizada a **AWS Pricing Calculator** com a seguinte configuração:

- **2 vCPUs**
- **1 GiB de memória**
- **Até 5 Gigabit de rede**
- **50 GB de armazenamento HDD (EBS sc1)**
- **Linux**
- **On-Demand (100%)**

**Comparação de Custos por Região:**

| Região                   | Custo Mensal (On-Demand) | Upfront |
|--------------------------|--------------------------|---------|
| **US East (N. Virginia)** | **USD 6.88**             | 0       |
| **South America (São Paulo)** | **USD 11.22**            | 0       |

📊 **Conclusão**:  
- N. Virginia é ~40% mais barato.  
- São Paulo é mais caro, mas essencial em casos de **restrições legais** ou **necessidade de baixa latência** no Brasil.

---

#### 📑 Exportações Oficiais da Calculadora AWS
- [PDF Estimativa N. Virginia](src/entrega_2/aws-n-virginia.pdf)
- [PDF Estimativa São Paulo](src/entrega_2/aws-sao-paulo.pdf)

*(Esses PDFs foram gerados diretamente no **AWS Pricing Calculator**, garantindo a rastreabilidade dos valores apresentados.)*

---

#### 🎥 Vídeos Explicativos
- **Entrega 1 (Machine Learning):** [Link do Vídeo no YouTube](URL_DO_VIDEO_AQUI) *(não listado)*  
- **Entrega 2 (AWS Cloud):** [Link do Vídeo no YouTube](URL_DO_VIDEO_AQUI) *(não listado)*  


## 📁 Estrutura de pastas

Dentre os arquivos e pastas presentes na raiz do projeto, definem-se:

- <b>.github</b>: Nesta pasta ficarão os arquivos de configuração específicos do GitHub que ajudam a gerenciar e automatizar processos no repositório.

- <b>assets</b>: aqui estão os arquivos relacionados a elementos não-estruturados deste repositório, como imagens.

- <b>config</b>: Posicione aqui arquivos de configuração que são usados para definir parâmetros e ajustes do projeto.

- <b>document</b>: aqui estão todos os documentos do projeto que as atividades poderão pedir. Na subpasta "other", adicione documentos complementares e menos importantes.

- <b>scripts</b>: Posicione aqui scripts auxiliares para tarefas específicas do seu projeto. Exemplo: deploy, migrações de banco de dados, backups.

- <b>src</b>: Todo o código fonte criado para o desenvolvimento do projeto ao longo das 7 fases.

- <b>README.md</b>: arquivo que serve como guia e explicação geral sobre o projeto (o mesmo que você está lendo agora).

## 🔧 Como executar o código

*Acrescentar as informações necessárias sobre pré-requisitos (IDEs, serviços, bibliotecas etc.) e instalação básica do projeto, descrevendo eventuais versões utilizadas. Colocar um passo a passo de como o leitor pode baixar o seu código e executá-lo a partir de sua máquina ou seu repositório. Considere a explicação organizada em fase.*


## 🗃 Histórico de lançamentos

* 0.5.0 - XX/XX/2024
    * 
* 0.4.0 - XX/XX/2024
    * 
* 0.3.0 - XX/XX/2024
    * 
* 0.2.0 - XX/XX/2024
    * 
* 0.1.0 - XX/XX/2024
    *

## 📋 Licença

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/agodoi/template">MODELO GIT FIAP</a> por <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://fiap.com.br">Fiap</a> está licenciado sobre <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">Attribution 4.0 International</a>.</p>


