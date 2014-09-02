#ifndef O_OBJECT_H
#define O_OBJECT_H

#include <stddef.h>

typedef struct o_class_object o_class_object_t;
typedef struct o_object o_object_t;

#define o_class_object_super(super_class_type) \
  super_class_type * super
#define o_class_object_variables() \
  char * name; \
  size_t size; \
  size_t instance_size
#define o_class_object_new(class_type, instance_type, ...) \
  instance_type * (* new)       (class_type * class, ##__VA_ARGS__)
#define o_class_object_methods(class_type, instance_type) \
  void            (* delete)    (instance_type * self); \
  class_type *    (* class)     (instance_type * self); \
  char *          (* class_name)(instance_type * self)

struct o_class_object {
  o_class_object_super(o_class_object_t);
  o_class_object_variables();
  o_class_object_new(o_class_object_t, o_object_t);
  o_class_object_methods(o_class_object_t, o_object_t);
};

extern o_class_object_t OObject;

#define o_object_instance_variables(class_type) \
  class_type * class

struct o_object {
  o_object_instance_variables(o_class_object_t);
};

typedef struct o_method {
  size_t offset;
  void * ptr;
} o_method_t;

void o_init_class(o_class_object_t * class, o_class_object_t * super, char * class_name, size_t class_size, size_t instance_size, size_t methods_len, o_method_t * methods);
void o_init_object_class(void);

#endif
