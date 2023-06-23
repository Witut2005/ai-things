

#include <bits/stdc++.h>

class Particle
{
    private:
    static double sworm_best; 

    double inertia;
    double cognitive_const;
    double social_const;
    double velocity;

    public:

    Particle(){}

    Particle(std::pair<double, double> vector, const double inertia, const double cognitive_const, const double social_const) : inertia(inertia), cognitive_const(cognitive_const), social_const(social_const)
    {
        
    }

    void update_position(void)
    {

    }

    void update_velocity(void)
    {
        // double cognitive_velocity 
    }
};

double Particle::sworm_best;