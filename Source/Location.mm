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
        locationManager = [[CLLocationManager alloc] init];
        locationManager.distanceFilter = kCLDistanceFilterNone;
        locationManager.desiredAccuracy = kCLLocationAccuracyHundredMeters;
        
        if (! [CLLocationManager locationServicesEnabled])
        {
            std::cout << "Not enabled\n";
        }
        else if ([CLLocationManager locationServicesEnabled])
        {
            std::cout << "Enabled\n";
        }
        
        [locationManager startUpdatingLocation];
    }
    
    ~LocationPeer()
    {
        [locationManager stopUpdatingLocation];
    }
    
    void updateLocation()
    {
        if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusNotDetermined)
        {
            std::cout << "Not\n";
            [locationManager startUpdatingLocation];
            [locationManager stopUpdatingLocation];
        }
        else if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusRestricted)
        {
            std::cout << "Restrict\n";
        }
        else if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusAuthorized)
        {
            std::cout << "Auth\n";
            [locationManager startUpdatingLocation];
        }
        else if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusDenied)
        {
            std::cout << "Denied\n";
        }
    }
    
    CLLocationCoordinate2D returnLocation()
    {
        return locationManager.location.coordinate;
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
    peer->updateLocation();
    CLLocationCoordinate2D coordinate = peer->returnLocation();
    return Point<double> (coordinate.latitude, coordinate.longitude);
}
