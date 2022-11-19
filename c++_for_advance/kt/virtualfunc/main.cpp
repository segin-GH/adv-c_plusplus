# include<iostream>
#include<string>

class Entity
{
public:
    virtual std::string get_name() {return "Entity";}
};



class Player : public Entity
{
private:
    std::string m_name;

public:
    Player(const std::string &name)
        : m_name(name){};
    std::string get_name() override {return m_name;}
};



int main()
{
    Entity *e = new Entity();
    std::cout << e -> get_name() << std::endl;

    Player *p = new Player("dude");
    std::cout << p -> get_name() << std::endl;

    Entity * ent = p;
    std::cout << ent -> get_name() <<std::endl;
}