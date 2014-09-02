#ifndef O_OBJECT_H
#define O_OBJECT_H

#include <stddef.h>

#define o_define_superclass(class_name, superclass_name) \
  o_init_class((void *) &class_name, (void *) &superclass_name, #class_name, \
          sizeof(o_class_type), sizeof(o_instance_type))
#define o_define_method(class_name, method_name, func_name) \
  o_method_t method_name ## _method = \
    {offsetof(o_class_type, method_name), func_name}; \
  o_init_method((void *) &class_name, &method_name ## _method)

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
  o_instance_type * (* new)       (o_class_type * class, ##__VA_ARGS__)
#define o_class_object_methods() \
  void              (* delete)    (o_instance_type * self); \
  o_class_type *    (* class)     (o_instance_type * self); \
  char *            (* class_name)(o_instance_type * self)

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

void o_init_class(o_class_type * class, o_class_type * super, char * class_name,
        size_t class_size, size_t instance_size);
void o_init_method(o_class_type * class, o_method_t * method);
void o_init_object_class(void);

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type

#endif
