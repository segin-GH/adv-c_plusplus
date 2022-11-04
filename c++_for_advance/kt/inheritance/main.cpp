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