//
//  Location.m
//  Desktop-Weather
//
//  Created by Pete Haddrell on 24/05/2016.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#include "Location.h"


/** A class that uses Objective-C to use CoreLocation */
class LocationPeer
{
public:
    /** Constructor */
    LocationPeer()
    {
        // setup for CoreLocation
        locationManager = [[CLLocationManager alloc] init];
        locationManager.distanceFilter = kCLDistanceFilterNone;
        locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters;
        
        // does a permission check to see if the user has allowed the app to use location data
        if ([locationManager respondsToSelector:@selector(requestWhenInUseAuthorization)])
        {
            [locationManager requestWhenInUseAuthorization];
        }
        
        [locationManager startUpdatingLocation];
    }
    
    ~LocationPeer()
    {
        [locationManager stopUpdatingLocation];
    }
    
    CLLocationManager *locationManager;
};


Location::Location()
:   peer (new LocationPeer())
{}

Location::~Location()
{
    
}

Point<double> Location::getCoordinate()
{
    CLLocationCoordinate2D coordinate = peer->locationManager.location.coordinate;
    std::cout << "\n" << coordinate.latitude << coordinate.longitude << "\n";
    return Point<double> (coordinate.latitude, coordinate.longitude);
}
