// Learning C++ 
// Challenge 01_03
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::string name;

    std::cout << "Please enter your first name: ";
    std::cin >> name;
    std::cout << "Your name is: " << name << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
