//sensor.h
//get ping [over microseconds]
#include "simpletools.h"
#include "ping.h" // Include ping header

#define PINGPIN 8 //Ping in pin 8

int getPing();
{
  return ping(PINGPIN); // return microseconds distance from ping sensor
}

// ARCHIVED
// probably going to be incorporated into wander in order
// to avoid error due to movement