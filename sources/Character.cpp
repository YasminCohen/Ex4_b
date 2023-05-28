#include "Character.hpp"
using namespace std;

namespace ariel
{

    Character::Character(const string &name, const Point &Location, int hitPoint) : nameOfCharacter(name), Location(Location), hitPoint(hitPoint), belongTOTeam(false)
    {
    }

    bool Character::isAlive() const
    {
        if(this->hitPoint > 0){
            return true;
        }
        return false;
    }

    double Character::distance(Character *charecter) const
    {
        cheackNullPointer(charecter);
        double dist = this->Location.distance(charecter->Location);
        return dist;
    }

    void Character::hit(int numberHit)
    {
        if (numberHit < 0)
        {
            throw invalid_argument(" Sending negative value to hit()");
        }

        this->hitPoint -= numberHit;
    }

    string Character::getName() const
    {
        return this->nameOfCharacter;
    }

    const Point& Character::getLocation() const
    {
        return this->Location;
    }

    void Character::setLocation(Point &other){
        this->Location.setX(other.getX());
        this->Location.setY(other.getY());
    }

    bool Character::belongsToTeam() const{
        return this->belongTOTeam;
    }

    void Character::changeStatus(){
        this->belongTOTeam = true;
    }

    int Character::getHitPoint() const{
        return this->hitPoint;
    }
}