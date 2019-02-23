/*
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#include <GForce/Object2D.hpp>
#include <GForce/Constants.hpp>

namespace gf
{
	Object2D::Object2D(double mass)
	{
		setMass(mass);
	}

	void Object2D::setMass(double mass)
	{
		m_Mass = mass;
	}

	void Object2D::addForce(Vector2D force)
	{
		m_Force += force;
	}

	void Object2D::setForce(Vector2D force)
	{
		m_Force = force;
	}

	void Object2D::tick(double deltaTime)
	{
		if(deltaTime == 0)
			return;

		m_Velocity += getAcceleration() * deltaTime;
		m_Position += m_Velocity * deltaTime;
	}

	void Object2D::setPosition(Vector2D new_pos)
	{
		m_Position = new_pos;
	}

	void Object2D::setVelocity(Vector2D new_vel)
	{
		m_Velocity = new_vel;
	}

	void Object2D::addVelocity(Vector2D vel)
	{
		m_Velocity += vel;
	}

	Vector2D Object2D::getAcceleration() const
	{
		return getForce() / getMass();
	}

	void Object2D::resetForce()
	{
		m_Force = Vector2D();
	}

	void Object2D::resetVelocity()
	{
		m_Velocity = Vector2D();
	}

	void Object2D::stopMovement()
	{
		resetForce();
		resetVelocity();
	}

	void Object2D::applyGravity(Object2D &a, bool update_a)
	{
		double force = GRAVITATIONAL_CONSTANT * (getMass() * a.getMass()) / distanceTo(a);

		Vector2D forceV = (a.getPosition() - getPosition()).normal();
		forceV *= force;
		addForce(forceV);
		if(update_a)
			a.addForce(-forceV);
	}

	double Object2D::distanceTo(const Object2D &other) const
	{
		return getPosition().distanceTo(other.getPosition());
	}
}