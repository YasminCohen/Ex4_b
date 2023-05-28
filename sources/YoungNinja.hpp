#ifndef MY_YOUNGNINJA
#define MY_YOUNGNINJA

#include "Ninja.hpp"

using namespace std;

namespace ariel{
    
    const int SpeedYoungNinja = 14;
    const int hitPointOfYoungNinja = 100;

    class YoungNinja: public Ninja
        { 
            public:
                YoungNinja(const string& name ,const Point& point);
        };
}

#endif