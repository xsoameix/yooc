#include <stdio.h>
#include <string.h>
#include "o_string.h"

o_class_string_t OString;

static void *
o_string_method_new(o_class_string_t * class, char * value) {
  o_string_t * string = (void *) class->super->new((void *) class);
  string->string = value;
  return string;
}

static char *
o_string_method_string(o_string_t * self) {
  return self->string;
}

static size_t
o_string_method_len(o_string_t * self) {
  return strlen(self->string);
}

void
o_init_string_class(void) {
  o_init_object_class();
  size_t class_size = sizeof(o_class_string_t);
  size_t instance_size = sizeof(o_string_t);
  o_method_t methods[] = {
    {offsetof(o_class_object_t, new),        o_string_method_new},
    {offsetof(o_class_string_t, string),     o_string_method_string},
    {offsetof(o_class_string_t, len),        o_string_method_len}
  };
  size_t methods_len = sizeof(methods) / sizeof(o_method_t);
  o_init_class((void *) &OString, &OObject, "String", class_size, instance_size, methods_len, methods);
}
