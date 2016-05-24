//
//  Location.h
//  Desktop-Weather
//
//  Created by Pete Haddrell on 24/05/2016.
//
//

#ifndef Location_h
#define Location_h

#include "JuceHeader.h"

class LocationPeer;

/** A class that collects location information from Location Peer */
class Location
{
public:
    /** Constructor */
    Location();
    
    /** Destructor */
    ~Location();
    
    /** Retrives coordinates */
    Point<double> getCoordinate();
    
private:
    ScopedPointer<LocationPeer> peer;   // allows data to be communicated from the objective-c framework
};

#endif /* Location_h */
