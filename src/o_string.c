#include <stdio.h>
#include <string.h>
#include "o_string.h"

#define o_class_type o_class_string_t
#define o_instance_type o_string_t

o_class_type OString;

static void *
o_string_method_new(o_class_type * class, char * value) {
  o_string_t * string = (void *) class->super->new((void *) class);
  string->string = value;
  return string;
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
  o_define_superclass(OString, OObject);
  o_define_method(OString, new,        o_string_method_new);
  o_define_method(OString, string,     o_string_method_string);
  o_define_method(OString, len,        o_string_method_len);
}
