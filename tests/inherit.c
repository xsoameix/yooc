#include <check.h>
#include "inherit.h"

class_parent_t Parent;
class_child_t Child;

static char *
parent_method_foo(void) {
  return "Parent#foo";
}

static char *
child_method_foo(void) {
  return "Child#foo";
}

void
init_parent_class(void) {
  o_init_object_class();
  size_t class_size = sizeof(class_parent_t);
  size_t instance_size = sizeof(parent_t);
  o_method_t methods[] = {
    {offsetof(class_parent_t, foo),        parent_method_foo}
  };
  size_t methods_len = sizeof(methods) / sizeof(o_method_t);
  o_init_class((void *) &Parent, &OObject, "Parent", class_size, instance_size, methods_len, methods);
}

void
init_child_class(void) {
  init_parent_class();
  size_t class_size = sizeof(class_child_t);
  size_t instance_size = sizeof(child_t);
  o_method_t methods[] = {
    {offsetof(class_child_t, foo),        child_method_foo}
  };
  size_t methods_len = sizeof(methods) / sizeof(o_method_t);
  o_init_class((void *) &Child, (void *) &Parent, "Child", class_size, instance_size, methods_len, methods);
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
