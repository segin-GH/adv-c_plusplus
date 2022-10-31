# include <iostream>

namespace ply {
class Player //  "Player" <- this is obj 
{
    public:
        int x, y;   
        int speed;

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