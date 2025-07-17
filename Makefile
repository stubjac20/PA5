out: clean compile execute

compile: main.cpp InventorySystem.cpp Product.cpp CSVParser.cpp
	g++ -g -Wall -std=c++14 main.cpp InventorySystem.cpp Product.cpp CSVParser.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe

