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
    /** Constructor */
    Weather();
    
    /** Destructor */
    ~Weather() {};
    
    /** Launches the functions to connect to the api and set the mutators */
    void connect();
    
    /** Searches the stream recieved from the api */
    int searchStream (String weatherStream, String searchTerm, const int searchOffset, const int digitCount, String returnType);
    
    /** Mutator to set the value for the weatherNode */
    void setWeatherNode (const int weatherVal);
    
    /** Mutator to set the value for the tempNode */
    void setTempNode (const float tempVal);
    
    /** Accesor to get the value of weatherNode */
    double getWeatherNode() { return weatherNode; };
    
    /**  Accessor to get the value of the tempNode */
    double getTempNode() { return tempNode; };
    
private:
    APIKey key;
    double longitude;
    double latitude;
    Location location;
    double weatherNode;
    double tempNode;
};


#endif  // WEATHER_H_INCLUDED
