#include <map>
#include <cstdlib>
#include <time.h>

template <typename T>
std::map<T, float>& transform_probabilities_to_ranges(std::map<T, float>& probabilities)
{
    float curr_range = 0.0;
    for(auto it = probabilities.begin(); it != probabilities.end(); ++it)
    {
        curr_range += it->second;
        probabilities[it->first] = curr_range;
    }
    return probabilities;
}

template <typename T>
T generate_asymmetrical_random_number(const std::map<T, float> probabilities)
{
    std::map<T, float> ranges = probabilities;
    transform_probabilities_to_ranges<T>(ranges);
    std::srand(time(NULL));
    float random_percent = (rand() % 10000) / 100;
    for(auto it = ranges.begin(); it != ranges.end(); ++it)
    {
        if(random_percent <= it->second)
        {
            return it->first;
        }
    }
    return 0;
}