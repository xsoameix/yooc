# Yet another object oriented library for C.

# Avaiable Classes

## Object

Initialize Object class

    o_init_object_class();

Usage

    // foo is an instance of Object class.
    o_object_t * foo = OObject.new();
    printf("foo.class_name()\n => %s\n",
           foo->class->class_name(foo));
    // foo.class_name()
    //  => Object
    foo->class->delete(foo);

## String

Initialize String class

    o_init_string_class();

Usage

    // bar is an instance of String class.
    o_string_t * bar = OString.new("bar");
    printf("bar.class_name()\n => %s\n",
           bar->class->class_name(bar));
    printf("bar.string()\n => %s\n",
           bar->class->string(bar));
    // bar.class_name()
    //  => String
    // bar.string()
    //  => bar
    bar->class->delete(bar);

    o_string_t * a = OString.new("a");
    printf("a.class()\n => %p\n",
           a->class->class(a));
    printf("a.string()\n => %s\n",
           a->class->string(a));
    printf("a.len()\n => %zu\n",
           a->class->len(a));
    // a.class()
    //  => 0x602080
    // a.string()
    //  => a
    // a.len()
    //  => 1
    a->class->delete(a);
