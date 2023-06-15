
#include <unistd.h>
#include <bits/stdc++.h>

bool check_if_has_edges(std::unordered_map<char, std::vector<std::pair<char, uint32_t>>> Nodes, char node)
{
    return Nodes[node].size() > 0;
}

int main(void)
{

    std::unordered_map<char, std::vector<std::pair<char, uint32_t>>> Nodes = 
    {
        {'a', {{'b', 4}, {'c', 2}}},
        {'b', {{'c', 3}, {'d', 2}, {'e', 3}}},
        {'c', {{'b', 1}, {'d', 4}, {'c', 5}}},
        {'d', {}},
        {'e', {{'d', 1}}}
    };

    char start_node = 'a', current_node = 'a', destination_node = 'e';
    std::vector<char> VisitedNodes; 

    std::unordered_map<char, uint32_t> Distances;

    for(auto a : Nodes)
        Distances.insert(std::make_pair(a.first, std::numeric_limits<uint32_t>::max()));
    
    Distances[current_node] = 0;
    
    while(current_node != destination_node)
    {
        std::pair<char, uint32_t> NextNode = {'\0', 0xFFFFFFFF};

        for(auto a : Nodes[current_node])
        {

            bool already_visited = false;;

            for(auto b : VisitedNodes)
            {
                if(a.first == b)
                    already_visited = true;
            }

            if(already_visited)
                continue;

            if(Distances[a.first] < Distances[current_node] + a.second)
                Distances[a.first] = Distances[current_node] + a.second;

            if(a.first == destination_node)
            {
                NextNode.first = a.first;
                NextNode.second = a.second;
                break;
            }

            else if((a.second <= NextNode.second) && (check_if_has_edges(Nodes, a.first)))
            {
                NextNode.first = a.first;
                NextNode.second = a.second;
            }
        }

        for(auto a : Distances)
            std::cout << a.second << " ";
        std::cout << std::endl;

        current_node = NextNode.first;
        VisitedNodes.push_back(current_node);

        std::cout << "next node: " << NextNode.first << std::endl;
        sleep(1);
        
    }

    for(auto a : Distances)
        std::cout << a.first << ": " << a.second << std::endl;
    std::cout << std::endl;
    
}