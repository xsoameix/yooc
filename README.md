# Yet another light weight object oriented library for C.

Supported features:

*   Encapsulation
*   Inheritance
*   Polymorphism

# Avaiable Classes

## Object

Initialize Object class

    o_init_object_class();

Usage

    // foo is an instance of Object class.
    o_object_t * foo = OObject.new();
    printf("foo.class_name()\n => %s\n",
           foo->_->class_name(foo));
    // foo.class_name()
    //  => Object
    foo->_->delete(foo);

## String

Initialize String class

    o_init_string_class();

Usage

    // bar is an instance of String class.
    o_string_t * bar = OString.new("bar");
    printf("bar.class_name()\n => %s\n",
           bar->_->class_name(bar));
    printf("bar.string()\n => %s\n",
           bar->_->string(bar));
    // bar.class_name()
    //  => String
    // bar.string()
    //  => bar
    bar->_->delete(bar);

    o_string_t * a = OString.new("a");
    printf("a.class()\n => %p\n",
           a->_->class(a));
    printf("a.string()\n => %s\n",
           a->_->string(a));
    printf("a.len()\n => %zu\n",
           a->_->len(a));
    // a.class()
    //  => 0x602080
    // a.string()
    //  => a
    // a.len()
    //  => 1
    a->_->delete(a);

# Development

Build libyooc.a and tests

    make

Run coverage

    make yooc_coverage
