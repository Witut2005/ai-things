
#include <bits/stdc++.h>
#include "./ant.cpp"

#define ITEMS_COUNT 6

template<typename T, int COLS, int ROWS>
T** convert_arr_to_ptr(T array[COLS][ROWS]) 
{
    T** ptr = new T*[ROWS];
    for (int i = 0; i < ROWS; ++i) 
    {
        ptr[i] = new T[COLS];
        for (int j = 0; j < COLS; ++j) 
            ptr[i][j] = array[i][j];
    }
    return ptr;
}


int main(void)
{
    uint32_t distance_between_attractions[ITEMS_COUNT][ITEMS_COUNT] = {
        {0,8,7,4,6,4},
        {8,0,5,7,11,5},
        {7,5,0,9,6,7},
        {4,7,9,0,5,6},
        {6,11,6,5,0,3},
        {4,5,7,6,3,0}
    };

    double pheromones[ITEMS_COUNT][ITEMS_COUNT];

    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        for(int j = 0; j < ITEMS_COUNT; j++)
            pheromones[i][j] = 1;
    }

    // std::vector<std::pair<uint32_t, std::string>> Attractions = 
    // {
    //     {CIRCUS, "circus"},
    //     {BALLON, "ballon"},
    //     {CARS, "cars"},
    //     {CAROUSEL, "carousel"},
    //     {CHAIN_CAROUSEL, "chain_carousel"},
    //     {FERRIS_WHEEL, "ferris_wheel"}
 
    std::vector<uint32_t> Attractions = { CIRCUS, BALLON, CARS, CAROUSEL, CHAIN_CAROUSEL, FERRIS_WHEEL };

    double** ants_pheromones = convert_arr_to_ptr<double, ITEMS_COUNT, ITEMS_COUNT>(pheromones);
    uint32_t** ants_distance = convert_arr_to_ptr<uint32_t, ITEMS_COUNT,ITEMS_COUNT>(distance_between_attractions);

    Ant* ant;

    for(int i = 0; i < 1000; i++)
    {
        ant = new Ant(Attractions, ants_distance, std::pair<double**, std::pair<uint32_t, uint32_t>> (ants_pheromones, {ITEMS_COUNT, ITEMS_COUNT}), CHAIN_CAROUSEL);

        while(!ant->if_all_places_visited())
            ant->visit();

        delete ant;
    }

    ant = new Ant(Attractions, ants_distance, std::pair<double**, std::pair<uint32_t, uint32_t>> (ants_pheromones, {ITEMS_COUNT, ITEMS_COUNT}), CHAIN_CAROUSEL);

    while(!ant->if_all_places_visited())
    {
        ant->visit();
    }

    for(const auto& a : ant->get_visited())
        std::cout << a << " -> ";

    std::cout << std::endl;


    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        delete ants_pheromones[i];
        delete ants_distance[i];
    }

    delete ants_pheromones;
    delete ants_distance;


}

