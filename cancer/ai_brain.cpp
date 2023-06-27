
#include "./case.cpp"
#include "./random.cpp"
#include <unistd.h>

class AiBrain{
    private:

    const std::string recur_event;
    std::vector<double> results;
    uint32_t best;

    template<typename T>
    T sigmoid(T x)
    {
        return fabs(x / (1 + abs(x)));
    }

    public:

    auto get_results()
    {
        return this->results;
    }

    AiBrain(std::string recur_event) : recur_event(recur_event){}

    bool check_if_all_true()
    {
        // if(!this->results.size())
        //     return false;

        // for(auto a : results)
        // {
        //     if(!a.second)
        //         return false;
        // }
        return true;
    }

    float random_id_factor(int min, int max)
    {
        return randomFloat(min, max);
    }

    float random_value_factor(int min, int max)
    {
        return randomFloat(min, max);
    }

    float cost_function(double result)
    {
        return pow(result - 1.0, 2);
    }

    void train(const std::vector<CancerCase>& vec)
    {
        this->results.clear();
        CaseField::IdFactors.clear();
        CaseField::FieldValues.clear();

        CaseField::IdFactors.insert(std::make_pair("age",  this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("menopause", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("size", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("inv_nodes", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("node_caps", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("deg_malig", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("breast", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("breast_quad", this->random_id_factor(-1,1)));
        CaseField::IdFactors.insert(std::make_pair("irradiat", this->random_id_factor(-1,1)));

        for(auto a : vec)
        {

            CaseField::FieldValues.insert(std::make_pair(a.age.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.menopause.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.size.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.inv_nodes.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.node_caps.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.deg_malig.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.breast.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.breast_quad.value,this->random_value_factor(0,1)));
            CaseField::FieldValues.insert(std::make_pair(a.irradiat.value,this->random_value_factor(0,1)));

            double result = this->sigmoid
                            ((CaseField::FieldValues[a.age.value] * CaseField::IdFactors.at("age")) + 
                            (CaseField::FieldValues[a.menopause.value] * CaseField::IdFactors.at("menopause")) + 
                            (CaseField::FieldValues[a.size.value] * CaseField::IdFactors.at("size")) + 
                            (CaseField::FieldValues[a.inv_nodes.value] * CaseField::IdFactors.at("inv_nodes")) + 
                            (CaseField::FieldValues[a.node_caps.value] * CaseField::IdFactors.at("node_caps")) + 
                            (CaseField::FieldValues[a.deg_malig.value] * CaseField::IdFactors.at("deg_malig")) + 
                            (CaseField::FieldValues[a.breast.value] * CaseField::IdFactors.at("breast")) + 
                            (CaseField::FieldValues[a.breast_quad.value] * CaseField::IdFactors.at("breast_quad")) + 
                            (CaseField::FieldValues[a.irradiat.value] * CaseField::IdFactors.at("irradiat")) - 0.8);

            // std::cout << a.type << std::endl;
            // std::cout << this->cost_function(result) << std::endl;
            // std::cout << result << std::endl;
            // usleep(200);

            if(result > 0.8)
            {
                double state = (double)(a.type == recur_event);
                this->results.push_back(pow(result - state, 2));
            }
            else
            {
                double state = (double)(a.type != recur_event);
                this->results.push_back(pow(result - state, 2));
            }
        }
    }

};