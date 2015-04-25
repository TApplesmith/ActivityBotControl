
#include "serialcom.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200


int main()
{
  simpleterm_close(); //close default terminal, I want to use those pins
                      //if the default uart pins are not used, this isn't needed
                      
  startComs(RX_PIN, TX_PIN, BAUD, 1000); //this will go to the bluetooth module eventually
  
  
  int n = 0;
  while(1)                                    
  {
    
    rxCommand(); //wait for a control byte
    sendInt32(n); //sending incrementing numbers
    n+=10000; 
    //Note: The computer can sometimes miss bytes 
    //when the bytes are coming really fast 
  }
}
