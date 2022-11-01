# include <iostream>


template <typename T >

void __print( T val)
{
    std::cout << val << std::endl;
}

int main()
{
    __print(10);
    __print("Luffy");
    __print(3.15f);
    
}