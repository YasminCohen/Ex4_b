#ifndef MY_POINT
#define MY_POINT

#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace ariel{
    
    class Point
    {
        private:
            double xOfPoint;
            double yOfPoint;
        public:
            Point(double xNew, double yNew);
            double distance(const Point& other) const;
            string print() const;
            static Point moveTowards(const Point& first, const Point& second, double distance);

            bool operator==(const Point& other) const;
            void setX(double setOfx);
            void setY(double setOfy);
            double getX() const;
            double getY() const;
    };
}
#endif