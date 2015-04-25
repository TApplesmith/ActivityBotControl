
#include "fdserial.h"
#include "serialcom.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200


int main()
{
  simpleterm_close(); //close default terminal, I want to use those pins
                      //if the default uart pins are not used, this isn't needed
                      
  startComs(RX_PIN, TX_PIN, BAUD); //this will go to the bluetooth module eventually
  
  rxCharblock(); //wait for a control byte
  
  int n = 0;
  while(1)                                    
  {
    int i = n;
    sendInt32(n); //sending incrementing numbers
    n+=10000; 
    //the computer can sometimes miss bytes 
    //when the bytes are coming really fast 
    //for an extended period of time
  }
}
