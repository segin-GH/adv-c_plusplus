#include <iostream> // <- preprocessor Statement // header files
#include <string>


void printHelloWorld(void)
{
   std::cout << "HelloWorld!" << std::endl; // <- code 
}


void printHelloWorld(std::string name)
{
   std::cout << "HelloWorld " << name << std::endl; // <- code 
}


int main(void) // <-entery point
{
    printHelloWorld();
    printHelloWorld("Luffy");

}
