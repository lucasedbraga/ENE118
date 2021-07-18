from yahooquery import Ticker
import datetime



class AcaoBV():

    def __init__(self,nome_acao):
        self._nome_acao = str(nome_acao)
        self.__acao = Ticker(self._nome_acao)

    def info_7dias(self):
        hoje = datetime.date.today()
        semana_passada = [hoje - datetime.timedelta(days=7) for x in range(7)]
        hist = self.__acao.history(start=semana_passada[-1], end=hoje)
        hist_max = self.__acao.history(period='max')
        det = self.__acao.summary_detail
        cotacao_atual = self.__acao.quotes[self._nome_acao]['ask']

        dados = [hist,det,cotacao_atual]

        return dados



