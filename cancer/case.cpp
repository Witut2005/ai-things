
#pragma once
#include <bits/stdc++.h>

#include <string>

struct CaseField
{
    std::string value;
    static std::unordered_map<std::string, double> InputValues; 
    static std::unordered_map<std::string, double> Weights;
};

std::unordered_map<std::string, double> CaseField::InputValues;
std::unordered_map<std::string, double> CaseField::Weights;

#define MAKE_STRING(x) #x

struct CancerCase
{
    CancerCase(std::string type, std::string age, std::string menopause, std::string size, std::string inv_nodes, std::string node_caps, 
                std::string deg_malig, std::string breast, std::string breast_quad, std::string irradiat)
    {
        this->type = type;
        this->age = { age };
        this->menopause = { menopause };
        this->size = { size };
        this->inv_nodes = { inv_nodes };
        this->node_caps = { node_caps };
        this->deg_malig = { deg_malig };
        this->breast = { breast };
        this->breast_quad = { breast_quad };
        this->irradiat = { irradiat };
    }

    std::string type;
    CaseField age;
    CaseField menopause;
    CaseField size;
    CaseField inv_nodes;
    CaseField node_caps;
    CaseField deg_malig;
    CaseField breast;
    CaseField breast_quad;
    CaseField irradiat;
};