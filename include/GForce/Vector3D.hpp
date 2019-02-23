/*
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#ifndef GFORCE_VECTOR3D_HPP
#define GFORCE_VECTOR3D_HPP

#include <cmath>

// Help: https://en.wikipedia.org/wiki/Euclidean_vector

namespace gf
{
	template<typename T>
	class Vector3DBase {
	public:
		union {
			T x, width;
		};

		union {
			T y, height;
		};

		union {
			T z, depth;
		};

		Vector3DBase() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector3DBase(T x, T y, T z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/**
         * Returns the length (size, magnitude) of this vector.
         */
		double length() const {
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}

		/**
         * Returns a normalized vector.
         */
		Vector3DBase direction() const {
			return Vector3DBase(x / length(), y / length(), z / length());
		}

		/**
		 * Calculates the cross product.
		 *
		 * The cross product gives a vector that is perpendicular to both V1 and V2 and thus normal to the plane containing them.
		 *
		 * https://en.wikipedia.org/wiki/Cross_product
		 */
		Vector3DBase cross(const Vector3DBase &other) const {
			return Vector3DBase(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		}

		Vector3DBase mixedProduct(const Vector3DBase &b, const Vector3DBase &c) const {
			return *this * b.cross(c);
		}

		/**
		 * Calculates the distance to another position vector.
		 * @param to
		 * @return
		 */
		double distanceTo(const Vector3DBase &to) const {
			return sqrt(pow(to.x - x, 2) + pow(to.y - y, 2) + pow(to.z - z, 2));
		}

		double angleWith(const Vector3DBase &other) const {
			return (*this * other) / (length() * other.length());
		}

		bool isZero() const {
			return x == 0 && y == 0 && z == 0;
		}

		Vector3DBase operator +(const Vector3DBase& other) const {
			return Vector3DBase(x + other.x, y + other.y, z + other.z);
		}

		Vector3DBase operator -() const {
			return Vector3DBase(-x, -y, -z);
		}

		Vector3DBase operator -(const Vector3DBase& other) const {
			return Vector3DBase(x - other.x, y - other.y, z - other.z);
		}

		Vector3DBase operator /(const T& scalar) const {
			return Vector3DBase(x / scalar, y / scalar, z / scalar);
		}

		const Vector3DBase& operator +=(const Vector3DBase& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		const Vector3DBase& operator -=(const Vector3DBase& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		const Vector3DBase& operator *=(const T& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		const Vector3DBase& operator /=(const T& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		/**
		 * Dot product.
		 */
		T operator *(const Vector3DBase& other) const {
			return x * other.x + y * other.y + z * other.z;
		}

		Vector3DBase operator *(const T& constant) const {
			return Vector3DBase<T>(x * constant, y * constant, z * constant);
		}

		Vector3DBase& operator =(const Vector3DBase& other) {
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		bool operator ==(const Vector3DBase& other) const {
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator !=(const Vector3DBase& other) const {
			return x != other.x || y != other.y || z != other.z;
		}
	};

	typedef Vector3DBase<double> Vector3D;
	typedef Vector3DBase<float> Vector3Df;
	typedef Vector3DBase<int> Vector3Di;
	typedef Vector3DBase<unsigned int> Vector3Du;
}

#endif //GFORCE_VECTOR3D_HPP
