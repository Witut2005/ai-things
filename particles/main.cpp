
#include <unistd.h>
#include <bits/stdc++.h>
#include "./particle/particle.cpp"

int main(void)
{
    uint64_t number_of_particles = 1000000;

    Particle* particles = new Particle[number_of_particles];

    std::pair<double, double> PositionToFind = {1000, 500000.0 / 2};

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 500000.0);

    // for(int i = 0; i < number_of_particles; i++)
    //     std::cout << distribution(generator) << std::endl;

    for(int i = 0; i < number_of_particles; i++)
        particles[i] = *new Particle(PositionToFind, std::make_pair(distribution(generator), distribution(generator)), 1, 2, 1);

    std::cout << Particle::get_sworm_best().first << " " << Particle::get_sworm_best().second << std::endl;

    while(Particle::get_sworm_best() != PositionToFind)
    {

        auto best = Particle::get_sworm_best();

        for(int i = 0; i < number_of_particles; i++)
            particles[i].update_position();

        for(int i = 0; i < number_of_particles; i++)
        {
            if(Particle::calculate_distance(PositionToFind, particles[i].get_position()) < Particle::calculate_distance(PositionToFind, best))
                std::cout << particles[i].get_position().first << " " << particles[i].get_position().second << std::endl;
        }
    }
    std::cout << Particle::get_sworm_best().first << " " << Particle::get_sworm_best().second << std::endl; 
}