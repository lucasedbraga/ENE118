from pyModbusTCP.client import ModbusClient
from dbhandler import DBHandler
from sqlite3.dbapi2 import enable_callback_tracebacks
from datetime import datetime
from time import sleep
from tabulate import tabulate
from threading import Thread

class ModbusPersistencia():
    '''
    Classe que implementa a funcionalidade de persistência de dados lidos a partir do protocolo
    MODBUS e também permite a busca de dados históricos
    '''

    def __init__(self,server_ip,server_port,tags_addrs,scan_time=1):
        """
        Construtor
        :param server_ip:
        :param server_port:
        :param tags_addrs:
        :param scan_time:
        """
        self._cliente_modbus = ModbusClient(host = server_ip,port = server_port)
        self._scan_time = scan_time
        self._tags_addrs = tags_addrs
        self._dbhandler = DBHandler('data/data.db',self._tags_addrs.keys(),tablename='modbusData')
        self.guardar_dados = Thread(target=self.guardar_dados)

    def guardar_dados(self):
        """
        Método para a leitura dos dados do servidor e armazenamento no BD
        """
        try:
            print('Persistência iniciada')
            self._cliente_modbus.open()
            data = {}
            while True:
                data['timestamp'] = datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')
                for tag in self._tags_addrs:
                    data[tag] = self._cliente_modbus.read_holding_registers(self._tags_addrs[tag],1)[0]
                self._dbhandler.insert_data(data)
                sleep(self._scan_time)

        except Exception as e:
            print('Erro na busca de dados da tabela: ', e.args)


    def acesso_dados_historicos(self):
        """
        Método que permite ao usuário acessar dados históricos
        """
        try:
            print('Bem vindo ao sistema de busca de dados historicos')
            while True:
                init = input('Digite o horário inicial para a busca (DD/MM/AAAA HH:MM:SS) :')
                final = input('Digite o horário final para a busca (DD/MM/AAAA HH:MM:SS) :')
                init = datetime.strptime(init,'%d/%m/%Y %H:%M:%S').strftime('%Y-%m-%d %H:%M:%S')
                final = datetime.strptime(final, '%d/%m/%Y %H:%M:%S').strftime('%Y-%m-%d %H:%M:%S')
                result = self._dbhandler.select_data(self._tags_addrs.keys(),init,final)
                print(tabulate(result['data'],headers=result['cols']))

        except Exception as e:
            print('Erro na busca de dados : ', e.args)