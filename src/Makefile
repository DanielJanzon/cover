
OBJECTS := main.o ast.o tokenizer.o grammar.o
CC := gcc
CXX := g++

CXX_FLAGS := -g -O0 -Wall
CC_FLAGS := -g -O0 -std=gnu99 -Wall

all: $(OBJECTS)
	$(CXX) -o cover $(OBJECTS)

main.o: main.cc grammar-generated.c
	$(CC) $(CXX_FLAGS) -c -o $@ $<

ast.o: ast.cc ast.h
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

grammar.o: grammar-generated.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

tokenizer.o: tokenizer-generated.c grammar-generated.c
	$(CC) $(CC_FLAGS) -c -o tokenizer.o $<

grammar-generated.c: grammar.y
	bison -d -o grammar-generated.c grammar.y

tokenizer-generated.c: tokenizer.l
	flex -o tokenizer-generated.c tokenizer.l

clean:
	rm -f cover tokenizer-generated.c grammar-generated.[hc] *.output *.a *.o

