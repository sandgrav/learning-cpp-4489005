// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

int main(){
    int nums[5] = {1,23,32,24,337};
    int sum = 0;
    float result; 

    // Write your code here
    for (int i : nums){
        sum += i;
    }
    
    result = (float)sum / 5;

    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
