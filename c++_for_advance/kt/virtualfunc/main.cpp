#include <iostream>
#include <string>
class Entity
{
public:
     virtual std::string get_name(){return "Entity";};

};

class Player : public Entity
{
private:
    std::string m_name;

public:
    Player(const std::string &name )
        : m_name(name){};

    std::string get_name() override {return m_name;}

};


void PrintName(Entity *ent)
{
    std::cout << ent -> get_name() <<std::endl;
}

int main(void)
{
    Entity *e = new Entity();
    // std::cout << e -> get_name() << std::endl;
    PrintName(e);

    Player *p = new Player("dude");
    // std::cout << p -> get_name() << std::endl;
    PrintName(p);

    Entity *entity = p;
    // std::cout << entity->get_name() << std::endl;
    PrintName(p);
}