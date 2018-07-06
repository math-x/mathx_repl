CC = g++
DEPS = bin/evaluate.o bin/function_map.o bin/parser.o bin/tools.o bin/variable_map.o bin/assignment.o bin/error.o bin/main.o

all:
	mkdir bin
	$(CC) -c src/evaluate.cpp -o bin/evaluate.o
	$(CC) -c src/function_map.cpp -o bin/function_map.o
	$(CC) -c src/parser.cpp -o bin/parser.o
	$(CC) -c src/tools.cpp -o bin/tools.o
	$(CC) -c src/variable_map.cpp -o bin/variable_map.o
	$(CC) -c src/assignment.cpp -o bin/assignment.o
	$(CC) -c src/error.cpp -o bin/error.o
	$(CC) -c src/main.cpp -o bin/main.o
	$(CC) $(DEPS) -o repl
	rm -rf bin
