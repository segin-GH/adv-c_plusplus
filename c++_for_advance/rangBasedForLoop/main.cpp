# include <iostream>
# include <vector>

int main(void)
{
    int arr[] = {1,2,3,4};
    std::vector <int> victor = {1,2,3,4,5,6};

    for(auto i : victor)
        std::cout << i << "\t";
    
    std::cout << std ::endl; 

    return 0;

}

/* 
**Advantages of foreach loop
It eliminates the possibility of errors and makes the code more readable.
Easy to implement
Does not require pre-initialization of the iterator

** Disadvantages of foreach loop
Cannot directly access the corresponding element indices
Cannot traverse the elements in reverse order
It doesn’t allow the user to skip any element as it traverses over each one of them

 */