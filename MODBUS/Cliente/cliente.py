from pyModbusTCP.client import ModbusClient
from time import sleep

class ClienteMODBUS():
    """
    Classe Cliente MODBUS
    """
    def __init__(self, server_ip,porta, scan_time=1):
        """
        Construtor da Classe Cliente
        param server_ip: ip do servidor
        param  port: Porta do serviço
        """
        self._cliente = ModbusClient(host=server_ip,port=porta)
        self._scan_time = scan_time

    def atendimento(self):
        """
        Método de Atendimento do Usuario
        """
        self._cliente.open()

        try:
            atendimento = True
            while atendimento:
                sel = input('Deseja realizar uma leitura, escrita ou configuração? (1-Leitura, 2-Escrita e 3-Configuração')

                if sel == 1:
                    tipo = input('Qual é o tipo de dado? (1-Holding Register, 2-Coil, 3-Input Register, 4- Entrada Discreta')
                    addr = input('Digite o Endereço da Tabela MODBUS')
                    nvezes = input('Digite o numero de vezes q deseja ler')

                    for i in range(0,int(nvezes)):
                        print(f'Leitura {i+1}: {self.lerDado(int(tipo),int(addr))}')
                        sleep(self._scan_time)
                if sel == 2:
                    tipo = input('Qual tipo de dado deseja escrever? (1-Holding, 2-Coil)')
                    addr = input('Endereço da tabela')
                    valor = input('Digite o valor')
                    self.escreveDado(int(tipo),int(addr),int(valor))

                if sel ==3:
                    scant = input('Digite o scantime em seguntos')
                    self._scan_time = float(scant)

                if sel ==4:
                    atendimento = False
                    self._cliente.close()
                    break
        except Exception as e:
            print('Erro', e.args)


    def lerDado(self,tipo,addr):
        """
        Método para leitura de um dado da Tabela MODBUS
        """
        if tipo ==1:
            return self._cliente.read_holding_registers(addr,1)[0]

        if tipo == 2:
            return self._cliente.read_coils(addr, 1)[0]

        if tipo ==3:
            return self._cliente.read_input_registers(addr,1)[0]

        if tipo == 4:
            return self._cliente.read_discrete_inputs(addr, 1)[0]

    def escreveDado(self, tipo, addr,valor):
        """
        Método para escrita de dado da Tabela MODBUS
        """
        if tipo == 1:
            return self._cliente.write_single_register(addr, valor)

        if tipo == 2:
            return self._cliente.write_single_coil(addr, valor)



