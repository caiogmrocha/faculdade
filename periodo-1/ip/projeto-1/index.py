import atexit
from datasource import datasource
from presenter import presenter

def graceful_shutdown():
    datasource.persists()

atexit.register(graceful_shutdown)

presenter.bootstrap()