#ifndef MY_TEAM2
#define MY_TEAM2
#include "Team.hpp"

using namespace std;

namespace ariel{        
        
    class Team2: public Team
        {
            public:
                Team2(Character* commander);
                void attack(Team *other) override;
                void print() const override;
        };
}
#endif