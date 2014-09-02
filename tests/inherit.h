#ifndef INHERIT_H
#define INHERIT_H

#include "o_object.h"

typedef struct class_parent class_parent_t;
typedef struct parent parent_t;

#define class_parent_new(class_type, instance_type, ...) \
    o_class_object_new(class_type, instance_type, ##__VA_ARGS__)
#define class_parent_methods(class_type, instance_type) \
    o_class_object_methods(class_type, instance_type); \
    char * (* foo)(instance_type * self)

struct class_parent {
    o_class_object_super(o_class_object_t);
    o_class_object_variables();
    class_parent_new(class_parent_t, parent_t);
    class_parent_methods(class_parent_t, parent_t);
};

extern class_parent_t Parent;

typedef struct class_child class_child_t;
typedef struct child child_t;

#define class_child_new(class_type, instance_type, ...) \
    o_class_object_new(class_type, instance_type, ##__VA_ARGS__)
#define class_child_methods(class_type, instance_type) \
    o_class_object_methods(class_type, instance_type); \
    char * (* foo)(instance_type * self)

struct class_child {
    o_class_object_super(class_parent_t);
    o_class_object_variables();
    class_child_new(class_child_t, child_t);
    class_child_methods(class_child_t, child_t);
};

extern class_child_t Child;

#define parent_instance_variables(class_type) \
    o_object_instance_variables(class_type)

struct parent {
    parent_instance_variables(class_parent_t);
};

#define child_instance_variables(class_type) \
    o_object_instance_variables(class_type)

struct child {
    child_instance_variables(class_child_t);
};

#endif
