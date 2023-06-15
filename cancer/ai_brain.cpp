
#include "./case.cpp"
#include "./random.cpp"

class AiBrain{
    private:

    const std::string recur_event;
    std::vector<std::pair<uint32_t, bool>> results;
    uint32_t best;

    public:

    auto get_results()
    {
        return this->results;
    }

    AiBrain(std::string recur_event) : recur_event(recur_event){}

    bool check_if_all_true()
    {
        if(!this->results.size())
            return false;

        for(auto a : results)
        {
            if(!a.second)
                return false;
        }
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

    void train(std::vector<CancerCase> vec)
    {
        this->results.clear();
        CaseField::IdFactors.clear();
        CaseField::FieldValues.clear();

        CaseField::IdFactors.insert(std::make_pair(vec[0].age.id, this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].menopause.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].size.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].inv_nodes.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].node_caps.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].deg_malig.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].breast.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].breast_quad.id,this->random_id_factor(1,2)));
        CaseField::IdFactors.insert(std::make_pair(vec[0].irradiat.id,this->random_id_factor(1,2)));

        uint32_t entry_id = 1;
        for(auto a : vec)
        {

            CaseField::FieldValues.insert(std::make_pair(a.age.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.menopause.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.size.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.inv_nodes.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.node_caps.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.deg_malig.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.breast.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.breast_quad.value,this->random_value_factor(2,7)));
            CaseField::FieldValues.insert(std::make_pair(a.irradiat.value,this->random_value_factor(2,7)));

            double result = (CaseField::FieldValues[a.age.value] * CaseField::IdFactors[a.age.id]) + 
                            (CaseField::FieldValues[a.menopause.value] * CaseField::IdFactors[a.menopause.id]) + 
                            (CaseField::FieldValues[a.size.value] * CaseField::IdFactors[a.size.id]) + 
                            (CaseField::FieldValues[a.inv_nodes.value] * CaseField::IdFactors[a.inv_nodes.id]) + 
                            (CaseField::FieldValues[a.node_caps.value] * CaseField::IdFactors[a.node_caps.id]) + 
                            (CaseField::FieldValues[a.deg_malig.value] * CaseField::IdFactors[a.deg_malig.id]) + 
                            (CaseField::FieldValues[a.breast.value] * CaseField::IdFactors[a.breast.id]) + 
                            (CaseField::FieldValues[a.breast_quad.value] * CaseField::IdFactors[a.breast_quad.id]) + 
                            (CaseField::FieldValues[a.irradiat.value] * CaseField::IdFactors[a.irradiat.id]);

            // std::cout << a.type << std::endl;
            if(result > 50)
            {
                bool result = (a.type == recur_event);
                results.push_back(std::make_pair(entry_id, result));
                if(!result)
                    return;
            }
            else
            {
                bool result = (a.type != recur_event);
                results.push_back(std::make_pair(entry_id, result));
                if(!result)
                    return;
            }
            entry_id++;

            // if(this->results.size() > this->best)
            // {

            // }

        }
    }

};