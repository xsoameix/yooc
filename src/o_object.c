#include <stdlib.h>
#include <string.h>
#include "o_object.h"

#define o_class_type o_class_object_t
#define o_instance_type o_object_t

o_class_type OObject;

static void *
o_object_method_new(o_class_type * class) {
  o_object_t * instance = malloc(class->instance_size);
  instance->class = class;
  return instance;
}

static void
o_object_method_delete(o_instance_type * self) {
  free(self);
}

static o_class_object_t *
o_object_method_class(o_instance_type * self) {
  return self->class;
}

static char *
o_object_method_class_name(o_instance_type * self) {
  return self->class->name;
}

void
o_init_class(o_class_type * class, o_class_type * super, char * class_name,
             size_t class_size, size_t instance_size) {
  if (class->size != 0) return;
  class->super = super;
  class->name = class_name;
  class->size = class_size;
  class->instance_size = instance_size;
  // inherit
  size_t offset = offsetof(o_class_type, new);
  if (class != &OObject) {
    memcpy((char *) class + offset,
           (char *) class->super + offset,
           class->super->size - offset);
  }
}

void
o_init_method(o_class_type * class, o_method_t * method) {
  // override
  void ** class_methods = (void *) class + method->offset;
  * class_methods = method->ptr;
}

void
o_init_object_class(void) {
  o_init_class(&OObject, NULL, "Object",
               sizeof(o_class_type), sizeof(o_instance_type));
  o_define_method(OObject, new,        o_object_method_new);
  o_define_method(OObject, delete,     o_object_method_delete);
  o_define_method(OObject, class,      o_object_method_class);
  o_define_method(OObject, class_name, o_object_method_class_name);
}
