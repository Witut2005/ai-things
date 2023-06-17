
#include <bits/stdc++.h>
#include <unistd.h>
#include "./chromosome.cpp"

double calculate_distance(std::pair<double, double> CityA, std::pair<double, double> CityB)
{
    return sqrt(pow(fabs(CityA.first - CityB.first), 2) + pow(fabs(CityA.second - CityB.second), 2));
}

double calculate_distance_all(std::string CitiesOrder, std::unordered_map<char, std::pair<double, double>> Cities)
{
    double distance = 0;

    for(auto it = CitiesOrder.begin(); it != CitiesOrder.end()-1; it++)
        distance = distance + calculate_distance(Cities[*it], Cities[*(it+1)]);
    
    return distance;
}

void new_generation_create(std::vector<std::string>& Population, std::unordered_map<char, std::pair<double, double>> Cities, uint32_t generation_counter, uint32_t crossover_counter, uint32_t mutation_counter)
{
    
    std::vector<std::pair<std::string*, double>> WorstFromPopulation;
    WorstFromPopulation.resize((generation_counter / 10) + 1, {std::make_pair<std::string*>(&Population[0], 0)});

    std::vector<std::pair<std::string*, double>> BestFromPopulation;
    BestFromPopulation.resize((generation_counter / 10) + 1, {std::make_pair<std::string*>(&Population[0], std::numeric_limits<double>::max())});

    for(auto& a : Population)
    {
        for(auto& b : WorstFromPopulation)
        {
            if(calculate_distance_all(a, Cities) > b.second)
                b = std::make_pair(&a, calculate_distance_all(a, Cities));
        }

        for(auto& b : BestFromPopulation)
        {
            if(calculate_distance_all(a, Cities) < b.second)
                b = std::make_pair(&a, calculate_distance_all(a, Cities));
        }
    }

    for(size_t i = 0; i < WorstFromPopulation.size() - 1; i += 2)
        *WorstFromPopulation[i].first =  Chromosome::crossover_make(*BestFromPopulation[i].first, *BestFromPopulation[i + 1].first);
    
    *(WorstFromPopulation.end() - 1)->first = Chromosome::crossover_make(*BestFromPopulation.begin()->first, *(BestFromPopulation.end() - 1)->first);
    
    for(uint32_t i = 0; i < (generation_counter / 20) + 1; i++)
    {
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(0, Population.size() - 1);

        Chromosome::mutation_make(Population[uniform_dist(e1)]);
    }


}

int main(void)
{
    std::unordered_map<char, std::pair<double, double>> Cities = {
        {'a', {133, 237}},
        {'b', {329, 397}},
        {'c', {221, 223}},
        {'d', {426, 283}},
        {'e', {153, 95}},
        {'f', {307, 224}},
        {'g', {400, 400}},
        {'h', {200, 200}},
        {'i', {1000, 400}},
        {'j', {400, 1000}},
        {'k', {100, 100}},
        {'l', {0, 0}},
        {'m', {500, 500}},
        {'n', {15, 15}},
        {'x', {675, 200}},
        {'y', {700, 400}},
        {'z', {475, 75}},
    };

    uint32_t generation_coutner = 100;
    uint32_t crossover_counter = 2;
    uint32_t mutation_counter = 2;

    std::vector<std::string> Population;
    Population.resize(generation_coutner, "adhijkglmnecfdba");

    double best_distance = std::numeric_limits<double>::max();

    while(1)
    {
        for(auto a : Population)
        {
            if(best_distance > calculate_distance_all(a, Cities))
            {
                best_distance = calculate_distance_all(a, Cities);
                std::cout << "best: " << best_distance << std::endl;
            }
        }

        new_generation_create(Population, Cities, generation_coutner, crossover_counter, mutation_counter);

        // for(auto a : Population)
        //     std::cout << a << " ";
        // std::cout << std::endl;

    }

}