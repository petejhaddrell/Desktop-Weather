/*
  ==============================================================================

    Weather.cpp
    Created: 24 May 2016 11:02:25am
    Author:  Pete Haddrell

  ==============================================================================
*/

#include "Weather.h"

Weather::Weather() :    weatherNode (0.0),
                        tempNode (0.0)
{}


int Weather::searchStream (String weatherStream, String searchTerm, const int searchOffset, const int digitCount, String returnType)
{
    int search = weatherStream.indexOf(searchTerm);
    search += searchOffset;
    String code = weatherStream.substring (search, search + digitCount);
    
    if (returnType == "float")
        return code.getFloatValue();
    else
        return code.getIntValue();
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
    urlStr += key.getKey(); //api key is stored seperately to prevent fraudulent use
    
    URL url (urlStr);
    String textStream = juce::JSON::toString (url.readEntireTextStream(), true);
    setWeatherNode (searchStream (textStream, "id", 5, 3, "int"));
    setTempNode (searchStream (textStream, "temp", 7, 6, "float"));
    
    //debugging
//    std::cout << urlStr << "\n";
//    std::cout << textStream << std::endl;
    std::cout <<  weatherNode << std::endl;
}


void Weather::setWeatherNode (const int weatherVal)
{
    double weatherMultiplier = 0.0;
    
    //Thunderstorm
    if ((weatherVal - 200) < 100)
    {
        std::cout << "200's" << std::endl;
        switch (weatherVal)
        {
            case 200: //thunderstorm with light rain
                
                break;
            
            case 201: //thunderstorm with rain
                break;
                
            case 202: //thunderstorm with heavy rain
                break;
            
            case 210: //light thunderstorm
                break;
                
            case 211: //thunderstorm
                break;
                
            case 212: //heavy thunderstorm
                break;
                
            case 221: //ragged thunderstorm
                break;
                
            case 230: //thunderstorm with light drizzle
                break;
                
            case 231: //thunderstorm with drizzle
                break;
                
            case 232: //thunderstorm with heavy drizzle
                break;
                
            default:
                break;
        }
    }
    //Drizzle
    else if ((weatherVal - 300) < 100)
    {
        std::cout << "300's" << std::endl;
        switch (weatherVal)
        {
            case 300: //light intensity drizzle
                break;
                
            case 301: //drizzle
                break;
                
            case 302: //heavy intensity drizzle
                break;
                
            case 310: //light intensity drizzle rain
                break;
                
            case 311: //drizzle rain
                break;
                
            case 312: //heavy intensity drizzle rain
                break;
                
            case 313: //shower rain and drizzle
                break;
                
            case 314: //heavy shower rain and drizzle
                break;
                
            case 321: //shower drizzle
                break;
                
            default:
                break;
        }
    }
    //Rain
    else if ((weatherVal - 500) < 100)
    {
        std::cout << "500's" << std::endl;
        switch (weatherVal)
        {
            case 500: //light rain
                break;
                
            case 501: //moderate rain
                break;
                
            case 502: //heavy intensity rain
                break;
                
            case 503: //very heavy rain
                break;
                
            case 504: //extreme rain
                break;
                
            case 511: //freezing rain
                break;
                
            case 520: //light intensity shower rain
                break;
                
            case 521: //shower rain
                break;
                
            case 522: //heavy intensity shower rain
                break;
                
            case 531: //ragged shower rain
                break;
                
            default:
                break;
        }
        
    }
    //Snow
    else if ((weatherVal - 600) < 100)
    {
        std::cout << "600's" << std::endl;
        
        switch (weatherVal)
        {
            case 600: //light snow
                break;
                
            case 601: //snow
                break;
                
            case 602: //heavy snow
                break;
                
            case 611: //sleet
                break;
                
            case 612: //shower sleet
                break;
                
            case 615: //light rain and snow
                break;
                
            case 616: //rain and snow
                break;
                
            case 620: //light shower snow
                break;
                
            case 621: //shower snow
                break;
                
            case 622: //heavy shower snow
                break;
                
            default:
                break;
        }
    }
    //Atmosphere
    else if ((weatherVal - 700) < 100)
    {
        std::cout << "700's" << std::endl;
        switch (weatherVal)
        {
            case 701: //mist
                break;
                
            case 711: //smoke
                break;
                
            case 721: //haze
                break;
                
            case 731: //sand,dust whirls
                break;
                
            case 741: //fog
                break;
                
            case 751: //sand
                break;
                
            case 761: //dust
                break;
                
            case 762: //volcanic ash
                break;
                
            case 771: //squalls
                break;
                
            case 781: //tornado
                break;
                
            default:
                break;
        }
    }
    //Clear/Clouds
    else if ((weatherVal - 800) < 100)
    {
        std::cout << "800's" << std::endl;
        switch (weatherVal)
        {
            case 800: //clear sky
                break;
               
            case 801: //few clouds
                break;
                
            case 802: //scattered clouds
                break;
                
            case 803: //broken clouds
                break;
                
            case 804: //overcast clouds
                break;
                
            default:
                break;
        }
    }
    //Extreme/Aditional
    else if ((weatherVal - 900) < 100)
    {
        std::cout << "900's" << std::endl;
        switch (weatherVal)
        {
            case 900: //tornado
                break;
                
            case 901: //tropical storm
                break;
                
            case 902: //hurricane
                break;
                
            case 903: //cold
                break;
                
            case 904: //hot
                break;
                
            case 905: //windy
                break;
                
            case 906: //hail
                break;
                
            case 951: //calm
                break;
                
            case 952: //light breeze
                break;
                
            case 953: //gentle breeze
                break;
                
            case 954: //moderate breeze
                break;
                
            case 955: //fresh breeze
                break;
                
            case 956: //strong breeze
                break;
                
            case 957: //high wind, near gale
                break;
                
            case 958: //gale
                break;
                
            case 959: //severe gale
                break;
                
            case 960: //storm
                break;
                
            case 961: //violent storm
                break;
                
            case 962: //hurricane
                break;
                
            default:
                break;
        }
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    
    weatherNode = weatherVal * weatherMultiplier; //needs to be assigned to correct value
}


void Weather::setTempNode (const float tempVal)
{
    float celsius = tempVal - 273.15; //converts kelvin to celsius
    
    if (tempVal < 250)
    {
        tempNode = 0.0;
    }
    else if (tempVal > 310)
    {
        tempNode = 1.0;
    }
    else
    {
        tempNode = (tempVal - 250) * 0.0166; //scales it to the range 0 to 0.996
    }
    
    std::cout <<  "celsius: " << celsius << std::endl;
}