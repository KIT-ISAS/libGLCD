
/* >> This file is part of the Nonlinear Estimation Toolbox
 *
 *    For more information, see https://bitbucket.org/nonlinearestimation/toolbox
 *
 *    Copyright (C) 2015-2017  Jannik Steinbring <nonlinearestimation@gmail.com>
 *                             Martin Pander
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GLCD_MISC_H_
#define _GLCD_MISC_H_

#include <Eigen/Dense>

namespace GLCD {

template<typename Derived>
void meanCorrection(const Eigen::MatrixXd& samples,
                    Eigen::MatrixBase<Derived>& correctedSamples)
{
    const Eigen::MatrixXd::Index numSamples = samples.cols();
    const double weight = 1.0 / numSamples;
    
    const Eigen::VectorXd mean = weight * samples.rowwise().sum();
    
    correctedSamples = samples.colwise() - mean;
}

template<typename Derived>
void covarianceCorrection(const Eigen::MatrixXd& samples,
                          Eigen::MatrixBase<Derived>& correctedSamples)
{
    const Eigen::MatrixXd::Index numSamples = samples.cols();
    const double weight = 1.0 / numSamples;
    
    const Eigen::MatrixXd cov = weight * (samples * samples.transpose());
    
    correctedSamples = cov.inverse().llt().matrixL().transpose() * samples;
}

void stdNormalRndMatrix(unsigned int rows,
                        unsigned int cols,
                        Eigen::MatrixXd& rndMatrix);

double normalizedCovError(const Eigen::MatrixXd& samples);

}   // namespace GLCD

#endif
