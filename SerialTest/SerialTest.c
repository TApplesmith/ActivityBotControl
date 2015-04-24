
#include "simpletools.h"                      // Include simpletools header


#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200


int main()                                    // main function
{
  simpleterm_reopen(RX_PIN, TX_PIN, 0, BAUD);
  
  while(1)                                    // Repeat indefinitely
  {
    for(int i = 0; i < 255; i++) 
    {
      //print("%d\n", i);
      putChar(1000);
      pause(50);
    }    
  }
}