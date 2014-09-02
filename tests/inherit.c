#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "inherit.h"

#define o_class Parent
#define o_class_type class_parent_t
#define o_instance_type parent_t

o_class_type o_class;

static o_instance_type *
parent_method_new(void) {
  o_init_instance();
}

static char *
parent_method_foo(o_instance_type * self) {
  if (o_wrong_class(self)) return NULL;
  o_lookup_method(foo, self);
  return "Parent#foo";
}

void
init_parent_class(void) {
  o_init_object_class();
  o_define_superclass(OObject);
  o_define_method(new, parent_method_new);
  o_define_method(foo, parent_method_foo);
}

#undef o_class
#undef o_class_type
#undef o_instance_type
#define o_class Child
#define o_class_type class_child_t
#define o_instance_type child_t

o_class_type o_class;

static o_instance_type *
child_method_new(void) {
  o_init_instance();
}

static char *
child_method_foo(o_instance_type * self) {
  return "Child#foo";
}

void
init_child_class(void) {
  init_parent_class();
  o_define_superclass(Parent);
  o_define_method(new, child_method_new);
  o_define_method(foo, child_method_foo);
}

START_TEST(inherit) {
  o_object_t * obj = OObject.new();
  parent_t * parent = Parent.new();
  ck_assert(strcmp(Parent.foo(parent), "Parent#foo") == 0);
  child_t * child = Child.new();
  ck_assert(strcmp(Child.foo(child), "Child#foo") == 0);
  ck_assert(strcmp(Parent.foo((parent_t *) child), "Child#foo") == 0);
  ck_assert(Parent.foo((void *) obj) == NULL);
  OObject.delete(obj);
  Parent.delete(parent);
  Child.delete(child);
} END_TEST

Suite *
inherit_suite(void) {
  init_child_class();
  Suite * suite = suite_create("inherit");
  TCase * tcase = tcase_create("Core");
  tcase_add_test(tcase, inherit);
  suite_add_tcase(suite, tcase);
  return suite;
}
