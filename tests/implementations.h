#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H

#include "o_object.h"
#include "interface.h"

#define o_super_class_type o_class_object_t
#define o_class_type class_rectangle_t
#define o_instance_type rectangle_t

typedef struct class_rectangle o_class_type;
typedef struct rectangle o_instance_type;

#define class_rectangle_new(...) \
    o_class_object_new(__VA_ARGS__)
#define class_rectangle_methods() \
    o_class_object_methods(); \
    o_interface_shape_methods()

struct class_rectangle {
    o_class_object_variables();
    class_rectangle_new(size_t w, size_t h);
    class_rectangle_methods();
};

extern o_class_type Rectangle;

#define rectangle_instance_variables() \
    o_object_instance_variables()

struct rectangle {
    rectangle_instance_variables();
    size_t w;
    size_t h;
};

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type
#define o_super_class_type o_class_object_t
#define o_class_type class_square_t
#define o_instance_type square_t

typedef struct class_square o_class_type;
typedef struct square o_instance_type;

#define class_square_new(...) \
    o_class_object_new(__VA_ARGS__)
#define class_square_methods() \
    o_class_object_methods(); \
    o_interface_shape_methods()

struct class_square {
    o_class_object_variables();
    class_square_new(size_t w);
    class_square_methods();
};

extern o_class_type Square;

#define square_instance_variables() \
    o_object_instance_variables()

struct square {
    square_instance_variables();
    size_t w;
};

#undef o_super_class_type
#undef o_class_type
#undef o_instance_type

#endif
