#include <stdlib.h>
#include <string.h>
#include "o_object.h"

o_class_object_t OObject;

static void *
o_object_method_new(o_class_object_t * class) {
  o_object_t * instance = malloc(class->instance_size);
  instance->class = class;
  return instance;
}

static void
o_object_method_delete(o_object_t * self) {
  free(self);
}

static o_class_object_t *
o_object_method_class(o_object_t * self) {
  return self->class;
}

static char *
o_object_method_class_name(o_object_t * self) {
  return self->class->name;
}

void
o_init_class(o_class_object_t * class, o_class_object_t * super, char * class_name, size_t class_size, size_t instance_size, size_t methods_len, o_method_t * methods) {
  if (class->size != 0) return;
  class->super = super;
  class->name = class_name;
  class->size = class_size;
  class->instance_size = instance_size;
  // inherit
  size_t offset = offsetof(o_class_object_t, new);
  if (class != &OObject) {
    memcpy((char *) class + offset,
           (char *) class->super + offset,
           class->super->size - offset);
  }
  // override
  for (size_t i = 0; i < methods_len; i++) {
    void ** class_methods = (void *) class + methods[i].offset;
    * class_methods = methods[i].ptr;
  }
}

void
o_init_object_class(void) {
  size_t class_size = sizeof(o_class_object_t);
  size_t instance_size = sizeof(o_object_t);
  o_method_t methods[] = {
    {offsetof(o_class_object_t, new),        o_object_method_new},
    {offsetof(o_class_object_t, delete),     o_object_method_delete},
    {offsetof(o_class_object_t, class),      o_object_method_class},
    {offsetof(o_class_object_t, class_name), o_object_method_class_name}
  };
  size_t methods_len = sizeof(methods) / sizeof(o_method_t);
  o_init_class(&OObject, NULL, "Object", class_size, instance_size, methods_len, methods);
}
