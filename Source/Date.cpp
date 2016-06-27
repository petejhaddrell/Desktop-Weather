//
//  Date.cpp
//  Desktop-Weather
//
//  Created by Pete Haddrell on 29/05/2016.
//
//

#include "Date.h"

Date::Date() :  timeNode (0.0),
                dateNode (0.0)
{}

int Date::getHours()
{
    return time.getHours();
}

int Date::getDayOfMonth()
{
    return time.getDayOfYear();
}

int Date::getMonthOfYear()
{
    return time.getMonth();
}

void Date::setTimeNode()
{
    timeNode =  getHours() * 0.043;
}

void Date::setDateNode()
{
    dateNode = (getDayOfMonth() * 0.032) * (getMonthOfYear() * 0.09);
}