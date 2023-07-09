
#include "./case.cpp"
#include "./random.cpp"
#include <unistd.h>

class AiBrain{
    private:

    const std::string RecurrenceEventString;
    std::vector<double> Results;
    uint32_t best;


    template<typename T>
    T sigmoid(T x)
    {
        return (x / (1 + abs(x)));
    }

    public:
    
    AiBrain(std::vector<CancerCase> CancerCases, std::string RecurrenceEventString) : RecurrenceEventString(RecurrenceEventString)
    {

    }

    auto get_results(void)
    {
        return this->Results;
    }

    double train()
    {

    }

    double calculate_cost(std::vector<double> Results)
    {
        double total_cost = 0.0;

        for(auto a : Results)
            total_cost += a;

        return total_cost;
    }

};
