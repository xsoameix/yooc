#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "o_string.h"

START_TEST(o_string_new) {
  o_string_t * foo = OString.new(&OString, "foo");
  ck_assert(strcmp(OString.string(foo), "foo") == 0);
  OString.delete(foo);
} END_TEST

START_TEST(o_string_static_new) {
  o_string_t foo = {&OString, "foo"};
  ck_assert(strcmp(OString.string(&foo), "foo") == 0);
} END_TEST

START_TEST(o_string_class_name) {
  o_string_t * foo = OString.new(&OString, "foo");
  ck_assert(strcmp(OString.class_name(foo), "OString") == 0);
  OString.delete(foo);
} END_TEST

START_TEST(o_string_len) {
  o_string_t * foo = OString.new(&OString, "foo");
  ck_assert(OString.len(foo) == strlen("foo"));
  OString.delete(foo);
} END_TEST

Suite *
o_string_suite(void) {
  o_init_string_class();
  Suite * suite = suite_create("o_string");
  TCase * tcase = tcase_create("Core");
  tcase_add_test(tcase, o_string_new);
  tcase_add_test(tcase, o_string_static_new);
  tcase_add_test(tcase, o_string_class_name);
  tcase_add_test(tcase, o_string_len);
  suite_add_tcase(suite, tcase);
  return suite;
}
