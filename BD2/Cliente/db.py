""""
Objetos do sqlalchemy para realização da conexão e operação do Banco de Dados
"""

from sqlalchemy import create_engine, engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from sqlalchemy.orm.session import Session

DB_CONECTION = 'sqlite:///data\data.db?check_same_thread=False'
engine = create_engine(DB_CONECTION, echo = False)
Base = declarative_base()
Session = sessionmaker(bind=engine)
