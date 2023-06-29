
#include <cstring>
#include <bits/stdc++.h>

void wykryj_wyrazy(std::vector<std::string>& wyrazy, const char* wielomian)
{
    std::string tmp = "";
    std::vector<char> znaki;

    for(int i = 0; i < strlen(wielomian); i++)
    {
        if((wielomian[i] == '+') || (wielomian[i] == '-'))
        {
            znaki.push_back(wielomian[i]);
            
            if(tmp >)
                wyrazy.push_back(tmp);

            tmp = "";
            continue;
        }
        tmp += wielomian[i];
    }

    wyrazy.push_back(tmp);

    for(int i = 0; i < znaki.size(); i++)
    {
        std::cout << znaki[i] << " " << wyrazy[i] << std::endl;
        wyrazy[i] = znaki[i] + wyrazy[i];
    }

    // for(auto a : znaki)
    //     std::cout << a << std::endl;

    std::cout << std::endl;

    for(auto a : wyrazy)
        std::cout << a << std::endl;

    // if((wyrazy[0][0] != '-') && (wyrazy[0][0] != '+'))  
    //     wyrazy[0] = '+' + wyrazy[0];

}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "wykorzystanie: nazwa_programu wielomian" << std::endl;
        return 3;
    }
    
    std::vector<std::string> wyrazy;

    wykryj_wyrazy(wyrazy, argv[1]);

    // for(const auto& a : wyrazy)
    // for(int i = 0; i < wyrazy.size(); i++) 
    //     std::cout << i << " " << wyrazy[i] << std::endl;

}
