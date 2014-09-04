#include <stdio.h>
#include "o_string.h"

int
main(void) {
  o_init_string_class();
  o_object_t * foo = OObject.new();
  printf("foo.class_name()\n => %s\n",
         foo->_->class_name(foo));
  foo->_->delete(foo);

  o_string_t * bar = OString.new("bar");
  printf("bar.class_name()\n => %s\n",
         bar->_->class_name(bar));
  printf("bar.string()\n => %s\n",
         bar->_->string(bar));
  bar->_->delete(bar);

  o_string_t * a = OString.new("a");
  printf("a.class()\n => %p\n",
         a->_->class(a));
  printf("a.string()\n => %s\n",
         a->_->string(a));
  printf("a.len()\n => %zu\n",
         a->_->len(a));
  a->_->delete(a);
  return 0;
}
