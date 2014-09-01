# Yet another object oriented library for C.

# Avaiable Classes

## Object

Initialize Object class

    o_init_object_class();

Usage

    // foo is an instance of Object class.
    o_object_t foo = {&OObject};
    printf("foo.class_name()\n => %s\n",
           OObject.class_name(&foo));
    // foo.class_name()
    //  => Object

## String

Initialize String class

    o_init_string_class();

Usage

    // bar is an instance of String class.
    o_string_t bar = {&OString, "bar"};
    printf("bar.class_name()\n => %s\n",
           OString.class_name(&bar));
    printf("bar.string()\n => %s\n",
           OString.string(&bar));
    // bar.class_name()
    //  => String
    // bar.string()
    //  => bar

    // 'a' is allocated by malloc.
    o_string_t * a = OString.new(&OString, "a");
    printf("a.class()\n => %s\n",
           OString.class(a)->class_name(a));
    printf("a.string()\n => %s\n",
           OString.string(a));
    printf("a.len()\n => %zu\n",
           OString.len(a));
    OString.delete(a);
    // a.class()
    //  => String
    // a.string()
    //  => a
    // a.len()
    //  => 1
