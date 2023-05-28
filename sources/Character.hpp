#ifndef MY_CHARECTER
#define MY_CHARECTER

#include "Point.hpp"

using namespace std;

namespace ariel
{

    class Character
    {

        private:
            string nameOfCharacter;
            bool belongTOTeam;
            int hitPoint;
            Point Location;
        protected:
            static void cheackNullPointer(void* character){
                    if (character == nullptr){
                    throw invalid_argument("the pointer is null!");            
                }
            }

        public:
            Character(const string &name, const Point &Location, int hitPoint);
            virtual ~Character() {}
            Character(const Character& other) = default;
            Character& operator=(const Character& other) = default;
            Character(Character&& other) = default;
            Character& operator=(Character&& other) = default;
        
            bool isAlive() const;
            double distance(Character *charecter) const;
            void hit(int hitreduce);
            string getName() const;
            const Point& getLocation() const;
            virtual string print() const = 0;
            void setLocation(Point &other);
            int getHitPoint() const;
            bool belongsToTeam() const;
			void changeStatus();
    };
};
#endif