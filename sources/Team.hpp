#ifndef MY_TEAM
#define MY_TEAM

#include <vector>

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"


using namespace std;

namespace ariel{

    class Team
    {
        
        const double Max = numeric_limits<double>::max();

        private:
            vector<Character *> team;
            Character *commander;
    

            static void cheackBelongsToTeam(Character* character){
                    if (character->belongsToTeam()){
                    throw runtime_error("not possible to put the same player in two different teams or two times in same team");           
                }
            }

        protected:
            static void cheackNullPointer(void* character){
                    if (character == nullptr){
                    throw invalid_argument("the pointer is null!");            
                }
            }
            void attackOfCowboys(Team* teamOfChar, Character *victim);
            void attackOfNinjas(Team* teamOfChar, Character *victim);

        public:

            Team(Character *commander);
            Team(const Team& other) = default;
            Team& operator=(const Team& other){

                if (this == &other) {
                    return *this;
                }

                for (auto& member : team) {
                    delete member;
                }
                
                team.clear();

                commander = other.commander;

                for (const auto& member : other.team) {
                    if (const auto *cowboy = dynamic_cast<const Cowboy*>(member)) {
                        team.push_back(new Cowboy(*cowboy));
                    } else if (const auto *ninja = dynamic_cast<const Ninja*>(member)) {
                        team.push_back(new Ninja(*ninja));
                    }
                }

                return *this;
            }
            Team(Team&& other) = default;
            Team& operator=(Team&& other) noexcept
            {  
                if (this == &other) {
                    return *this;
                }

                for (auto it = team.begin(); it != team.end(); ++it) {
                    delete *it;
                }


                team.clear();


                commander = other.commander;
                team = move(other.team);


                other.commander = nullptr;
                other.team.clear();

                return *this;
            }

            virtual ~Team();
    
            Team():commander(nullptr){

            }
    
            virtual Character *findSolider(Team *other) const;

            void add(Character* Character);
            int stillAlive() const;
            virtual void attack(Team *other);
			virtual void print() const;
            const std::vector<Character*>& getTeam() const;
            Character* getCommander() const;
            void setCommander(Character *leader);
            int getSizeOfAllTeam() const;
        };
}
#endif