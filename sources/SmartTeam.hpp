#ifndef MY_SMARTTRAM
#define MY_SMARTTRAM

#include "Team.hpp"

using namespace std;

namespace ariel{


    class SmartTeam: public Team
    { 
        public:
            SmartTeam(Character *chief);
            void attack(Team *other) override;
            void print() const override;
    };
}

#endif