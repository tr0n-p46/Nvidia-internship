#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <math.h>

#include "Vec3D.h"

using namespace std;

Vec3D::Vec3D() : x(0), y(0), z(0) {}

Vec3D::Vec3D(double x, double y) : x(x), y(y), z(0) {}

Vec3D::Vec3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3D::Vec3D(const Vec3D &v) : x(v.x), y(v.y), z(v.z) {}

double Vec3D::getX() {
	return this->x;
}

void Vec3D::setX(const double x) {
	this->x = x;
}

double Vec3D::getY() {
	return this->y;
}	

void Vec3D::setY(const double y) {
	this->y = y;
}

double Vec3D::getZ() {
	return this->z;
}	

void Vec3D::setZ(const double z) {
	this->z = z;
}

bool Vec3D::operator==(const Vec3D &v) {
	return this->x==v.x?(this->y==v.y?(this->z==v.z?true:false):false):false;
}

bool Vec3D::operator!=(const Vec3D &v) {
	return !(*this==v);
}

Vec3D& Vec3D::operator=(const Vec3D &v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

Vec3D Vec3D::operator+(const Vec3D &v) {
	return Vec3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec3D Vec3D::operator-(const Vec3D &v) {
	return Vec3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec3D& Vec3D::operator+=(const Vec3D &v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

Vec3D& Vec3D::operator-=(const Vec3D &v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

Vec3D& Vec3D::operator-() {
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
	return *this;
}

Vec3D& Vec3D::operator*=(double c) {
	this->x *= c;
	this->y *= c;
	this->z *= c;
	return *this;
}

Vec3D& Vec3D::operator/=(double c) {
	assert(c != 0);
	this->x /= c;
	this->y /= c;
	this->z /= c;
	return *this;
}

Vec3D Vec3D::operator*(double c) {
	return Vec3D(this->x * c, this->y * c, this->z * c);
}

Vec3D Vec3D::operator/(double c) {
	assert(c != 0);
	return Vec3D(this->x / c, this->y / c, this->z / c);
}

double Vec3D::operator[](const int i) {
	assert(i == 0 || i == 1 || i == 2);
	return i==0?this->x:(i==1?this->y:this->z);
}

double Vec3D::getDistanceFromPoint(const Vec3D &v) {
	Vec3D temp(*this-v);
	return temp.getMagnitude();
}

double Vec3D::getdistanceFromOrigin(const Vec3D &v) {
	return getDistanceFromPoint(Vec3D(0,0));
}

Vec3D Vec3D::getCrossProduct(const Vec3D &v) {
	return Vec3D(this->y * v.z - this->z * v.y,
				 this->z * v.x - this->x * v.z,
				 this->x * v.y - this->y * v.x
				 );
}

double Vec3D::getDotProduct(const Vec3D &v) {
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}

void Vec3D::normalize() {
	double magnitude = getMagnitude();
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;
}

double Vec3D::getMagnitude() {
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vec3D::show() {
	cout<<"("<<this->x<<", "<<this->y<<", "<<this->z<<")"<<endl;
}