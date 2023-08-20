import atexit
import datetime
from os import system
from textwrap import dedent

from datasource import datasource

class Presenter:
    available_view_choices = [1,2,3,4,5,6]

    def bootstrap(self):
        self.home_view()


    def choose_view_handler(self):
        choice = int(input("(6 -> home) > "))

        if choice == 0:
            datasource.persists()
            exit(1)

        choices = {
            1: 'list_view',
            2: 'details_view',
            3: 'create_view',
            4: 'update_view',
            5: 'delete_view',
            6: 'home_view',
        }

        if choice not in choices.keys():
            print('Opção indisponível')
        else:
            print("choices[choice]: ", choices[choice], choice)
            try:
                getattr(self, choices[choice])()
            except:
                print("view not implemented")
        
        self.choose_view_handler()


    def home_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #        Seja Bem-vindo       #
        #                             #
        #      Gestão de Produtos     #
        #                             #
        ###############################
        #                             #
        #     Selecione uma opção     #
        #                             #
        ###############################

        1 - Listar produtos cadastrados
        2 - Detalhes de um produto cadastrado
        3 - Cadastrar um novo produto
        4 - Editar um produto existente
        5 - Excluir um produto existente
        6 - Ir para a home
        """))

        self.choose_view_handler()


    def list_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Lista de Produtos         #
        #                             #
        ###############################
        """))

        items = datasource.get_all()

        if len(items):
            for item in datasource.get_all():
                print(f"ID: {item['id']}, Nome: {item['name']}, Preço: R$ {str(item['price']).replace('.', ',')}")
        else:
            print("Estoque vazio\n")

        self.choose_view_handler()


    def details_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Detalhes de um Produto    #
        #                             #
        #   Digite o ID do produto a  #
        #        ser visualizado      #
        ###############################

        """))

        item_id = int(input("Digite o ID do item: "))

        filtered_items = datasource.get_by_id(item_id)

        if len(filtered_items):
            item = filtered_items[0]

            print(f"\nProduto {item_id} encontrado com sucesso!")

            print(f"\nNome: {item['name']}")
            print(f"Descrição: {item['description']}")
            print(f"Preço: {float(item['price']):.2f}")
            print(f"Data de Validade: {datetime.strfdate(item['expiration_date'], '%d/%m/%Y')}")
        else:
            print("Item inexistente!")

        self.choose_view_handler()


    def details_view_old(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Detalhes de um Produto    #
        #                             #
        # Selecione o filtro desejado #
        #                             #
        ###############################

        1 - ID
        2 - Nome
        3 - Descrição
        4 - Preço
        5 - Data de validade

        """))

        chosen_filter = int(input("Filtrar pela propriedade: "))

        filter_choices = {
            1: "get_by_id",
            2: "get_by_name",
            3: "get_by_description",
            4: "get_by_price",
            5: "get_by_expiration_date",
        }

        if chosen_filter not in filter_choices.keys():
            print('Opção indisponível')
        else:
            filter_value = input("Digite o valor do filtro: ")

            filtered_items = getattr(datasource, filter_choices[chosen_filter])(filter_value)

            # if (len(filtered_items)):
            #     for item in filtered_items:


        self.choose_view_handler()


    def create_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Cadastro de Produto       #
        #                             #
        ###############################

        """))

        data = dict()

        data['name'] = input("Nome do Produto: ")
        data['description'] = input("Descrição do Produto: ")
        data['price'] = float(input("Preço do Produto: "))
        data['expiration_date'] = input(f"Data de Validade do Produto (##/##/####): ")

        datasource.create(data)

        print("\nNovo produto cadastrado com sucesso!")

        self.choose_view_handler()


    def update_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Edição de Produto         #
        #                             #
        ###############################

        """))

        data = dict()

        item_id = int(input("ID do Produto: "))
        data['name'] = input("Nome do Produto: ")
        data['description'] = input("Descrição do Produto: ")
        data['price'] = float(input("Preço do Produto: "))
        data['expiration_date'] = input(f"Data de Validade do Produto (##/##/####): ")

        datasource.update(item_id, data)

        print("\nNovo produto atualizado com sucesso!")

        self.choose_view_handler()


    def delete_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #   Deletar produto           #
        #                             #
        ###############################

        """))

        item_id = int(input("Digite o ID do produto a ser deletado: "))

        datasource.delete(item_id)

        print("\nProduto deletado com sucesso!")

        self.choose_view_handler()


presenter = Presenter()

presenter.bootstrap()

def graceful_shutdown():
    datasource.persists()

atexit.register(graceful_shutdown)