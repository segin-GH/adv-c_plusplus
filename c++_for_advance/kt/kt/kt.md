# KT c++ (not for noobs)*



## HelloWorld in c++

```
#include <iostream> // <- preprocessor Statement // header files
int main(void) // <-entery point
{
   std::cout << "HelloWorld" << std::endl; // <- code 
}
```
 ****Points to talk about****

* namespace (using std namespace, using std::cout)


---

## Function OverLoading
```
#include <iostream> // <- preprocessor Statement // header files
#include <string>

using std::cout;

void printHello(void)
{
   cout << "HelloWorld!" << std::endl; // <- code 
}
void printHello(std::string name)
{
   std::cout << "Hello " << name << std::endl; // <- code 
}

int main(void) // <-entery point
{
    printHello();
    printHello("Luffy");

}
```

## RangeBasedForLoop

```
#include <iostream>
#include <vector>

int main(void)
{
    int arr[] = {1,2,3,4};
    std::vector <int> victor = {1,2,3,4,5,6};

    for(auto i : victor)
        std::cout << i << "\t";
    
    std::cout << std ::endl; 

    return 0;
}
```

## Lambada

```
#include <iostream>
#include <vector>
// #include <algorithm>

void forEach(std::vector <int>& values, void(*func)(int))
{
    for(int va : values)
        func(va);
}


int main (void)
{
    std::vector <int> values = {0,1,2,3,4,5};
    forEach(values, [](int value){std::cout << "Values" << std::endl;});
    forEach(values, [](int value){std::cout << value << std::endl;});
}


```
## RangeBasedForLoop

```
#include <iostream>
#include <vector>

int main(void)
{
    int arr[] = {1,2,3,4};
    std::vector <int> victor = {1,2,3,4,5,6};

    for(auto i : victor)
        std::cout << i << "\t";
    
    std::cout << std ::endl; 

    return 0;
}
```
## Template

```
#include <iostream>

template <typename T >

void __print( T val)
{
    std::cout << val << std::endl;
}

int main()
{
    __print<int>(10);
    __print("Luffy");
    __print(3.15f);
}

```

## Class

```
#include <iostream>

namespace ply {
class Player //  "Player" <- this is obj 
{
    public:
        int m_x, m_y;   
        int m_speed;

    void Move(int xa, int ya) 
    {
        //do some stuff
        x += xa;
        y += ya;
        std::cout << "player moved" << std::endl;

    }
};
};


int main()
{
    ply::Player player; //   <- this is called instance

    player.x = 5;
    player.y = 7;
    player.speed = 1000;

    player.Move(10,10);

}
```

* Public , private
* getter, setter 
* constructor
* deconstructor

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
