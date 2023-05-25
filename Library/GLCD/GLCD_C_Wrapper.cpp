#include "GLCD_C_Wrapper.h"
#include <GLCD/Computation.h>
#include <memory>

extern "C"
{
    double* createSamples(int dimension, int numSamples)
    {
        GLCD::Computation computation;
        auto raw_data = std::make_unique<double[]>(dimension * numSamples);
        Eigen::Map<Eigen::MatrixXd> samples(raw_data.get(), dimension, numSamples);

        Eigen::MatrixXd initialParameters;
        Optimization::Result result = computation(dimension, numSamples, initialParameters, samples);
        return raw_data.release();
    }
}