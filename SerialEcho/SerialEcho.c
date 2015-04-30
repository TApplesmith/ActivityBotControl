
#include "fdserial.h"

#define RX_PIN 11//31//11
#define TX_PIN 10//30//10
#define BAUD 9600


int main()
{
  //simpleterm_close(); //close default terminal, I want to use those pins
                      //if the default uart pins are not b nused, this isn't needed
                      
  fdserial *d = fdserial_open(RX_PIN, TX_PIN,0, BAUD);
  
  while(1)                                    
  {
     fdserial_txChar(d, fdserial_rxChar(d));
  }
}
