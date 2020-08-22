#include <ti/sysbios/knl/Queue.h>

typedef struct SensorDataFrame {
      Queue_Elem _elem;
      uint8_t data[30];
  } SensorDataFrame;
