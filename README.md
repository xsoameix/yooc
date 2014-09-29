# Yet another light weight object oriented library for C.

Supported features:

*   Encapsulation
*   Inheritance
*   Polymorphism

# Basic Syntax

    instance->_->method(instance, arg1, arg2, ...);

Examples:

    array->_->len(array);
    hash->_->set(hash, key, value);

# Avaiable Classes

## Object

Initialize Object class

    o_init_object_class();

Usage

*   Create an instance from `Object` class.

        o_object_t * foo = OObject.new();

*   Call `class_name` method of foo.

        puts(foo->_->class_name(foo)); // => OObject

*   Delete this instance.

        foo->_->delete(foo);

## String

Initialize String class

    o_init_string_class();

Usage

*   Create an instance from `String` class.

        o_string_t * bar = OString.new("bar");

*   Call `class_name`, `string`, and `len` methods of foo.

        puts(bar->_->class_name(bar)); // => OString
        puts(bar->_->string(bar));     // => bar
        printf("%zu", bar->_->len(bar)); // => 3

*   Delete this instance.

        bar->_->delete(bar);

# Development

Build libyooc.a and tests

    make

Run coverage

    make yooc_coverage
