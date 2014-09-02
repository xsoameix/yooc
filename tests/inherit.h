#ifndef INHERIT_H
#define INHERIT_H

#include "o_object.h"
#include "interface.h"

#define o_super_class_type o_class_object_t
#define o_class_type class_parent_t
#define o_instance_type parent_t

typedef struct class_parent o_class_type;
typedef struct parent o_instance_type;

#define class_parent_new(...) \
    o_class_object_new(__VA_ARGS__)
#define class_parent_methods() \
    o_class_object_methods(); \
    char * (* foo)(o_instance_type * self)

struct class_parent {
    o_class_object_variables();
    class_parent_new();
    class_parent_methods();
};

extern o_class_type Parent;

#define parent_instance_variables() \
    o_object_instance_variables()

struct parent {
    parent_instance_variables();
};

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type
#define o_super_class_type class_parent_t
#define o_class_type class_child_t
#define o_instance_type child_t

typedef struct class_child o_class_type;
typedef struct child o_instance_type;

#define class_child_new(...) \
    o_class_object_new(__VA_ARGS__)
#define class_child_methods() \
    o_class_object_methods(); \
    char * (* foo)(o_instance_type * self)

struct class_child {
    o_class_object_variables();
    class_child_new();
    class_child_methods();
};

extern o_class_type Child;

#define child_instance_variables() \
    o_object_instance_variables()

struct child {
    child_instance_variables();
};

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type

#endif
