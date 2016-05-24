/*
  ==============================================================================

    Weather.cpp
    Created: 24 May 2016 11:02:25am
    Author:  Pete Haddrell

  ==============================================================================
*/

#include "Weather.h"

Weather::Weather()
{
    
}

Weather::~Weather()
{
    
}

void Weather::connect()
{
    //api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}
    String urlStr ("api.openweathermap.org/");
    urlStr += key.getKey();
    urlStr += "/2.5/weather?lat=";
    //put lat
    urlStr += "&lon=";
    //put lon
}