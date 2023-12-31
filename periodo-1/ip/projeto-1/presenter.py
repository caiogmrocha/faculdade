import datetime
from os import system
from textwrap import dedent
from re import match

from datasource import datasource
from helpers import vinput, is_float, is_int, is_str

class Presenter:
    available_view_choices = [1,2,3,4,5,6]

    def bootstrap(self):
        self.home_view()


    def choose_view_handler(self):
        choice = int(input("(7 -> home) > "))

        if choice == 0:
            datasource.persists()
            exit(1)

        choices = {
            1: 'list_view',
            2: 'search_view',
            3: 'details_view',
            4: 'create_view',
            5: 'update_view',
            6: 'delete_view',
            7: 'home_view',
        }

        if choice not in choices.keys():
            print('Opção indisponível')
        else:
            getattr(self, choices[choice])()
        
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
        2 - Filtrar produtos cadastrados
        3 - Detalhes de um produto cadastrado
        4 - Cadastrar um novo produto
        5 - Editar um produto existente
        6 - Excluir um produto existente
        7 - Ir para a home
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
            for item in items:
                print(f"ID: {item['id']:<6} Nome: {item['name']:<40} Preço: R$ {str(item['price']).replace('.', ','):<15}")
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


    def search_view(self):
        system('clear')

        print(dedent("""
        ###############################
        #                             #
        #    Filtragem de produtos    #
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
            
            if chosen_filter == 1:
                filter_value = int(filter_value)
            elif chosen_filter == 4:
                filter_value = float(filter_value)

            filtered_items = getattr(datasource, filter_choices[chosen_filter])(filter_value)

            if len(filtered_items):
                for item in filtered_items:
                    print(f"ID: {item['id']:<6} Nome: {item['name']:<40} Preço: R$ {str(item['price']).replace('.', ','):<15}")
            else:
                print("\nNão foram encontrados produtos para o filtro informado.\n")

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

        data['name'] = vinput("Nome do Produto: ", validator=lambda v: is_str(v) and len(v) > 0)
        data['description'] = vinput("Descrição do Produto: ", validator=lambda v: is_str(v) and len(v) > 0)
        data['price'] = float(vinput("Preço do Produto: ", validator=lambda v: is_float(v) and float(v) > 0))
        data['expiration_date'] = vinput(f"Data de Validade do Produto (##/##/####): ", validator=lambda v: is_str(v) and len(v) > 0 and match(r"\d{2}/\d{2}/\d{4}", v))

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

        item_id = int(vinput("ID do Produto: "), validator=lambda v: is_int(v) and (0 < int(v) <= 100000))
        data['name'] = vinput("Nome do Produto: ", validator=lambda v: is_str(v) and len(v) > 0)
        data['description'] = vinput("Descrição do Produto: ", validator=lambda v: is_str(v) and len(v) > 0)
        data['price'] = float(vinput("Preço do Produto: "), validator=lambda v: is_float(v) and float(v) > 0)
        data['expiration_date'] = vinput(f"Data de Validade do Produto (##/##/####): ", validator=lambda v: is_str(v) and len(v) > 0 and match(v, r"\d{2}/\d{2}/\d{4}"))

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
        int(vinput("Digite o ID do produto a ser deletado: "), validator=lambda v: is_int(v) and (0 < int(v) <= 100000))

        item_id = int(vinput("Digite o ID do produto a ser deletado: "), validator=lambda v: is_int(v) and (0 < int(v) <= 100000))

        datasource.delete(item_id)

        print("\nProduto deletado com sucesso!")

        self.choose_view_handler()


presenter = Presenter()

