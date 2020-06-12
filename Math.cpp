#include "Math.h"

Math::Math()
{
    //ctor
}

#include <random>
#include <string>
void Math::normal(int length, double* result)
{
    const int nrolls=length;  // number of experiments
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0,2.0);

    for (int i=0; i<nrolls; ++i) {
        double number = distribution(generator);
        result[i] = number;
    }
}

float Math::getDistance(float x1, float y1, float x2, float y2)
{
    //Thank you Pythagoras!
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
