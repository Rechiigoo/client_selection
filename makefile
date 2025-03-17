CXX = g++
CPPFLAGS = -I. -std=c++11

all: raffle lista_clientes

raffle: raffle.cpp 
	$(CXX) $< $(CPPFLAGS) -o $@

lista_clientes: lista_clientes.cpp
	$(CXX) $< $(CPPFLAGS) -o $@

clean: 
	rm -f raffle lista_clientes
