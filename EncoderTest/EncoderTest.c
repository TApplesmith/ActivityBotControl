
#include "simpletools.h"                      // Include simpletools header
#include "ping.h"                             // Include ping header
#include "abdrive.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200

#define PING_PIN 8

#define MAX_SPEED 0

int main()                                    // main function
{
  simpleterm_reopen(RX_PIN, TX_PIN, 0, BAUD);
  //drive_open();
  //drive_goto(0,0);
  //drive_setMaxSpeed(MAX_SPEED);
  int l=1;
  int r=1;

  drive_speed(-10,-10);
  pause(1000);
    drive_speed(0,0);
  while(1)                                    // Repeat indefinitely
  {
    for(int i = 0; i < 100; i++) 
    {
      drive_getTicks(&l,&r); //only works when actually moving, otherwise no response
      int ultrasonic = ping(PING_PIN);
      //print("ultrasonic %d uS\n",ultrasonic);
      print("%d %d\n", l, r);
      pause(50);
    }    
  }
}