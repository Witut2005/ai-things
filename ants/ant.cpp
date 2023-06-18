
#include <bits/stdc++.h>

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
    uint32_t current_place;

    int get_random_int(int min, int max)
    {
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(min, max);
        return uniform_dist(e1);
    }

    int probability_roulette[10][10];

    public:

    Ant(std::vector<uint32_t> Places, uint32_t** distance_matrix, uint32_t first_place_id) : Places(Places), distance(0), distance_matrix(distance_matrix), current_place(first_place_id)
    {
        this->Places.erase(std::find(this->Places.begin(), this->Places.end(), current_place));
        std::cout << current_place << " -> ";
    }

    void calculate_probabilty(void)
    {
        memset(this->probability_roulette, -1, 100 * sizeof(int));
    }

    void visit_using_pheromones(uint32_t** pheromones)
    {

    }

    void visit_random(void)
    {

        if(!this->Places.size())
            return;
        
        auto PlaceSelected = this->Places.begin() + (get_random_int(0, this->Places.size() - 1));

        std::cout << *PlaceSelected << " -> ";
        
        this->distance = this->distance + this->distance_matrix[this->current_place][*PlaceSelected];
        this->current_place = *PlaceSelected;
        this->Places.erase(PlaceSelected);

        // for(auto a : this->Places)
        //     std::cout << a << " ";
        // std::cout << std::endl;
        // std::cout << this->Places.size() << std::endl;


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