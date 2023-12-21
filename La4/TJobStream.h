#ifndef TJOBSTREAM_H
#define TJOBSTREAM_H

#include <random>

class TJobStream {
private:
    double JobIntensity;
    std::mt19937 RandomGenerator;
    std::uniform_real_distribution<double> JobDistribution;

public:
    TJobStream(double intensity);
    int GetNewJob();
};

#endif // TJOBSTREAM_H