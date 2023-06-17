#include "quaternion.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


Quaternion::Quaternion(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Quaternion::Quaternion() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

float Quaternion::getX() {
	return this->x;
}

float Quaternion::getY() {
	return this->y;
}

float Quaternion::getZ() {
	return this->z;
}

void Quaternion::setX(float x) {
	this->x = x;
}

void Quaternion::setY(float y) {
	this->y = y;
}

void Quaternion::setZ(float z) {
	this->z = z;
}

void Quaternion::abs() {
	this->x = fabsf(x);
	this->y = fabsf(y);
	this->z = fabsf(z);
}


Quaternion Quaternion::operator-(Quaternion other) {
	return Quaternion(this->x - other.x, this->y - other.y, this->z - other.z);
}
Quaternion Quaternion::operator+(Quaternion other) {
	return Quaternion(this->x + other.x, this->y + other.y, this->z + other.z);
}
Quaternion Quaternion::operator*(Quaternion other) {
	return Quaternion(this->x * other.x, this->y * other.y, this->z * other.z);
}
Quaternion Quaternion::operator/(Quaternion other) {
	return Quaternion(this->x / other.x, this->y / other.y, this->z / other.z);
}
Quaternion Quaternion::operator+=(Quaternion other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}
Quaternion Quaternion::operator-=(Quaternion other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}
Quaternion Quaternion::operator*=(Quaternion other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;

	return *this;
}
Quaternion Quaternion::operator/=(Quaternion other) {
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;

	return *this;
}
Quaternion Quaternion::operator%(Quaternion other) {
	return Quaternion(fmodf(this->x, other.x), fmodf(this->y, other.y), fmodf(this->z, other.z));
}
Quaternion Quaternion::operator%=(Quaternion other) {
	this->x = fmodf(this->x, other.x);
	this->y = fmodf(this->y, other.y);
	this->z = fmodf(this->z, other.z);
	return *this;
}


float Quaternion::degrees(float radiants) {
	return radiants / M_PI * 180;
}

float Quaternion::radiants(float degrees) {
	return degrees * M_PI / 180;
}



