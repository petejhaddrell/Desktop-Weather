/*
  ==============================================================================

    Weather.h
    Created: 24 May 2016 11:02:25am
    Author:  Pete Haddrell

  ==============================================================================
*/

#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#include "../../APIKey/APIKey.h"

class Weather
{
public:
    Weather();
    ~Weather();
    
    void connect();
    
private:
    APIKey key;
};




#endif  // WEATHER_H_INCLUDED
