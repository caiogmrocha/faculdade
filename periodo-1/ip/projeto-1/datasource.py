import os
from datetime import datetime
from random import randint

class DataSource:
    data = []

    def __init__(self):
        self.load()

    def get_all(self) -> list:
        return self.data


    def get_by_id(self, id) -> list:
        return [item for item in self.get_all() if item['id'] == id]
    

    def get_by_name(self, name) -> list:
        return [item for item in self.get_all() if item['name'] == name]


    def get_by_description(self, description) -> list:
        return [item for item in self.get_all() if item['description'] == description]


    def get_by_price(self, price) -> list:
        return [item for item in self.get_all() if item['price'] == price]


    def get_by_expiration_date(self, expiration_date) -> list:
        return [item for item in self.get_all() if item['expiration_date'] == expiration_date]


    def create(self, data) -> None:
        data['id'] = randint(1, 100000)
        data['expiration_date'] = datetime.strptime(data['expiration_date'], '%d/%m/%Y')

        self.data.append(data)


    def update(self, id, data) -> None:
        updated_list = [item for item in self.get_all() if item['id'] != id]

        print("updated_list: ", updated_list)

        data['id'] = id
        data['expiration_date'] = datetime.strptime(data['expiration_date'], '%d/%m/%Y')

        updated_list.append(data)

        self.data = updated_list

            
    def delete(self, id) -> None:
        self.data = [item for item in self.get_all() if item['id'] != id]


    def persists(self) -> None:
        if os.path.exists('database.csv'):
            os.remove('database.csv')

        file = open('database.csv', 'w', encoding='utf-8')

        formatted_lines = []

        for item in self.data:
            formatted_lines.append(f"{item['id']};{item['name']};{item['description']};{item['price']};{datetime.strftime(item['expiration_date'], '%d/%m/%Y')}\n")
        
        file.writelines(formatted_lines)

        file.close()


    def load(self) -> None:
        file = None

        if os.path.exists('database.csv'):
            file = open('database.csv', 'r', encoding='utf-8')
        else:
            file = open('database.csv', 'w', encoding='utf-8')
            file.close()
            file = open('database.csv', 'r', encoding='utf-8')

        for line in file.readlines():
            id,name,description,price,expiration_date = line.replace('\n', '').split(";")

            self.data.append({
                "id": int(id),
                "name": name,
                "description": description,
                "price": float(price),
                "expiration_date": datetime.strptime(expiration_date, '%d/%m/%Y')
            })


        file.close()

datasource = DataSource()