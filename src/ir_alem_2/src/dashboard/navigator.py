import streamlit as st

from ..dashboard.database.exportar import exportar_db_page
from ..dashboard.database.importar import importar_db_page
from ..dashboard.global_messages import get_global_messages
from ..dashboard.modelo_preditivo.exploracao_de_dados import exploracao_de_dados
from ..dashboard.modelo_preditivo.previsoes import previsao_manual_page
from ..dashboard.principal import get_principal_page
from ..dashboard.generic.table_view import TableView
from packages.database.dynamic_import import import_models
from ..dashboard.menu import menu


def get_generic_pages() -> list:
    """
    Função para importar dinamicamente os módulos e retornar uma lista de páginas genéricas que fazem o CRUD.
    """

    rotas = []

    models = import_models()


    items = list(models.items())
    items.sort(key=lambda x: x[1].display_name())
    for model_name, model in items:
        view = TableView(model)
        rotas.extend(view.get_routes())
    return rotas

def navigation():
    """
    Função para exibir a página principal do aplicativo.
    :return:
    """

    get_global_messages()

    current_page = st.navigation([
        get_principal_page(),
        *get_generic_pages(),
        exportar_db_page,
        importar_db_page,
        exploracao_de_dados,
        previsao_manual_page,
    ])

    menu()

    current_page.run()

