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
    forEach(values, [](int value){std::cout << "Values" << std::endl; });

}

