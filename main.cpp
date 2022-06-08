#include "Generator/Generator.h"
#include <iostream>
std::map<int, float>& get_probabilities_from_user(std::map<int, float>& prob)
{
    float sum;
    int num;
    float percent;
    while(sum<100)
    {
        std::cout<< "Enter the number: ";
        std::cin>> num;
        std::cout<< "Enter the probability (in %): ";
        std::cin>> percent;
        if(sum + percent > 100)
        {
            percent = 100 - sum;
        }
        sum += percent;
        prob[num] = percent;
    }
    return prob;
}
int main()
{
    std::map<int, float> prob;
    get_probabilities_from_user(prob);
    std::cout<< "Randomly generated number: " << generate_asymmetrical_random_number(prob) << "\n";
}