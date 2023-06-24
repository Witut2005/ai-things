

#include <bits/stdc++.h>

class Particle
{
    private:
    static std::pair<double, double> SwormBest; 

    double inertia;
    double cognitive_const;
    double social_const;

    double velocity;
    std::pair<double, double> Position;
    std::pair<double, double> Destination;
    std::pair<double, double> PersonalBest;

    public:

    Particle(){}

    Particle(std::pair<double, double> Destination, std::pair<double, double> Position, const double inertia, const double cognitive_const, const double social_const) : Destination(Destination), Position(Position), inertia(inertia), 
                cognitive_const(cognitive_const), social_const(social_const)
    {
        velocity = 0;

        if(calculate_distance(this->Destination, this->Position) < calculate_distance(this->Destination, this->SwormBest))
            this->SwormBest = this->Position;

    }

    static double calculate_distance(std::pair<double, double> Destination, std::pair<double, double> CurrentPosition)
    {
        return sqrt(pow(CurrentPosition.first - Destination.first, 2) + pow(CurrentPosition.second - Destination.second, 2));
    }

    static std::pair<double, double> get_sworm_best(void)
    {
        return Particle::SwormBest;
    }

    void update_position(void)
    {
        this->update_velocity();

        this->Position.first += this->velocity;
        this->Position.second += this->velocity;

        if(calculate_distance(this->Destination, this->Position) < calculate_distance(this->Destination, this->SwormBest))
            this->SwormBest = this->Position;

        
        
    }

    auto get_position(void)
    {
        return this->Position;
    }

    void update_velocity(void)
    {
        double inertia_velocity = this->inertia * this->velocity;
        double cognitive_velocity = 0.2 * this->cognitive_const * ((this->PersonalBest.first - this->Position.first) + (this->PersonalBest.second - this->Position.second));
        double social_velocity = 0.1 * this->social_const * sqrt((pow(this->SwormBest.first - this->Position.first, 2) + pow(this->SwormBest.second - this->Position.second, 2)));

        this->velocity = inertia_velocity + cognitive_velocity + social_velocity;
    }
};

std::pair<double, double> Particle::SwormBest = {std::numeric_limits<double>::max(), std::numeric_limits<double>::max()};