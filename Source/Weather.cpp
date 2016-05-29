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
   //off while permissions get sorted
//    latitude = location.getCoordinate().x;
//    longitude = location.getCoordinate().y;
    
    //hard set to london
    latitude = 51.5074;
    longitude = 0.1278;
    
    String lat (latitude);
    String longit (longitude);
    
    //api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}
    String urlStr = "http://api.openweathermap.org/data/2.5/weather?lat=";
    urlStr += lat;
    urlStr += "&lon=";
    urlStr += longit;
    urlStr += "&APPID=";
    urlStr += key.getKey();
    
    std::cout << urlStr << "\n";
    
    URL url (urlStr);
    String textStream = juce::JSON::toString (url.readEntireTextStream(), true);
    std::cout << textStream << std::endl;
}