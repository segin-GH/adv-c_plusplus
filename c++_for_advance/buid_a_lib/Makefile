CC=g++
INCDIRS=-I.
OPT=-O3
CXXFLAGS=$(INCDIRS) $(OPT)

CXXFILES=main.cpp helloWorld.cpp
OBJECTS=main.o helloWorld.o

BINARY= bin

#1 rule

all: $(BINARY)

#2 rule
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^
# g++ -o bin main.o helloWorld.o


# regular expression where % is a wildcard
# 3 rule
%.o:%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $^

#4 rule
clean:
	rm -rf $(BINARY) $(OBJECTS)
