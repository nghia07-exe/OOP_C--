#ifndef HEADER_H_
#define HEADER_H_

#include <math.h>

class Point3D {
   private:
    double x_, y_, z_;

   public:
    Point3D() : x_(0), y_(0), z_(0) {}
    Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}
    double distance(Point3D other) {
        double dx = this->x_ - other.x_;
        double dy = this->y_ - other.y_;
        double dz = this->z_ - other.z_;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
    void move(double dx, double dy, double dz) {
        x_ += dx;
        y_ += dy;
        z_ += dz;
    }
    void rotate() {
        double temp = y_;
        y_ = x_;
        x_ = -temp;
    }
};
// #include "main.h"
#endif  // HEADER_H_
