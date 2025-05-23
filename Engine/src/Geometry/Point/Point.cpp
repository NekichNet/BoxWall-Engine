#include <algorithm>

#include "Point.hpp"
#include "../../Math/Math.hpp"

using namespace engine_math;

const geom::Point& geom::Point::cord(AXIS axis, unsigned int value)
{
	switch (axis) {
	case geom::AXIS::X:
		x_ = value; break;
	case geom::AXIS::Y:
		y_ = value; break;
	case geom::AXIS::Z:
		z_ = value; break;
	case geom::AXIS::Q:
		q_ = value; break;
	}
}

int geom::Point::cord(AXIS axis)
{
	switch (axis) {
	case geom::AXIS::X:
		return x_;
	case geom::AXIS::Y:
		return y_;
	case geom::AXIS::Z:
		return z_;
	case geom::AXIS::Q:
		return q_;
	}
}

const geom::Point& geom::Point::x(int value) { x_ = value; }
int geom::Point::x() const { return x_; }
const geom::Point& geom::Point::y(int value) { y_ = value; }
int geom::Point::y() const { return y_; }
const geom::Point& geom::Point::z(int value) { z_ = value; }
int geom::Point::z() const { return z_; }
const geom::Point& geom::Point::q(int value) { q_ = value; }
int geom::Point::q() const { return q_; }

const geom::Vector& geom::Point::toVector() const
{
	return *(new Vector(*this));
}

void geom::Point::fromVector(const Vector& obj)
{
	x_ = obj.x();
	y_ = obj.y();
	z_ = obj.z();
	q_ = obj.q();
}

unsigned int geom::Point::getDistance(const Point& obj) const
{
	return sqrt(pow(std::max(obj.x_, x_) - std::min(obj.x_, x_), 2) +
		pow(std::max(obj.y_, y_) - std::min(obj.y_, y_), 2) +
		pow(std::max(obj.z_, z_) - std::min(obj.z_, z_), 2) +
		pow(std::max(obj.q_, q_) - std::min(obj.q_, q_), 2));
}

unsigned int geom::Point::getDistanceHorizontal(const Point& obj) const
{
	return sqrt(pow(std::max(obj.x_, x_) - std::min(obj.x_, x_), 2) +
		pow(std::max(obj.z_, z_) - std::min(obj.z_, z_), 2) +
		pow(std::max(obj.q_, q_) - std::min(obj.q_, q_), 2));
}

const geom::Vector& geom::Point::getRelative(const Point& obj) const
{
	return *(new Vector(
		abs(obj.x_ - x_),
		abs(obj.y_ - y_),
		abs(obj.z_ - z_),
		abs(obj.q_ - q_)
	));
}

const Point& geom::Point::createRelative(const Vector& vector) const
{
	// TODO: �������� ����� �������� return
}
