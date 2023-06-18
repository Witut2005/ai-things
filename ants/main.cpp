
#include <bits/stdc++.h>
#include "./ant.cpp"

#define ITEMS_COUNT 6

template<int COLS, int ROWS>
uint32_t** convert_arr_to_ptr(uint32_t array[COLS][ROWS]) 
{
    uint32_t** ptr = new uint32_t*[ROWS];
    for (int i = 0; i < ROWS; ++i) 
    {
        ptr[i] = new uint32_t[COLS];
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

    // std::vector<std::pair<uint32_t, std::string>> Attractions = 
    // {
    //     {CIRCUS, "circus"},
    //     {BALLON, "ballon"},
    //     {CARS, "cars"},
    //     {CAROUSEL, "carousel"},
    //     {CHAIN_CAROUSEL, "chain_carousel"},
    //     {FERRIS_WHEEL, "ferris_wheel"}
 
    std::vector<uint32_t> Attractions = { CIRCUS, BALLON, CARS, CAROUSEL, CHAIN_CAROUSEL, FERRIS_WHEEL };

    Ant* ant = new Ant(Attractions, convert_arr_to_ptr<6,6>(distance_between_attractions), 0);

    while(!ant->if_all_places_visited())
    {
        ant->visit_random();
    }
    std::cout << std::endl;
    std::cout << ant->get_distance() << std::endl;

}

