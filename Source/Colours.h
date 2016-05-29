//
//  Colours.hpp
//  Desktop-Weather
//
//  Created by Pete Haddrell on 29/05/2016.
//
//

#ifndef Colours_h
#define Colours_h

#include "JuceHeader.h"

class AppColours
{
public:
    AppColours() {}
    ~AppColours() {}
    
    //takes in time of day
    void setBackground (int tod);
    
private:
    ColourSelector background;
};

#endif /* Colours_h */
