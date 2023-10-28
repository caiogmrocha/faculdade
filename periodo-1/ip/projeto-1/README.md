# Sobre o projeto

O projeto se trata de uma aplicação CLI de controle de estoque de produtos que permite ao usuário realizar as seguintes ações:

1 - Listar produtos cadastrados
2 - Filtrar produtos cadastrados
3 - Detalhes de um produto cadastrado
4 - Cadastrar um novo produto
5 - Editar um produto existente
6 - Excluir um produto existente
7 - Ir para a home

# Como iniciar

Para iniciar a aplicação é necessário estar com a versão 3.10.6 do Python e executar o comando `python3 index.py` na raiz do projeto.

# Tarefas

## 1. Implementar acesso à base de dados (DataSource)

- [x] DataSource.persists
- [x] DataSource.load
- [x] DataSource.get_all
- [x] DataSource.get_by_name
- [x] DataSource.get_by_description
- [x] DataSource.get_by_price
- [x] DataSource.get_by_expiration_date
- [x] DataSource.create
- [x] DataSource.update
- [x] DataSource.delete

## 2. Implementar apresentação da inteface CLI (Presenter)

- [x] Presenter.home_view
- [x] Presenter.list_view
- [x] Presenter.search_view
- [x] Presenter.details_view
- [x] Presenter.create_view
- [x] Presenter.update_view
- [x] Presenter.delete_view
- [x] Validações
    - [x] Presenter.create_view
    - [x] Presenter.update_view
    - [x] Presenter.delete_view