#include "Ninja.hpp"

using namespace std;

namespace ariel{

        Ninja::Ninja(const string &name, int speed,const Point &Location, int hitPoint):speed(speed),Character(name, Location,hitPoint)
        {
        }

        void Ninja::move(Character* cowboy)
        {
                cheackNullPointer(cowboy);
                if (cowboy== this){
                        throw invalid_argument("ninja  Cannot move to himself!");
                }
                if(this->isAlive()== false){
                throw runtime_error("Dead characters cannot to move");
                }

		
             Point newPoint = Point::moveTowards(this->getLocation(), cowboy->getLocation(),this->speed);
             this->setLocation(newPoint);
        }
    
        void Ninja::slash(Character* cowboy) const
        {
                cheackNullPointer(cowboy);
		
                if(cowboy->isAlive() == false || this->isAlive() == false||cowboy== this){
                        throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy Cannot slash yourself!");
                }
                double dist = this->distance(cowboy);
                if(dist>1){
                        return;
                }else{
                        cowboy->hit(40);
                }
        }
        
        string Ninja::print() const{
        
                string name = this->getName();
                string hitPointing = to_string(this->getHitPoint());
                string locations =  this->getLocation().print();
                if (isAlive() == true){
                        return " N " + name + ", his HitPoints: " + hitPointing + ", his Location: " + locations;
                }
                return " N (" + name + "), his Location: " + locations;
        }
}
