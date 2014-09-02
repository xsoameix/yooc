#ifndef O_STRING_H
#define O_STRING_H

#include "o_object.h"

#define o_super_class_type o_class_object_t
#define o_class_type o_class_string_t
#define o_instance_type o_string_t

typedef struct o_class_string o_class_type;
typedef struct o_string o_instance_type;

#define o_class_string_new(...) \
  o_class_object_new(__VA_ARGS__)
#define o_class_string_methods() \
  o_class_object_methods(); \
  char * (* string)(o_instance_type * self); \
  size_t (* len)   (o_instance_type * self)

struct o_class_string {
  o_class_object_variables();
  o_class_string_new(char * value);
  o_class_string_methods();
};

extern o_class_type OString;

#define o_string_instance_variables() \
  o_object_instance_variables(); \
  char * string

struct o_string {
  o_string_instance_variables();
};

void o_init_string_class(void);

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type

#endif
