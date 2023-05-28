#ifndef MY_COWBOY
#define MY_COWBOY

#include "Character.hpp"

using namespace std;

namespace ariel{

    const int bools = 6;
    const int hiting = 110;

    class Cowboy: public Character
    {
        private:
            int amountOfBools;
        public:
            Cowboy(const string& name, const Point& Location);
            
            void shoot(Character *other);

            bool hasboolets() const;

            void reload();
            
            string print() const override;

    };
}
#endif