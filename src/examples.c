#include <stdio.h>
#include "o_string.h"
#define _(instance, method, ...) instance->_->method(instance, ## __VA_ARGS__)

int
main(void) {
  o_init_string_class();
  o_object_t * foo = OObject.new();
  printf("foo.class_name()\n => %s\n",
         _(foo, class_name));
  _(foo, delete);

  o_string_t * bar = OString.new("bar");
  printf("bar.class_name()\n => %s\n",
         _(bar, class_name));
  printf("bar.string()\n => %s\n",
         _(bar, string));
  _(bar, delete);

  o_string_t * a = OString.new("a");
  printf("a.class()\n => %p\n",
         _(a, class));
  printf("a.string()\n => %s\n",
         _(a, string));
  printf("a.len()\n => %zu\n",
         _(a, len));
  _(a, delete);
  return 0;
}
