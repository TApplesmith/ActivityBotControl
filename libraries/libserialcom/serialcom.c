
#include "serialcom.h"

static fdserial *conn;
static int tout = 1000;

void startComs(int rxpin, int txpin, int baudrate, int timeout)
{
  conn = fdserial_open(rxpin, txpin, 0, baudrate);
  tout = timeout;
}

void sendInt32(int i) //sends in little endian
{
  for(int j = 0; j < 4; j++)
  {
    writeChar(conn, (char) (i>>(8*j)) );    //cast to char truncates int from 32 bits to 8 bits
  }                               //bitshifting before cast gets 4 bytes with the same bits as the int
}

int rxCommand()
{
  return fdserial_rxTime(conn, tout);
}