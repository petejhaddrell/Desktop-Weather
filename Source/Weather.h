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
#include "Location.h"

class Weather
{
public:
    Weather();
    ~Weather();
    
    void connect();
    int searchWeatherValue (String weatherStream, String searchTerm, const int searchOffset, const int digitCount);
    int setWeatherState (const int weatherVal);
    
private:
    APIKey key;
    double longitude;
    double latitude;
    Location location;
};




#endif  // WEATHER_H_INCLUDED
