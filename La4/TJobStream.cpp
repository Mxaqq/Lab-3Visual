#include "TJobStream.h"
#include <random>

TJobStream::TJobStream(double intensity) {
    JobIntensity = intensity;
    RandomGenerator = std::mt19937(std::random_device{}());
    JobDistribution = std::uniform_real_distribution<double>(0.0, 1.0);
}

int TJobStream::GetNewJob() {
    double randomNumber = JobDistribution(RandomGenerator);
    if (randomNumber < JobIntensity) {
        static int nextJobId = 1;
        return nextJobId++;
    }

    return 0;
}