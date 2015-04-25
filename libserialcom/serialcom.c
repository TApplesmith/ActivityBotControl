
#include "serialcom.h"

fdserial *conn;

void startComs(int rxpin, int txpin, int baudrate)
{
  conn = fdserial_open(rxpin, txpin, 0, baudrate);
}

void sendInt32(int i) //sends in little endian
{
  for(int j = 0; j < 4; j++)
  {
    writeChar(conn, (char) (i>>(8*j)) );    //cast to char truncates int from 32 bits to 8 bits
  }                               //bitshifting before cast gets 4 bytes with the same bits as the int
}

char rxCharblock()
{
  return fdserial_rxChar(conn);
}