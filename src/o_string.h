#ifndef O_STRING_H
#define O_STRING_H

#include "o_object.h"

typedef struct o_class_string o_class_string_t;
typedef struct o_string o_string_t;

#define o_class_string_new(class_type, instance_type, ...) \
  o_class_object_new(class_type, instance_type, ##__VA_ARGS__)
#define o_class_string_methods(class_type, instance_type) \
  o_class_object_methods(class_type, instance_type); \
  char * (* string)(instance_type * self); \
  size_t (* len)   (instance_type * self)

struct o_class_string {
  o_class_object_super(o_class_object_t);
  o_class_object_variables();
  o_class_string_new(o_class_string_t, o_string_t, char * value);
  o_class_string_methods(o_class_string_t, o_string_t);
};

extern o_class_string_t OString;

#define o_string_instance_variables(class_type) \
  o_object_instance_variables(class_type); \
  char * string

struct o_string {
  o_string_instance_variables(o_class_string_t);
};

void o_init_string_class(void);

#endif
