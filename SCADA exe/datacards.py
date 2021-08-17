from kivymd.uix.card import MDCard

class DataCard(MDCard):
    title = 'Data Card'

    def __init__(self, tag, modbusClient, **kwargs):
        self.tag = tag
        self.title = self.tag['description']
        self._modbusClient = modbusClient
        super().__init__(**kwargs)

    def update_data(self,dt):
        try:
            if self._modbusClient.is_open():
                self.set_data(self._read_data(self.tag['address'], 1)[0])

        except Exception as e:
            nome = self.tag['name']
            tipo = self.tag['type']
            print(f'Erro ao realizar leitura do dado {nome,tipo} : {e.args}')

    def write_data(self):
        try:
            if self._modbusClient.is_open():
                self._write_data_fcn(self.tag['address'],self.get_data())
        except Exception as e:
            print(f'Erro ao realizar escrita do dado: {e.args}')



class CardHoldingRegister(DataCard):
    def __init__(self, tag, modbusClient, **kwargs):
        super().__init__(tag, modbusClient, **kwargs)
        self._read_data = self._modbusClient.read_holding_registers
        self._write_data_fcn = self._modbusClient.write_single_register

    def set_data(self,data):
        self.ids.textfield.text = str(data)
    def get_data(self):
        return int(self.ids.textfield.text)

class CardInputRegister(DataCard):
    def __init__(self, tag, modbusClient, **kwargs):
        super().__init__(tag,modbusClient,**kwargs)
        self._read_data = self._modbusClient.read_input_registers

    def set_data(self,data):
        self.ids.label.text = str(data)


class CardCoil(DataCard):
    def __init__(self, tag, modbusClient, **kwargs):
        super().__init__(tag, modbusClient, **kwargs)
        self._read_data = self._modbusClient.read_coils
        self._write_data_fcn = self._modbusClient.write_single_coil
    def set_data(self,data):
        self.ids.switch.text = str(data)
    def get_data(self):
        return self.ids.switch.active

