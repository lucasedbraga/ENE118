import json

dict = [{'name': 'tempForno','description':'Temperatura Forno','unidade':'ºC','address':1000,'type':'input'},
        {'name': 'SetPoint', 'description': 'Temperatura Desejada', 'unidade': 'ºC', 'address': 2000, 'type': 'holding'},
        {'name': 'Status', 'description': 'Estado Atuador', 'address': 1000, 'type': 'coil'}]

json_object = json.dumps(dict)
print(json_object)