#include "Cowboy.hpp"

using namespace std;
namespace ariel{

    Cowboy::Cowboy(const string& name,const Point& Location):amountOfBools(bools),Character(name,Location,hiting)
    {        
    }
    void Cowboy::shoot(Character *Ninjago)
    {
        cheackNullPointer(Ninjago);
        if(Ninjago->isAlive() == false || this->isAlive()== false ||Ninjago== this){
                throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy, and Cannot shoot yourself!");
        }

        if(this->amountOfBools >=1){
            Ninjago->hit(10);
            this->amountOfBools--;
        }

    }

    bool Cowboy::hasboolets() const
    {
        if (this->amountOfBools>0){
            return true;
        }
        return false;
    }

    void Cowboy::reload()
    {
        if(this->isAlive()==false){
            throw runtime_error(" Dead cowboy can not reload");
        }
        if(amountOfBools<6){
            this->amountOfBools =6;
        }    
    }
            
    string Cowboy::print() const 
    {    
        string name = this->getName();
        string hitPointing = to_string(this->getHitPoint());
        string locations =  this->getLocation().print();
        if (isAlive() == true){
            return " C " + name + ", his HitPoints: " + hitPointing + ", his Location: " + locations;
        }
		return " C (" + name + "), his Location: " + locations;

    }
}
