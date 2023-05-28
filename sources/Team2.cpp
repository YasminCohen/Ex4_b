#include "Team2.hpp"

using namespace std;

namespace ariel{        
        
    Team2::Team2(Character* commander):Team(commander){

    }

    void Team2::attack(Team *other)
    {
        cheackNullPointer(other);

        if (other->stillAlive() == 0 || this->stillAlive() == 0 || other == this)
            throw runtime_error("Other team is dead! or our Team is dead! or Cannot attack self team!");

        if (getCommander()->isAlive() == false)
        {
            setCommander(findSolider(this));
        }

    Character* target = findSolider(other);

    for (auto& member : getTeam()) {
        if (target->isAlive() == false) {
            if (other->stillAlive() <1) {
                break;
            }
            target = findSolider(other);
        }

        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
            if (cowboy->isAlive()) {
                if (!cowboy->hasboolets()) {
                    cowboy->reload();
                } else {
                    cowboy->shoot(target);
                }
            }
        } else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
            if (ninja->isAlive()) {
                if (ninja->getLocation().distance(target->getLocation()) >1) {
                    ninja->move(target);
                } else {
                    ninja->slash(target);
                }
            }
        }
    }

    }

    void Team2::print() const
    {
        cout << "There are "<< this->getSizeOfAllTeam() <<"people in the group. "<< endl;
        cout << this->stillAlive() <<" of them are alive"<< endl;
        cout << "Their commander is " << this->getCommander()->getName() << endl;
        cout << "Their commander is " << this->getCommander()->getName() << endl;
        string print = "";
        for (Character *member : getTeam()){
            print = member->print();
            cout << member->print() << endl;
        }
            
    }
}
