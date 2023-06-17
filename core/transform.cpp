#include "transform.h"
#include <cmath>
#include <iostream>
Transform::Transform() {
    this->localVector = Vector3();
    this->localRotation = Quaternion();
}

Transform::Transform(Vector3 v) {

    this->localVector = v;
    this->localRotation = Quaternion();
}

Transform::Transform(Vector3 v, Quaternion rotation) {
    this->localVector = v;
    this->localRotation = rotation;
}

Transform::Transform(double x, double y, double z) {
    this->localVector = Vector3(x, y, z);
    this->localRotation = Quaternion();
}

Transform::Transform(double x, double y, double z, Quaternion rotation) {
    this->localVector = Vector3(x, y, z);
    this->localRotation = rotation;
}
//Calculates the X, Y and Z angle from this GlobalVector to another Vector
Quaternion Transform::angleTo(Vector3 other) {
    float yaw, pitch, roll;
    Vector3 diff =  other - this->getGlobalVector3();
    
    yaw = asin(diff.getZ() / sqrt(pow(diff.getX(), 2) + pow(diff.getZ(), 2)));
    pitch = asin(diff.getY() / sqrt(pow(diff.getX(), 2) + pow(diff.getY(), 2)));
    roll = asin(diff.getY() / sqrt(pow(diff.getY(), 2) + pow(diff.getZ(), 2)));
    return Quaternion(Quaternion::degrees(yaw), Quaternion::degrees(pitch), Quaternion::degrees(roll));
}
//Calculates the X, Y and Z angle from a other Vector to this GlobalVector
Quaternion Transform::angleFrom(Vector3 other) {
    float yaw, pitch, roll;
    Vector3 diff = other - this->getGlobalVector3();

    yaw = acos(diff.getZ() / sqrt(pow(diff.getX(), 2) + pow(diff.getZ(), 2)));
    pitch = acos(diff.getY() / sqrt(pow(diff.getX(), 2) + pow(diff.getY(), 2)));
    roll = acos(diff.getY() / sqrt(pow(diff.getY(), 2) + pow(diff.getZ(), 2)));
    return Quaternion(Quaternion::degrees(yaw), Quaternion::degrees(pitch), Quaternion::degrees(roll));
}

//Global return Parents Rotation + Local Rotation. Is no Parent setted, it will just return the Local Rotation
Quaternion Transform::getGlobalRotation() {
    if (this->hasParent()) {
        return parent->getGlobalRotation() + this->getLocalRotation();
    }
    return this->getLocalRotation();
}

//Returns the Local Rotation
Quaternion Transform::getLocalRotation() {
    return this->localRotation;
}

//Returns the Parents Vector + Local Vector in relation the Parents Rotation
Vector3 Transform::getGlobalVector3() {
    if (this->hasParent()) {
        Vector3 globalVector = parent->getGlobalVector3() + this->getLocalVector3();
        Transform* parent = this->parent;

        Quaternion angle = getParent()->angleTo(globalVector);

        angle += getParent()->getGlobalRotation();
        Vector3 diff = globalVector - getParent()->getGlobalVector3();
        double newX, newY, newZ;
        newX = sin(angle.getX()) * sqrt(diff.getX()*diff.getX() + diff.getZ()*diff.getZ());
        newZ = cos(angle.getX()) * sqrt(diff.getX() * diff.getX() + diff.getZ() * diff.getZ());
        newY = sin(angle.getY())* sqrt(diff.getX() * diff.getX() + diff.getY() * diff.getY());
        diff = Vector3(newX, newY, newZ);
        return diff;
    }
    return this->getLocalVector3();
}
//Returns Local Vector
Vector3 Transform::getLocalVector3() {
    return this->localVector;
}
//Return if the Parent is not equal to nullptr
bool Transform::hasParent() {
    Transform* parent = this->parent;
    return parent != nullptr;
}
//Returns if this Transform is facing to a Vector 
bool Transform::isFacing(Vector3 point, float fov) {
     Quaternion angle = this->angleTo(point);
     Quaternion facing = this->getGlobalRotation();
     float facingYaw, facingPitch, angleYaw, anglePitch;
     facingYaw = facing.getX();
     facingPitch = facing.getY();
     angleYaw = angle.getX();   
     anglePitch = angle.getY();

     return facingYaw > angleYaw - fov && facingYaw < angleYaw + fov && facingPitch > anglePitch - fov && facingPitch < anglePitch + fov;
}
//Returns if this Transform is directly facing to a Vector
bool Transform::isFacing(Vector3 point) {
    return isFacing(point, 0);
}

Transform* Transform::getParent() {
    return this->parent;
}

void Transform::setRotation(Quaternion r) {
    this->localRotation = r;
}

void Transform::setParent(Transform p) {
    this->parent = &p;
}

void Transform::setParent(Transform* p) {
    this->parent = p;
}
