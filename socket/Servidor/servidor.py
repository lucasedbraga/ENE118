import socket
import threading

class Servidor():
    """
    Classe Servidor - Calculadora Remota - API Socket
    """
    def __init__(self,host,porta):
        """
        Construtor da Classe Servidor
        """
        self._host = host
        self._port = porta
        self._tcp = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    def start(self):
        """
        Inicia a execução do serviço
        """
        endpoint = (self._host,self._port)
        try:
            self._tcp.bind(endpoint)
            self._tcp.listen(1)
            print("Servidor Iniciado em",self._host,":",self._port)
            while True:
                con, cliente = self._tcp.accept()
                self._service(con,cliente)
        except Exception as e:
            print("Erro ao inicializar o Servidor", e.args)
    
    def _service(self,con,client):
        """
        Método que implementa o serviço de calculadora remota
        : param con: objeto socket utilizado para enviar e receber os dados
        : param client: é o endereço e porta do cliente
        """
        print('Atendendo Cliente', client)
        operadores =['+','-','*','/']
        while True:
            try:
                msg = con.recv(1024)
                msg_s = str(msg.decode('ascii'))
                op = 'none'
                for x in operadores:
                    if msg_s.find(x) > 0:
                        op = x
                        msg_s = msg_s.split(op)
                        break
                if op=="+":
                    resp = float(msg_s[0]) + float(msg_s[1])
                elif op=="-":
                    resp = float(msg_s[0]) - float(msg_s[1])
                elif op=="*":
                    resp = float(msg_s[0]) * float(msg_s[1])
                elif op=="/":
                    resp = float(msg_s[0]) / float(msg_s[1])
                else:
                    resp = "Operação Inválida"
                con.send(bytes(str(resp),'ascii'))
                print(f'{client} -> Requisição atendida')
            except OSError as e:
                print(f"Erro na Conexão{client} : {e.args}")
                return
            except Exception as e:
                print(f'Erro nos dados recebidos do cliente {client} : {e.args}')
                con.send(bytes("Erro",'ascii'))


class ServidorMT(Servidor):
    """
    Classe ServidorMT - Calculadora Remota - Multithreading
    """
    def __init__(self,host,port):
        """
        Construtor da Classe Servidor MT
        """
        super().__init__(host, port)
        self.__threadpool  = {}

    def start(self):
        """
        Inicia a execução do serviço
        """
        endpoint = (self._host,self._port)
        try:
            self._tcp.bind(endpoint)
            self._tcp.listen(1)
            print("Servidor Iniciado em",self._host,":",self._port)
            while True:
                con, cliente = self._tcp.accept()
                self.__threadpool[cliente] = threading.Thread(target=self._service, args=(con,cliente))
                self.__threadpool[cliente].start()
        except Exception as e:
            print("Erro ao inicializar o Servidor", e.args)