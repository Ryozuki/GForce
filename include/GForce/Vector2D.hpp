/*
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#ifndef GFORCE_VECTOR2DBASE_HPP
#define GFORCE_VECTOR2DBASE_HPP

#include <cmath>

namespace gf
{
    template <typename T>
    class Vector2DBase {
    public:
        union {
            T x, w;
        };

        union {
            T y, h;
        };

        Vector2DBase() {
            this->x = 0;
            this->y = 0;
        }

        Vector2DBase(T x, T y) {
            this->x = x;
            this->y = y;
        }

        double angleWith(const Vector2DBase& other) const {
            // TODO: Return the smallest angle? E.g if it's > 180, return angle - 180.
            return ((*this) * other) / (length() * other.length());
        }

        double angle() const {
            return atan(y / x);
        }

        bool isZero() const {
            return x == 0 && y == 0;
        }

        /**
         * Returns the length (size) of this vector.
         */
        double length() const {
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        /**
         * Returns a normalized vector.
         */
        Vector2DBase direction() const {
            return Vector2DBase(x / length(), y / length());
        }

        /**
         * Calculates the normal vector of this vector.
         * @return
         */
        Vector2DBase normal() const {
            return Vector2DBase(-y, x);
        }

        Vector2DBase operator +(const Vector2DBase& other) const {
            return Vector2DBase(this->x + other.x, this->y + other.y);
        }

        Vector2DBase operator -() const {
            return Vector2DBase(-x, -y);
        }

        Vector2DBase operator -(const Vector2DBase& other) const {
            return Vector2DBase(x - other.x, y - other.y);
        }

        Vector2DBase operator /(const T& scalar) const {
            return Vector2DBase(x / scalar, y / scalar);
        }

        const Vector2DBase& operator +=(const Vector2DBase& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        const Vector2DBase& operator -=(const Vector2DBase& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        const Vector2DBase& operator /=(const T& scalar) {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        T operator *(const Vector2DBase& other) const {
            return x * other.x + y * other.y;
        }

        Vector2DBase operator *(const T& scalar) const {
            return Vector2DBase<T>(x * scalar, y * scalar);
        }

        Vector2DBase& operator =(const Vector2DBase& other) {
            x = other.x;
            y = other.y;
            return *this;
        }

        bool operator ==(const Vector2DBase& other) const {
            return x == other.x && y == other.y;
        }

        bool operator !=(const Vector2DBase& other) const {
            return x != other.x || y != other.y;
        }
    };

    typedef Vector2DBase<double> Vector2D;
    typedef Vector2DBase<float> Vector2Df;
    typedef Vector2DBase<int> Vector2Di;
    typedef Vector2DBase<unsigned  int> Vector2Du;
}

#endif //GFORCE_VECTOR2DBASE_HPP
