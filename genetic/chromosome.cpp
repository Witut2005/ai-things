
#include <bits/stdc++.h>

class Chromosome
{
    private:

    public:

    static std::string crossover_make(std::string a, std::string b)
    {
        std::string first(a.begin() + 1, a.end() - 1);
        std::string second(b.begin() + 1, b.end() - 1);

        for(int i = 0; i < 2; i++)
            std::remove(second.begin(), second.end(), *(first.begin() + i));
        
        second.resize(second.size() - 2);

        return *a.begin() + std::string(first.begin(), first.begin() + 2) + second + *(a.end() - 1);
    }

    static void mutation_make(std::string& a)
    {
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(1, a.length() - 2);

        std::swap(a[1], a[uniform_dist(e1)]);
    }

};