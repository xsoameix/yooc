#include <stdio.h>
#include "o_string.h"

int
main(void) {
  o_init_string_class();
  o_object_t * foo = OObject.new();
  printf("foo.class_name()\n => %s\n",
         foo->class->class_name(foo));
  foo->class->delete(foo);

  o_string_t * bar = OString.new("bar");
  printf("bar.class_name()\n => %s\n",
         bar->class->class_name(bar));
  printf("bar.string()\n => %s\n",
         bar->class->string(bar));
  bar->class->delete(bar);

  o_string_t * a = OString.new("a");
  printf("a.class()\n => %p\n",
         a->class->class(a));
  printf("a.string()\n => %s\n",
         a->class->string(a));
  printf("a.len()\n => %zu\n",
         a->class->len(a));
  a->class->delete(a);
  return 0;
}
