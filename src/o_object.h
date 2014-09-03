#ifndef O_OBJECT_H
#define O_OBJECT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define o_init_instance(...) \
  o_instance_type * instance = malloc(o_class.instance_size); \
  instance->class = &o_class; \
  o_class.initialize(instance, ##__VA_ARGS__); \
  return instance
#define o_wrong_class(instance) \
  (!o_class.is_a(instance, &o_class))
#define o_lookup_method(method_name, ...) \
  if (o_class.class(self) != &o_class) return self->class->method_name(__VA_ARGS__)
#define o_define_superclass(superclass_name) \
  o_define_superclass_(o_class, superclass_name)
#define o_define_superclass_(class_name, superclass_name) \
  o_define_superclass__(class_name, superclass_name)
#define o_define_superclass__(class_name, superclass_name) \
  o_init_class((void *) &class_name, (void *) &superclass_name, #class_name, \
               sizeof(o_class_type), sizeof(o_instance_type))
#define o_implements(interface_name) \
  o_class.interface_ ## interface_name = &interface_name
#define o_define_method(method_name, func_name) \
  o_class.method_name = func_name;

#define o_super_class_type o_class_object_t
#define o_class_type o_class_object_t
#define o_instance_type o_object_t

typedef struct o_class_object o_class_type;
typedef struct o_object o_instance_type;

#define o_class_object_variables() \
  o_super_class_type * super; \
  char * name; \
  size_t size; \
  size_t instance_size
#define o_class_object_new(...) \
  o_instance_type * (* new)       (__VA_ARGS__); \
  void              (* initialize)(o_instance_type * self, ##__VA_ARGS__)
#define o_class_object_methods() \
  void              (* delete)    (o_instance_type * self); \
  o_class_type *    (* class)     (o_instance_type * self); \
  char *            (* class_name)(o_instance_type * self); \
  bool              (* is_a)      (o_instance_type * self, o_class_type * class)
#define o_interface_variables(interface_name) \
  o_interface_variables_(interface_name)
#define o_interface_variables_(interface_name) \
  void * interface_ ## interface_name

struct o_class_object {
  o_class_object_variables();
  o_class_object_new();
  o_class_object_methods();
};

extern o_class_type OObject;

#define o_object_instance_variables() \
  o_class_type * class

struct o_object {
  o_object_instance_variables();
};

typedef struct o_method {
  size_t offset;
  void * ptr;
} o_method_t;

void   o_init_class(o_class_type * class, o_class_type * super,
        char * class_name, size_t class_size, size_t instance_size);
void   o_init_object_class(void);
void * o_get_interface(o_instance_type * instance, void * interface);

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type

#endif
