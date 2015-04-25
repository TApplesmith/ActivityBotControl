
#include "simpletools.h"                      // Include simpletools header
#include "fdserial.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200

void sendInt32(fdserial* connection, int i)
{
  writeChar(connection, (char)i); //little endian
  writeChar(connection, (char)(i>>8));
  writeChar(connection, (char)(i>>16));
  writeChar(connection, (char)(i>>24));
}    

int main()
{
  simpleterm_close(); //close default terminal, I want to use those pins
  fdserial *wireless = fdserial_open(RX_PIN, TX_PIN, 0, BAUD); //this will go to the bluetooth module eventually
  
  fdserial_rxChar(wireless);
  
  int n = 0;
  while(1)                                    
  {
    int i = n;
    sendInt32(wireless, n);
    n+=10000; 
    pause(2);
  }
}