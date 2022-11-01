# include <iostream>
#include <string>
#include <memory>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }

        ~Entity()
        {
            std::cout << "Entity  Kaboom!" << std::endl;
        }

        void printEntity()
        {
            //
        }
};


int main()
{
    // {
    //     // std::unique_ptr<Entity> entity(new Entity());
    //     std::unique_ptr <Entity> entity = std::make_unique <Entity>();
    //     entity->printEntity();
    // }

    {
        std::shared_ptr <Entity> e0;
        
        {
            std::shared_ptr <Entity> sharedEntity = std::make_shared <Entity>(); // this will have a refrence counter

            std:: weak_ptr<Entity> weakEntity = sharedEntity; //if you dont want to take ownerShip
            
            e0 = sharedEntity;
        }
    }
}