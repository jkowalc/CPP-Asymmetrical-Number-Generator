#include <map>
#include <cstdlib>

template <typename T>
T generate_asymmetrical_random_number(const std::map<T, float> probabilities)
{
    std::map<T, float> ranges = probabilities;
    transform_probabilities_to_ranges<T>(ranges);
    float random_float = std::rand();
    for(auto it = probabilities.begin(); it != probabilities.end(); ++it)
    {
        if(random_float <= probabilities.second / 100)
        {
            return probabilities.first;
        }
    }
}

template <typename T>
std::map<T, float>& transform_probabilities_to_ranges(std::map<T, float>& probabilities)
{
    float curr_range;
    for(auto it = probabilities.begin(); it != probabilities.end(); ++it)
    {
        curr_range += it->second;
        probabilities[it->first] = curr_range;
    }
    return probabilities;
}