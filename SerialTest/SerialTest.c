
#include "simpletools.h"                      // Include simpletools header
#include "fdserial.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200


int main()                                    // main function
{
  simpleterm_close(); //close default terminal, I want to use those pins
  fdserial *wireless = fdserial_open(RX_PIN, TX_PIN, 0, BAUD); //this will go to the bluetooth module eventually
  
  int t = 0;
  while(scan("%d",&t)==0){} //wait for serial input
  
  int n = 0;
  while(1)                                    
  {
    int i = n;
    //printi("%d %d %d\n",i,i>>8,(char) i);
    writeChar(wireless, (char)(i>>24));
    writeChar(wireless, (char)(i>>16));
    writeChar(wireless, (char)(i>>8));
    writeChar(wireless, (char)i);
    n++; 
    pause(2);
  }
}