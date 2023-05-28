#ifndef MY_TRAINEDNINJA
#define MY_TRAINEDNINJA

#include "Ninja.hpp"

using namespace std;

namespace ariel{
    const int speedTrainedNinja =12;
    const int hitPointOfTrainedNinja = 120;

    class TrainedNinja: public Ninja
    {
        public:
            TrainedNinja(const string& name,const Point& point);            
    };

}
#endif