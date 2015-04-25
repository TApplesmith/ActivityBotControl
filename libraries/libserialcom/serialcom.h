
#include "fdserial.h"

void startComs(int rxpin, int txpin, int baudrate, int timeout);

void sendInt32(int i);

int rxCommand();