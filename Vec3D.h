#ifndef Vec3D_H
#define Vec3D_H
 
class Vec3D {
   protected:
      double x, y, z;

   public:
      Vec3D();
      Vec3D(double x, double y);
      Vec3D(double x, double y, double z);
      Vec3D(const Vec3D &v);  
      double getX();
      void setX(const double x);
      double getY();
      void setY(const double y);
      double getZ();
      void setZ(const double z);
      void setXYZ(double x, double y, double z);
      bool operator==(const Vec3D &v);
      bool operator!=(const Vec3D &v);
      Vec3D& operator=(const Vec3D &v);
      Vec3D operator+(const Vec3D &v);
      Vec3D operator-(const Vec3D &v);
      Vec3D& operator+=(const Vec3D &v);
      Vec3D& operator-=(const Vec3D &v);
      Vec3D& operator-();
      Vec3D operator*(double c);
      Vec3D operator/(double c);
      Vec3D& operator*=(double c);
      Vec3D& operator/=(double c);
      double operator[](const int i);
      double getDistanceFromPoint(const Vec3D &v);
      double getdistanceFromOrigin(const Vec3D &v);
      Vec3D getCrossProduct(const Vec3D &v);
      double getDotProduct(const Vec3D &v);
      void normalize();
      double getMagnitude();
      void show();
};

#endif