//
//  main.cpp
//  cpp
//
//  Created by devontae.reid on 8/30/17.
//  Copyright © 2017 devontae.reid. All rights reserved.
//

#include <iostream>
using namespace std;

const double PI = 3.14159265359;

class point {
public:
    point(double x = 0.0, double y = 0) :  x_(x), y_(y) {};
    
    double x() const { return x_; };
    double y() const { return y_ ;};
    
    void x(double x) { x_ = x; };
    void y(double y) { y_ = y; };
    
    friend ostream& operator<<(ostream& os, const point& pt) {
        return os << "X: " << pt.x() << " Y: " << pt.y();
    }
    
private:
    double x_;
    double y_;
};

class shape {
public:
    shape(const point& center = 0) : center_(center) {};
    
    point center() const {return center_;}
    void center(point center) { center = center; }
    
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    
private:
    point center_;
    
};

class circle : public shape{
public:
    
    circle(double radius = 0.0, point center = 0.0) : radius_(radius), shape(center) {};
    
    double radius() const {return radius_;}
    void radius(double radius) { radius_ = radius; }
    
    
    double area() const { return PI * radius_ * radius_; }
    double perimeter() const { return 2.0 * PI * radius_; }
    
    friend ostream& operator<<(ostream& os,circle& c){
        return os << "Circle:\nRadius: " << c.radius()
                    << " Center : " << c.center()
                    << " Area: " << c.area()
                    << " Perimeter: " << c.perimeter() << "\n";
    }
    
private:
    double radius_;
};


class rectangle : public shape {
public:
    rectangle(double height = 0.0, double width = 0.0 , point center = 0.0) : height_(height) , width_(width) , shape(center) {};
    
    double height() const { return height_; }
    void height(double height) { height_  = height; }
    
    double width() const { return width_; }
    void width(double width) { width_ = width; }
    
    double area() const { return height_ * width_; }
    double perimeter() const { return (2 * height_) + (2 * width_); }
    
    friend ostream& operator<<(ostream& os,rectangle& r){
        return os << "Rectangle:\nHeight: " << r.height()
        << " Width: " << r.width()
        << " Center: " << r.center()
        << " Area: " << r.area()
        << " Perimeter: " << r.perimeter() << "\n";
    }
    
private:
    double width_;
    double height_;
    
};

int main(int argc, const char * argv[]) {
    
    circle c;
    circle c2(2);
    circle c3(3,point(2,3));
    
    cout << c << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    
    
    rectangle s;
    rectangle s2(2,3);
    rectangle s3(56,40,point(39,23));
    
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    
}
