#include <stdlib.h>
#include <string.h>
#include "o_object.h"

#define o_class OObject
#define o_class_type o_class_object_t
#define o_instance_type o_object_t

o_class_type o_class;

static o_instance_type *
o_object_method_new(void) {
  o_init_instance();
}

static void
o_object_method_initialize(o_instance_type * self) {
}

static void
o_object_method_delete(o_instance_type * self) {
  free(self);
}

static o_class_type *
o_object_method_class(o_instance_type * self) {
  return self->class;
}

static char *
o_object_method_class_name(o_instance_type * self) {
  return self->class->name;
}

static bool
o_object_method_is_a(o_instance_type * self, o_class_type * class) {
  o_class_type * klass = self->class;
  while (klass != NULL) {
    if (klass == class) return true;
    klass = klass->super;
  }
  return false;
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

void *
o_get_interface(o_instance_type * instance, void * interface) {
  size_t offset = offsetof(o_class_type, new);
  size_t methods_len = (instance->class->size - offset) / sizeof(void *);
  void ** methods = (void *) instance->class + offset;
  for (size_t i = 0; i < methods_len; i++) {
    if (methods[i] == interface) return &methods[i];
  }
  return NULL;
}

void
o_init_object_class(void) {
  o_init_class(&o_class, NULL, "OObject",
               sizeof(o_class_type), sizeof(o_instance_type));
  o_define_method(new,        o_object_method_new);
  o_define_method(initialize, o_object_method_initialize);
  o_define_method(delete,     o_object_method_delete);
  o_define_method(class,      o_object_method_class);
  o_define_method(class_name, o_object_method_class_name);
  o_define_method(is_a,       o_object_method_is_a);
}
