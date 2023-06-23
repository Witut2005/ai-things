
#include <bits/stdc++.h>
#include "./particle/particle.cpp"

int main(void)
{
    int number_of_particles = 50;

    Particle* particles = new Particle[number_of_particles];

    std::pair<double, double> PositionToFind = {500.0, 500.0};

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-10.0, 10.0);

    for(int i = 0; i < number_of_particles; i++)
        particles[i] = *new Particle(std::make_pair(distribution(generator), distribution(generator)), 1, 2, 1);



}