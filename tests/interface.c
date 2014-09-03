#include <check.h>
#include <stdio.h>
#include "interface_instance.h"

#define o_class Rectangle
#define o_class_type class_rectangle_t
#define o_instance_type rectangle_t

void * Shape;

o_class_type o_class;

static o_instance_type *
rectangle_method_new(size_t w, size_t h) {
  o_init_instance(w, h);
}

static void
rectangle_method_initialize(o_instance_type * self, size_t w, size_t h) {
  self->w = w;
  self->h = h;
}

static size_t
rectangle_method_area(shape_t * self) {
  return self->rectangle.w * self->rectangle.h;
}

void
init_rectangle_class(void) {
  o_init_object_class();
  o_define_superclass(OObject);
  o_implements(Shape);
  o_define_method(new,        rectangle_method_new);
  o_define_method(initialize, rectangle_method_initialize);
  o_define_method(area,       rectangle_method_area);
}

#undef o_class
#undef o_class_type
#undef o_instance_type
#define o_class Square
#define o_class_type class_square_t
#define o_instance_type square_t

o_class_type o_class;

static o_instance_type *
square_method_new(size_t w) {
  o_init_instance(w);
}

static void
square_method_initialize(o_instance_type * self, size_t w) {
  self->w = w;
}

static size_t
square_method_area(shape_t * self) {
  return self->square.w * self->square.w;
}

void
init_square_class(void) {
  o_init_object_class();
  o_define_superclass(OObject);
  o_implements(Shape);
  o_define_method(new,        square_method_new);
  o_define_method(initialize, square_method_initialize);
  o_define_method(area,       square_method_area);
}

START_TEST(interface) {
  shape_t * rectangle = (shape_t *) Rectangle.new(2, 10);
  ck_assert(o_interface_shape_of(rectangle)->area(rectangle) == 20);
  shape_t * square = (shape_t *) Square.new(2);
  ck_assert(o_interface_shape_of(square)->area(square) == 4);
  Rectangle.delete(rectangle);
  Square.delete(square);
} END_TEST

Suite *
interface_suite(void) {
  init_rectangle_class();
  init_square_class();
  Suite * suite = suite_create("interface");
  TCase * tcase = tcase_create("Core");
  tcase_add_test(tcase, interface);
  suite_add_tcase(suite, tcase);
  return suite;
}
