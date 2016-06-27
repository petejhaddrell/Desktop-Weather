//
//  Date.hpp
//  Desktop-Weather
//
//  Created by Pete Haddrell on 29/05/2016.
//
//

#ifndef Date_h
#define Date_h

#include "JuceHeader.h"

/** Class to get the time and date information and then scale it to node values */
class Date
{
public:
    /** Constructor */
    Date();
    
    /** Destructor */
    ~Date() {};
    
    /** Retrieves the hours of the day */
    int getHours();
    
    /** Retrieves the day of the month */
    int getDayOfMonth();
    
    /** Retrieves the month of the year */
    int getMonthOfYear();
    
    /** Mutator to set the value of the timeNode */
    void setTimeNode();
    
    /** Mutator to set the value of the dateNode */
    void setDateNode();
    
    /** Accessor to retrieve the value of the timeNode */
    double getTimeNode() { return timeNode; };
    
    /** Accessor to retrieve the value of the dateNode */
    double getDateNode() { return dateNode; };
    
private:
    Time time;
    double timeNode;
    double dateNode;
};

#endif /* Date_h */
