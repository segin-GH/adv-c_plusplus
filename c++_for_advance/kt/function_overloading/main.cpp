#include <iostream> // <- preprocessor Statement // header files
#include <string>

using std::cout;

void printHello(void)
{
   cout << "HelloWorld!" << std::endl; // <- code 
}


void printHello(std::string name)
{
   std::cout << "Hello " << name << std::endl; // <- code 
}


int main(void) // <-entery point
{
    printHello();
    printHello("Luffy");

}
