#ifndef MY_OLDNINJA
#define MY_OLDNINJA

#include "Ninja.hpp"

using namespace std;

namespace ariel{

    const int speedOldNinja = 8;
    const int hitPointOfOldNinja = 150;

    class OldNinja: public Ninja
        { 
            public:
                OldNinja(const string& name,const Point &point);

        };
}

#endif