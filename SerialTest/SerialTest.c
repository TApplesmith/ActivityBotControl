
#include "simpletools.h"                      // Include simpletools header
#include "fdserial.h"

#define RX_PIN 31
#define TX_PIN 30
#define BAUD 115200

void sendInt32(fdserial* connection, int i) //sends in little endian
{
  writeChar(connection, (char)i);
  writeChar(connection, (char)(i>>8));    //cast to char truncates int from 32 bits to 8 bits
  writeChar(connection, (char)(i>>16));   //bitshifting before cast gets 4 bytes with the same bits as the int
  writeChar(connection, (char)(i>>24));
}    

int main()
{
  simpleterm_close(); //close default terminal, I want to use those pins
                      //if the default uart pins are not used, this isn't needed
                      
  fdserial *wireless = fdserial_open(RX_PIN, TX_PIN, 0, BAUD); //this will go to the bluetooth module eventually
  
  fdserial_rxChar(wireless); //wait for a control byte
  
  int n = 0;
  while(1)                                    
  {
    int i = n;
    sendInt32(wireless, n); //sending incrementing numbers
    n+=10000; 
    pause(2); //the computer can sometimes miss bytes 
            //when the bytes are coming really fast 
            //for an extended period of time
            
  }
}
