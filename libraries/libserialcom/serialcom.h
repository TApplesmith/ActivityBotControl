
#include "fdserial.h"

void startComs(int rxpin, int txpin, int baudrate, int timeout);

void txInt32(int i);

int rxCommand();

int rxInt32();