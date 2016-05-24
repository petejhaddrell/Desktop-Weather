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
    latitude = location.getCoordinate().x;
    longitude = location.getCoordinate().y;
    
    String lat (latitude);
    String longit (longitude);
    
    //api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}
    String urlStr ("api.openweathermap.org/");
    urlStr += key.getKey();
    urlStr += "/2.5/weather?lat=";
    urlStr += lat;
    urlStr += "&lon=";
    urlStr += longit;
    
//    std::cout << urlStr << "\n";
}