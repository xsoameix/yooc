#include <stdio.h>
#include <string.h>
#include "o_string.h"

#define o_class OString
#define o_class_type o_class_string_t
#define o_instance_type o_string_t

o_class_type o_class;

static o_instance_type *
o_string_method_new(char * value) {
  o_init_instance(value);
}

static void
o_string_method_initialize(o_instance_type * self, char * value) {
  o_class.super->initialize((void *) self);
  self->string = value;
}

static char *
o_string_method_string(o_instance_type * self) {
  return self->string;
}

static size_t
o_string_method_len(o_instance_type * self) {
  return strlen(self->string);
}

void
o_init_string_class(void) {
  o_init_object_class();
  o_define_superclass(OObject);
  o_define_method(new,        o_string_method_new);
  o_define_method(initialize, o_string_method_initialize);
  o_define_method(string,     o_string_method_string);
  o_define_method(len,        o_string_method_len);
}
