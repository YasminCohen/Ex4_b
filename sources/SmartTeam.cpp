#include "SmartTeam.hpp"

using namespace std;
namespace ariel{

    SmartTeam::SmartTeam(Character *chief):Team(chief)
    { 
    }

    void SmartTeam::attack(Team *teamOfChar){
    
        cheackNullPointer(teamOfChar);

        if (teamOfChar->stillAlive() == 0 || stillAlive() == 0 || teamOfChar == this)
            throw runtime_error("Other team is dead! or our Team is dead! or Cannot attack self team!");

        if (getCommander()->isAlive() == false)
        {
            setCommander(findSolider(this));
        }

        Character *vict = findSolider(teamOfChar);
    
        this->attackOfNinjas(teamOfChar, vict);
        this->attackOfCowboys(teamOfChar, vict);
	
    }
    void SmartTeam::print() const{
        
        cout << "There are "<< this->getSizeOfAllTeam() <<"people in the group. "<< endl;
        cout << this->stillAlive() <<" of them are alive"<< endl;
        cout << "Their commander is " << this->getCommander()->getName() << endl;
        cout << "Their commander is " << this->getCommander()->getName() << endl;
        string print = "";
        for (Character *member : getTeam()){
            print = member->print();
            cout << print << endl;
        }
            
    }
}
