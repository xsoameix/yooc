#include <check.h>
#include "inherit.h"

#define o_class_type class_parent_t
#define o_instance_type parent_t

o_class_type Parent;

static char *
parent_method_foo(o_instance_type * self) {
  return "Parent#foo";
}

void
init_parent_class(void) {
  o_init_object_class();
  o_define_superclass(Parent, OObject);
  o_define_method(Parent, foo, parent_method_foo);
}

#undef o_class_type
#undef o_instance_type
#define o_class_type class_child_t
#define o_instance_type child_t

o_class_type Child;

static char *
child_method_foo(o_instance_type * self) {
  return "Child#foo";
}

void
init_child_class(void) {
  init_parent_class();
  o_define_superclass(Child, Parent);
  o_define_method(Child, foo, child_method_foo);
}

START_TEST(inherit) {
  parent_t * parent = Parent.new(&Parent);
  ck_assert(strcmp(Parent.foo(parent), "Parent#foo") == 0);
  child_t * child = Child.new(&Child);
  ck_assert(strcmp(Child.foo(child), "Child#foo") == 0);
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
