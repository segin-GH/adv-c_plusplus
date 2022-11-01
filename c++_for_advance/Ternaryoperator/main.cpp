#include <iostream>
#include <string>

static int S_speed = 10;
static int S_level = 0;

int main ()
{
    if (S_level >= 5) {S_speed = 10 ;} else {S_speed = 5 ;}

    S_speed = S_level > 5 && S_level < 100 ? 10 : 5; 
    S_speed = S_level > 5 ? S_level > 10 ? 15 : 10 : 5;    



    std::string rank = S_level > 10 ? "Master" : "NOOB"; 
    std::cout << S_speed << std::endl;
}