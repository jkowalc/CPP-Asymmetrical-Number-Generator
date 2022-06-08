#include "Generator/Generator.h"
#include <iostream>

int main()
{
    std::map<int, float> prob = {{1, 25.0}, {2, 25.0}, {3, 50.0}};
    std::cout<<generate_asymmetrical_random_number(prob)<<"\n";
}