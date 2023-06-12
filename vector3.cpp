#include "vector3.h"
#include <cmath>

Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3::Vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vector3::Vector3(double x, double y) {
    this->x = x;
    this->y = y;
    this->z = 0;
}
Vector3 Vector3::operator-(Vector3 other)
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}
Vector3 Vector3::operator+(Vector3 other)
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}
Vector3 Vector3::operator*(Vector3 other)
{
    return Vector3(x * other.x, y * other.y, z * other.z);
}
Vector3 Vector3::operator/(Vector3 other)
{
    return Vector3(x / other.x, y / other.y, z / other.z);
}
Vector3 Vector3::operator+=(Vector3 other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}
Vector3 Vector3::operator-=(Vector3 other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}
Vector3 Vector3::operator*=(Vector3 other)
{
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return *this;
}
Vector3 Vector3::operator/=(Vector3 other){
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
    return *this;
}

double Vector3::distance(Vector3 other){
    Vector3 diff = *this - other;
    double distanceXY = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
    double distance = sqrt(pow(distanceXY, 2) + pow(diff.z, 2));
    return distance;
}

double Vector3::getX(){
    return this->x;
}
double Vector3::getY(){
    return this->y;
}
double Vector3::getZ(){
    return this->z;
}


void Vector3::setX(double x) {
    this->x = x;
}
void Vector3::setY(double y) {
    this->y = y;
}
void Vector3::setZ(double Z) {
    this->z = z;
}