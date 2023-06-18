
#include <bits/stdc++.h>

#define PHEROMONES_FACTOR 1
#define HEURISTICS_FACTOR 2

enum ATTRACTIONS
{
    CIRCUS = 0,
    BALLON = 1,
    CARS = 2,
    CAROUSEL = 3,
    CHAIN_CAROUSEL = 4,
    FERRIS_WHEEL = 5
};

class Ant
{

    private:
    std::vector<uint32_t> Places;
    uint32_t distance;
    uint32_t** distance_matrix;
    std::pair<double**, std::pair<uint32_t, uint32_t>> pheromones;
    uint32_t current_place;
    uint32_t next_place;
    std::vector<uint32_t> PlacesVisited;

    int get_random_int(int min, int max)
    {
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(min, max);
        return uniform_dist(e1);
    }

    int* probability_roulette;

    public:

    Ant(std::vector<uint32_t> Places, uint32_t** distance_matrix, std::pair<double**, std::pair<uint32_t, uint32_t>> pheromones, uint32_t first_place_id) : Places(Places), distance(0), distance_matrix(distance_matrix), pheromones(pheromones), current_place(first_place_id)
    {
        this->Places.erase(std::find(this->Places.begin(), this->Places.end(), current_place));
        this->PlacesVisited.push_back(this->current_place);
        this->probability_roulette = new int[100];
        // std::cout << this->current_place << " -> ";
    }

    ~Ant()
    {
        delete []this->probability_roulette;
    }

    void calculate_probability(void)
    {
        memset(this->probability_roulette, -1, 100 * sizeof(int));

        std::vector<std::pair<uint32_t, double>> Values;
        double all_probabilities = 0;

        for(const auto& a : this->Places)
        {
            double probability = pow(pheromones.first[this->current_place][a], PHEROMONES_FACTOR) * pow(1 / (double)distance_matrix[this->current_place][a], HEURISTICS_FACTOR) * 10;
            all_probabilities += probability;
            Values.push_back(std::make_pair(a, probability));
        }

        uint32_t index = 0;
        for(auto it = Values.begin(); it != Values.end(); it++)
        {

            uint32_t start_index = index;
            uint32_t end_index = start_index + round(it->second / all_probabilities * 100);

            if(it == std::prev(Values.end(), 1))
                end_index = 100;

            for(; index < end_index; index++)
                this->probability_roulette[index] = it->first;
        }

    }

    void visit_using_pheromones()
    {

    }

    void print_probabilities(void)
    {
        for(int i = 0; i < 10; i++) 
        {
            for(int j = 0; j < 10; j++) 
                std::cout << this->probability_roulette[i * 10 + j] << " ";
            std::cout << std::endl;
        }
    }

    void print_pheromones(void)
    {
        for(uint32_t i = 0; i < pheromones.second.first; i++) 
        {
            for(uint32_t j = 0; j < pheromones.second.second; j++) 
                std::cout << this->pheromones.first[i][j] << " ";
            std::cout << std::endl;
        }
    }

    void visit_random(void)
    {

        if(!this->Places.size())
            return;
        
        auto PlaceSelected = this->Places.begin() + (get_random_int(0, this->Places.size() - 1));

        // std::cout << *PlaceSelected << " -> ";
        
        this->distance = this->distance + this->distance_matrix[this->current_place][*PlaceSelected];
        this->current_place = *PlaceSelected;
        this->Places.erase(PlaceSelected);

        // for(auto a : this->Places)
        //     std::cout << a << " ";
        // std::cout << std::endl;
        // std::cout << this->Places.size() << std::endl;
    }

    void visit(void)
    {

        if(!this->Places.size())
            return;

        this->calculate_probability();
        // this->print_probabilities();
        // std::cout << "----------------------------------------------------------------" << std::endl;

        auto PlaceSelected = std::find(this->Places.begin(), this->Places.end(), this->probability_roulette[this->get_random_int(0, 100)]);
        
        if(PlaceSelected == this->Places.end())
            return;

        // if(this->Places.size() > 1)
        //     std::cout << *PlaceSelected << " -> ";
        // else
        //     std::cout << *PlaceSelected << std::endl;

        this->PlacesVisited.push_back(*PlaceSelected);
        
        this->distance = this->distance + this->distance_matrix[this->current_place][*PlaceSelected];
        this->current_place = *PlaceSelected;
        this->Places.erase(PlaceSelected);

        if(!this->Places.size())
        {
            for(auto it = this->PlacesVisited.begin(); it != this->PlacesVisited.end() - 1; it++)
                this->pheromones.first[*it][*(it+1)] += (double)100 / (double)this->distance;
        }

    }

    auto get_visited(void)
    {
        return this->PlacesVisited;
    }

    bool if_all_places_visited(void)
    {
        return this->Places.size() == 0;
    }

    uint32_t get_distance(void)
    {
        return this->distance;
    }

};