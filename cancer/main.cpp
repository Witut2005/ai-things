
#include <bits/stdc++.h>
#include "./ai_brain.cpp"

// namespace fs = std::filesystem;

std::vector<std::string> split(std::string str, char delimiter)
{
    uint32_t start = 0;
    std::vector<std::string> vec;
    decltype(str.find(delimiter, start)) end;

    while((end = str.find(delimiter, start)) != std::string::npos)
    {
        vec.push_back(str.substr(start, end - start));
        start = end + sizeof(char);
    }

    auto tmp = str.substr(start);
    if(tmp.length())
        vec.push_back(tmp);

    return vec;

}

std::ostream& operator<<(std::ostream& os, std::vector<std::pair<uint32_t, bool>> vec)
{
    for(auto a : vec)
        std::cout << a.second << " ";

    return os;
}

std::vector<CancerCase> file_data_get(const char* path)
{
    std::ifstream Stream(path);
    std::string Line, LineField;
    std::vector<CancerCase> vec;

    if(!Stream.good())
        return vec;

    while(getline(Stream, Line))
    {
        auto tmp = split(Line, ',');
        vec.push_back(CancerCase(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7], tmp[8], tmp[9]));
    }

    Stream.close();

    return vec;
}

int main(void)
{

    std::vector<CancerCase> CancerData = file_data_get("./data/breast+cancer/breast-cancer.data");

    if(!CancerData.size())
    {
        std::cout << "no data found" << std::endl;
        return 1;
    }

    AiBrain Brain("recurrence-events");

    uint32_t test_id = 0;
    double best = 10000;

    // while(!Brain.check_if_all_true())
    while(1)
    {

        Brain.train(CancerData);

        double total_cost = 0.0;
        auto results = Brain.get_results();//.size() > best)

        for(auto a : results)
            total_cost = total_cost + a;
        
        // std::cout << total_cost << std::endl;

        if(total_cost < best)
        {
            std::cout << total_cost << std::endl;
            std::cout << "--------------------------------" << std::endl;
            best = total_cost;
        }

    }

    // for(auto a : CaseField::IdFactors)
    // {
    //     std::cout << a.first << " " << a.second << std::endl;
    // }

    // std::cout << "--------------------------------------------" << std::endl;

    // for(auto a : CaseField::FieldValues)
    // {
    //     std::cout << a.first << " " << a.second << std::endl;
    // }

}