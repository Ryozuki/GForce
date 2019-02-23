/*
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#ifndef GFORCE_OBJECT2D_HPP
#define GFORCE_OBJECT2D_HPP

#include "Vector2D.hpp"

namespace gf
{
	class Object2D
	{
	private:
		double m_Mass;
		Vector2D m_Position;
		Vector2D m_Force;
		Vector2D m_Velocity;

	public:
		explicit Object2D(double mass = 100);

		void setPosition(Vector2D new_pos);

		Vector2D getPosition() const { return m_Position; }

		/**
		 * Sets the mass of the object
		 */
		void setMass(double mass);

		double getMass() const { return m_Mass; }

		/**
		 * Adds a force to the object.
		 */
		void addForce(Vector2D force);

		/**
		 * Sets the current force the object holds.
		 */
		void setForce(Vector2D force);

		Vector2D getForce() const { return m_Force; }

		void addVelocity(Vector2D vel);

		void setVelocity(Vector2D new_vel);

		Vector2D getVelocity() { return m_Velocity; };

		Vector2D getAcceleration() const;

		// Sets the force to 0.
		void resetForce();

		// Sets the velocity to 0.
		void resetVelocity();

		// Resets both velocity and force, thus stopping any motion.
		void stopMovement();

		double distanceTo(const Object2D &other) const;

		/**
		 * Applies the gravity force between the 2 objects.
		 * If update_a is true a will be updated too.
		 */
		void applyGravity(Object2D &a, bool update_a = true);

		/**
		 * Updates the object based on the delta time, the current force.
		 * @param deltaTime
		 */
		void tick(double deltaTime);
	};
}

#endif //GFORCE_OBJECT2D_HPP
