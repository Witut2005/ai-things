
#pragma once
#include <bits/stdc++.h>

#include <string>

struct CaseField
{
    std::string id;
    std::string value;
    static std::unordered_map<std::string, double> IdFactors;
    static std::unordered_map<std::string, double> FieldValues;
};

std::unordered_map<std::string, double> CaseField::IdFactors;
std::unordered_map<std::string, double> CaseField::FieldValues;

#define MAKE_STRING(x) #x

struct CancerCase
{
    CancerCase(std::string type, std::string age, std::string menopause, std::string size, std::string inv_nodes, std::string node_caps, 
                std::string deg_malig, std::string breast, std::string breast_quad, std::string irradiat)
    {
        this->type = type;
        this->age = {MAKE_STRING(age), age};
        this->menopause = {MAKE_STRING(menopause), menopause};
        this->size = {MAKE_STRING(size), size};
        this->inv_nodes = {MAKE_STRING(inv_nodes), inv_nodes};
        this->node_caps = {MAKE_STRING(node_caps), node_caps};
        this->deg_malig = {MAKE_STRING(deg_malig), deg_malig};
        this->breast = {MAKE_STRING(breast), breast};
        this->breast_quad = {MAKE_STRING(breast_quad), breast_quad};
        this->irradiat = {MAKE_STRING(irradiat), irradiat};
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