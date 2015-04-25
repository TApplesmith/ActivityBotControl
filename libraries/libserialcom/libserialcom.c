
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
    
    switch(rxCommand()) //wait for a control byte
    {
      case 'a':
        sendInt32(n); //sending incrementing numbers
        n+=10000; 
        break;
        
      case '?':
        sendInt32(42);
        break;
        
      case -1:    //case when timed out
        sendInt32(314);
        break;
        
      default:    //unknown command
        sendInt32(2718);
    }        
    
    //Note: The computer can sometimes miss bytes 
    //when the bytes are coming really fast 
  }
}
