#include <stdio.h>
#include "o_string.h"

int
main(void) {
  o_init_string_class();
  o_object_t * foo = OObject.new();
  printf("foo.class_name()\n => %s\n",
         OObject.class_name(foo));
  OObject.delete(foo);

  o_string_t * bar = OString.new("bar");
  printf("bar.class_name()\n => %s\n",
         OString.class_name(bar));
  printf("bar.string()\n => %s\n",
         OString.string(bar));
  OString.delete(bar);

  o_string_t * a = OString.new("a");
  printf("a.class()\n => %p\n",
         OString.class(a));
  printf("a.string()\n => %s\n",
         OString.string(a));
  printf("a.len()\n => %zu\n",
         OString.len(a));
  OString.delete(a);
  return 0;
}
