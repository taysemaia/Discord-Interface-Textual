.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/sistema.o build/executor.o build/usuario.o build/canaltexto.o build/servidor.o build/mensagem.o

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

build/usuario.o: src/usuario.cpp include/usuario.h 
	g++ -Iinclude src/usuario.cpp -c -o build/usuario.o

build/canaltexto.o: src/canaltexto.cpp include/canaltexto.h 
	g++ -Iinclude src/canaltexto.cpp -c -o build/canaltexto.o

build/servidor.o: src/servidor.cpp include/servidor.h 
	g++ -Iinclude src/servidor.cpp -c -o build/servidor.o
build/mensagem.o: src/mensagem.cpp include/mensagem.h 
	g++ -Iinclude src/mensagem.cpp -c -o build/mensagem.o
#para adicionar novas regras apenas siga o formato
#build/usuario.o: src/usuario.cpp include/usuario.h
#	g++ -Iinclude src/usuario.cpp -c

objects: $(OBJECTS)

concordo: objects src/concordo.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/concordo.cpp -o build/concordo

clean:
	rm build/*.o build/concordo

all: concordo

run:
	./build/concordo
