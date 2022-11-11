

CC=g++
#declaring a var
INCDIRS=-I.
#includin var
OPT=-o0
#compiler optmization
CXXFLAGS=$(INCDIRS) $(OPT)
#c++ flags
R_OPT=-o3
#release opt
R_CXXFLAGS=$(INCDIRS) $(R_OPT)
# .cpp files
CXXFILES=main.cpp helloWorld.cpp
# .o files
OBJECTS=main.o helloWorld.o

# output file name eg: "a.out" 
BINARY= bin
# release output file name eg: "a.out" 
R_BINARY= r_bin

# 1 rule debug
all: $(BINARY)

# 2 rule
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^
# looks something like this (g++ -o bin main.o helloWorld.o)


# regular expression where % is a wildcard
# 3 rule
%.o:%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $^

# 4 rule
release:$(R_BINARY)

# 5 rule
$(R_BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# 6 rule
%.o:%.cpp
	$(CC) $(R_CXXFLAGS) -c -o $@ $^

# 7 rule
clean:
	rm -rf $(BINARY) $(OBJECTS)

# 8 rule
r_clean:
	rm -rf $(R_BINARY) $(R_OBJECTS)
