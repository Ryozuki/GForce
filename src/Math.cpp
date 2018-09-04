/* 
 * (c) Edgar Luque. See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#include "GForce/Math.hpp"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

namespace gf
{
    double Math::toDegrees(double radians) {
        return radians * (180 / M_PI);
    }

    double Math::toRadians(double degrees) {
        return (M_PI * degrees) / 180;
    }
}
