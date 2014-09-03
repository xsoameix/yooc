#ifndef INTERFACE_INSTANCE_H
#define INTERFACE_INSTANCE_H

#include "implementations.h"

union shape {
  struct rectangle rectangle;
  struct square square;
};

#endif
