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