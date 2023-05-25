
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

#include <GLCD/Computation.h>
#include <GLCD/MCvMDistanceAsym.h>
#include <GLCD/MCvMDistanceSymEven.h>
#include <GLCD/MCvMDistanceSymOdd.h>
#include <GLCD/Misc.h>
#include <stdexcept>

namespace GLCD {

Computation::Computation()
{
    // By default, use varying bMax
    setBMax(-1);
    
    // By default, use point symmetric sampling
    setSymmetric(true);
}

Computation::~Computation()
{

}

void Computation::setSymmetric(bool useSymmetric)
{
    this->useSymmetric = useSymmetric;
}

void Computation::setBMax(double bMax)
{
    this->forceBMax = bMax;
}

}   // namespace GLCD

