#ifndef MY_NINJA
#define MY_NINJA

#include "Character.hpp"

using namespace std;

namespace ariel{

    class Ninja: public Character
    {
        private:
            int speed;
        public:
            Ninja(const string& name, int speed,const Point& Location, int hitPoint);

            void move(Character* cowboy);
            void slash(Character* cowboy) const;
            string print() const override;
    };

}
#endif