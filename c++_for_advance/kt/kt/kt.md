# KT c++ (not for noobs)*

# Makefile

## main.c
```
#include "helloWorld.h"

int main ()
{
    SRC::PrintH per;
    per.printHello();
    per.printHello("luffy");
}

```

## helloWorld.h

```
#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H


#include <iostream>
#include <string>

namespace SRC { 

class PrintH 
{

public:
    void printHello();
    void printHello(std::string name);
};

}


#endif
```
## helloworld.h
```
# include "helloWorld.h"


void SRC::PrintH::printHello()
{
    std::cout << "Hello World!" << std::endl;
}

void SRC::PrintH::printHello(std::string name)
{
    std::cout << "Hello " << name << std::endl;
}
```
## makefile
```

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

```

# Inheritance

```
#include <iostream>
// #include <string>

class Entity
{

private:
    int m_posX;
    int m_posY;

public:

    void move(int xa, int xy)
    {
        m_posX += xa;
        m_posY += xy;
    }

    void printPos()
    {
        std::cout << m_posX << "   " << m_posY << std::endl;
    }
    Entity()
    {
        m_posX = 0;
        m_posY = 0;
    }
    Entity(int x, int y)
    {
        m_posX = x;
        m_posY = y;
    }



};

class Player : public Entity
{

private:
    std::string m_name = "Dude";

public:

    void setName(std::string name)
    {
        m_name = name;
    }
};

int main(void)
{
    Entity entity;
    entity.move(10,11);
    entity.printPos();
    
    Player playerOne;
    playerOne.move(21,22);
    playerOne.printPos();


    
}
```
# Virtual Function

```
#include <iostream>
#include <string>
#include <ostream>
class Entity
{
    public:

       virtual std::string GetName() {return "Entity";};
};

class Player : public Entity
{
    private:
        std::string m_Name;

    public:
        Player(const std::string &name)
            : m_Name(name) {}; // <-- member initlizer List
        std::string GetName() override {return m_Name;}
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}


int main()
{
    Entity *e = new Entity();
    // std::cout << e ->GetName() << std::endl;
    PrintName(e);

    Player *p = new Player("luffy");
    // std::cout << p ->GetName() << std::endl;
    PrintName(p);

// if you start refering player as if it was an entity (polymorphism)

    Entity * entity = p;
    // std::cout << entity->GetName() << std::endl;
    PrintName(p);
}

```
