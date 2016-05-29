//
//  Date.hpp
//  Desktop-Weather
//
//  Created by Pete Haddrell on 29/05/2016.
//
//

#ifndef Date_h
#define Date_h

#include "JuceHeader.h"

class Date
{
public:
    Date() {};
    ~Date() {};
    int getHours();
    
private:
    Time time;
};

#endif /* Date_h */
