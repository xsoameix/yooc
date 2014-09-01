#include <stdio.h>
#include "o_string.h"

int
main(void) {
  o_init_string_class();
  o_object_t foo = {&OObject};
  printf("foo.class_name()\n => %s\n",
         OObject.class_name(&foo));
  o_string_t bar = {&OString, "bar"};
  printf("bar.class_name()\n => %s\n",
         OString.class_name(&bar));
  printf("bar.string()\n => %s\n",
         OString.string(&bar));
  o_string_t * a = OString.new(&OString, "a");
  printf("a.class()\n => %s\n",
         OString.class(a)->class_name(a));
  printf("a.string()\n => %s\n",
         OString.string(a));
  printf("a.len()\n => %zu\n",
         OString.len(a));
  OString.delete(a);
  return 0;
}
