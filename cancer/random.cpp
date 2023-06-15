
#include <bits/stdc++.h>

// generate random integer
int randomInt() { return rand(); }

// generate random integer in a range [Min , Max)
int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

// generate random fraction

float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}

// generate random float in a range
float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;

    return (float)randomInt(a, b) + randomFloat();
}