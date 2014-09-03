#ifndef INTERFACE_H
#define INTERFACE_H

#include "o_object.h"

typedef struct interface_shape interface_shape_t;
typedef union shape shape_t;

#define o_interface_shape_methods() \
  o_interface_variables(Shape); \
  size_t (* area)(shape_t * self)
#define o_interface_shape_of(instance) \
  ((interface_shape_t *) o_get_interface((void *) instance, &Shape))

struct interface_shape {
  o_interface_shape_methods();
};

extern void * Shape;

#endif
