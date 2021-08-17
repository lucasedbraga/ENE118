from modulopersistencia import ModbusPersistencia

tags_addrs = {
    'temperatura': 1000,
    'pressao': 1001,
    'umidade': 1002,
    'consumo': 1003
}

mod = ModbusPersistencia('localhost', 502, tags_addrs)
mod.guardar_dados.start()
mod.acesso_dados_historicos()