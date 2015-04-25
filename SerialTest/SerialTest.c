
#include "simpletools.h"                      // Include simpletools header
#include "fdserial.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200



int main()                                    // main function
{
  simpleterm_close(); //close default terminal, I want to use those pins
  fdserial *wireless = fdserial_open(RX_PIN, TX_PIN, 0, BAUD); //this will go to the bluetooth module eventually
  
  fdserial_rxChar(wireless);
  
  int n = 0;
  while(1)                                    
  {
    int i = n;
    writeChar(wireless, (char)i); //little endian
    writeChar(wireless, (char)(i>>8));
    writeChar(wireless, (char)(i>>16));
    writeChar(wireless, (char)(i>>24));
    n+=10000; 
    pause(2);
  }
}