import socket
import pickle

import pandas as pd


class Cliente():
    """
    Classe Cliente - Calculadora Remota - API Socket
    """
    def __init__(self, server_ip,porta):
        """
        Construtor da Classe Cliente
        param server_ip: ip do servidor
        param  port: Porta do serviço
        """
        self.__server_ip = server_ip
        self.__port = porta
        self.__tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def start(self):
        """
        Método que inicializa a execução do cliente
        """
        endpoint = (self.__server_ip,self.__port)
        try:
            self.__tcp.connect(endpoint)
            print("Conexão Realizada com Sucesso!")
            self.__method()
        except Exception as e:
            print("Erro na Conexão com o Servidor", e.args)

    def plot(self,resp):
        from matplotlib import pyplot as plt
        import numpy as np
        import pandas as pd

        print(f'Detalhes da ação {self._nome_acao} \n \n {pd.DataFrame(resp[1])}', end='\n')

        hist = resp[0]
        print(hist, end='\n')

        print("Valor de Mercado Atual: R$", resp[2])


        plt.figure(figsize=[7.16, 7.16], tight_layout=True)

        plt.suptitle(f'Informações do Ativo {self._nome_acao}')
        plt.title("Últimos 7 Dias")
        preg_o = np.array(pd.DataFrame.from_dict(hist['open'])).astype(float)
        preg_c = np.array(pd.DataFrame.from_dict(hist['close'])).astype(float)
        preg_min = np.array(pd.DataFrame.from_dict(hist['low'])).astype(float)
        preg_max = np.array(pd.DataFrame.from_dict(hist['high'])).astype(float)

        plt.plot(preg_o, label="Abertura" , color='orange')
        plt.plot(preg_c, label="Fechamento" , color='green')
        plt.plot(preg_min, label="Cotação Mínima" , color='red')
        plt.plot(preg_max, label="Cotação Máxima" , color='blue')

        plt.legend()
        plt.legend()
        plt.show()

    def __method(self):
        """
        Método que implementa as requisições do cliente e a IHM
        """
        try:
            msg = ''
            while msg != 'x':
                msg = input("Digite a Ativo que deseja analisar (x para sair): ")
                if msg == '':
                    continue
                elif msg == 'x':
                    break

                self._nome_acao = str(msg)
                self.__tcp.send(bytes(msg,'ascii'))
                resp = self.__tcp.recv(6500)
                dados = pickle.loads(resp)
                self.plot(dados)
            self.__tcp.close()
        except Exception as e:
            print("Erro ao realizar a comunicação com o servidor", e.args)




