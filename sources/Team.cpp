#include "Team.hpp"
#include <algorithm> 


using namespace std;

namespace ariel{

    Team::Team(Character *commander):commander(commander){
        cheackNullPointer(commander);
        cheackBelongsToTeam(commander);
        this->team.push_back(commander);
        commander->changeStatus();
    }


    Team::~Team(){
        for_each(team.begin(), team.end(), [](Character* temp) {
            delete temp;
        });
    }

    void Team::add(Character* Character){

        cheackNullPointer(Character);
        cheackBelongsToTeam(Character);
        if(this->getSizeOfAllTeam()==10){
            throw runtime_error("It is not possible to add more than 10 people to the group");
        }

        this->team.push_back(Character);
        Character->changeStatus();
    }

    
    Character *Team::findSolider(Team *other) const
    {
        double distance = Max;
        double temp =0;
        Character *result = nullptr;
        for(std::vector<Character*>::size_type i = 0; i<(int)other->getSizeOfAllTeam(); i++){
            if(other->team.at(i)->isAlive()){
                 temp = this->commander->distance(other->team.at(i));
                if(temp<distance){
                    distance = temp;
                    result = other->team.at(i);
                }
             }
        }
        return result;
    }


    void Team::attackOfCowboys(Team* enemyTeam, Character* target) {
        for (auto& member : team) {

            if (!member->isAlive()) {
                continue;
            }

            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy == nullptr) {
                continue;
            }

            if (!cowboy->hasboolets()) {
                cowboy->reload();
                continue;
            }

            if (target->isAlive()) {
                cowboy->shoot(target);
            } else {

                if (enemyTeam->stillAlive() < 1) {
                    break;
                }
                target = findSolider(enemyTeam);
                if (target != nullptr) {
                    cowboy->shoot(target);
                }
            }


        }
    }


    void Team::attackOfNinjas(Team* teamOfChar, Character *vict){

        for (Character *characterTemp : this->team)
	    {
            if(characterTemp->isAlive()== false)
            {
                continue;
            }
            
            if (vict->isAlive() == false)
            {
                if (teamOfChar->stillAlive() <1)
                    break;

                vict = findSolider(teamOfChar);
            }

            Ninja *ninja = dynamic_cast<Ninja *>(characterTemp);
            if (ninja == nullptr ){
                continue;
            }
            
            if (ninja->getLocation().distance(vict->getLocation()) > 1){
                    ninja->move(vict);
            }
            else{
                ninja->slash(vict);
            }
        }
    }

    void Team::attack(Team* teamOfChar){
    
        cheackNullPointer(teamOfChar);

        if (teamOfChar->stillAlive() == 0 || stillAlive() == 0 || teamOfChar == this)
            throw runtime_error("Other team is dead! or our Team is dead! or Cannot attack self team!");

        if (commander->isAlive() == false)
        {
            this->commander = findSolider(this);;
        }

        Character *vict = findSolider(teamOfChar);
    
        this->attackOfCowboys(teamOfChar, vict);
        this->attackOfNinjas(teamOfChar, vict);
	
    }


    void Team::print() const{
        cout << "There are "<< this->getSizeOfAllTeam() <<"people in the group. "<< endl;
        cout << this->stillAlive() <<" of them are alive"<< endl;
        cout << "Their commander is " << this->commander->getName() << endl;
        cout << "Their commander is " << this->commander->getName() << endl;

        for (Character *temp : this->team)
        {
            if (dynamic_cast<Cowboy *>(temp)){
                continue;
            }
            else{
                cout << temp->print() << endl;
            }
        }

        for (Character *temp : this->team)
        {
            if (dynamic_cast<Ninja *>(temp)){
                continue;
            }else{
                cout << temp->print() << endl;
            }
        }
    }

    Character* Team::getCommander() const{
        return this->commander;
    }

    void Team::setCommander(Character *commander){
        this->commander = commander;
    }

    int Team::stillAlive() const{

        int stillAlive = 0;
    
        for (Character *temp : this->team)
	    {
            if (!temp->isAlive()){
                continue;
            }
            stillAlive = stillAlive+1;
	    }
        return stillAlive;
    }

    const vector<Character*>& Team::getTeam() const{
        return this->team;
    }
    int Team::getSizeOfAllTeam() const{
        return (int)this->team.size();
    }

}