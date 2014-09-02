#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "o_object.h"

START_TEST(o_object_new) {
  o_object_t * foo = OObject.new();
  ck_assert(OObject.class(foo) == &OObject);
  OObject.delete(foo);
} END_TEST

START_TEST(o_object_static_new) {
  o_object_t foo = {&OObject};
  ck_assert(OObject.class(&foo) == &OObject);
} END_TEST

START_TEST(o_object_class_name) {
  o_object_t * foo = OObject.new();
  ck_assert(strcmp(OObject.class_name(foo), "OObject") == 0);
  OObject.delete(foo);
} END_TEST

Suite *
o_object_suite(void) {
  o_init_object_class();
  Suite * suite = suite_create("o_object");
  TCase * tcase = tcase_create("Core");
  tcase_add_test(tcase, o_object_new);
  tcase_add_test(tcase, o_object_static_new);
  tcase_add_test(tcase, o_object_class_name);
  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *
o_all_suite(void) {
  return suite_create("all");
}

Suite * o_string_suite(void);
Suite * inherit_suite(void);
Suite * interface_suite(void);

int
main(void) {
  SRunner * runner = srunner_create(o_all_suite());
  srunner_add_suite(runner, o_object_suite());
  srunner_add_suite(runner, o_string_suite());
  srunner_add_suite(runner, inherit_suite());
  srunner_add_suite(runner, interface_suite());
  srunner_run_all(runner, CK_NORMAL);
  size_t failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
