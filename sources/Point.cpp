#include "Point.hpp"

using namespace std;

namespace ariel{
    
    Point::Point(double xNew, double yNew):xOfPoint(xNew),yOfPoint(yNew){
    }

    double Point::distance(const Point& other) const {

        double deltaX = other.xOfPoint - this->xOfPoint;
        double deltaY = other.yOfPoint - this->yOfPoint;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    string Point::print() const{
        string xFrom = to_string(this->xOfPoint);
        string yFrom = to_string(this->yOfPoint);
        return "(" + xFrom+ ","+yFrom+")";
    }

    Point Point::moveTowards(const Point& first, const Point& second, double dist) { 
        if(dist<0){
            throw invalid_argument("It is not possible to enter a negative distance");
        }

        if ((first.distance(second)) <= dist) {
            return second;
        }
        
        double proportion = dist/ (first.distance(second));
        double distx = second.getX() - first.getX();
        double disty = second.getY() - first.getY();
        Point result = Point(first.getX() + (distx * proportion), first.getY() + (disty * proportion));
        return result;
    }




    bool Point::operator==(const Point& other) const { 
        bool boolX= (this->xOfPoint == other.xOfPoint);
        bool boolY= (this->yOfPoint == other.yOfPoint);
        return boolX && boolY ;
    }

    void Point::setX(double setOfx){
        this->xOfPoint = setOfx;
    }

    void Point::setY(double setOfy){
        this->yOfPoint = setOfy;
    }

    double Point::getX() const{
        return this->xOfPoint;
    }

    double Point::getY() const{
        return this->yOfPoint;
    }

}
