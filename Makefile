bin/monedas: monedas.cpp
	mkdir -p bin
	g++ -o bin/monedas monedas.cpp

bin/monedas_d: monedas_deduccion.cpp
	mkdir -p bin
	g++ -o bin/monedas_d monedas_deduccion.cpp

bin/monedas_b: monedas_backpointer.cpp
	mkdir -p bin
	g++ -o bin/monedas_b monedas_backpointer.cpp


