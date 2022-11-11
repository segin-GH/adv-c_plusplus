CC=g++
INCDIRS=-I.
OPT=-O0
CFLAGS=-g $(INCDIRS) $(OPT)

CFILES=main.cpp helloWorld.cpp
OBJECTS=main.o helloWorld.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# regular expression where % is a wildcard
%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)