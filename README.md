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

# Underscore Syntax

    #define _(instance, method, ...) instance->_->method(instance, ## __VA_ARGS__)

    _(instance, method, arg1, arg2, ...);

Examples:

    _(array, len);
    _(hash, set, key, value);

# Avaiable Classes

## Object

Initialize Object class

    o_init_object_class();

Usage

*   Create an instance from `Object` class.

        o_object_t * foo = OObject.new();

*   Call `class_name` method of foo.

        puts(_(foo, class_name)); // => OObject

*   Delete this instance.

        _(foo, delete);

## String

Initialize String class

    o_init_string_class();

Usage

*   Create an instance from `String` class.

        o_string_t * bar = OString.new("bar");

*   Call `class_name`, `string`, and `len` methods of foo.

        puts(_(bar, class_name)); // => OString
        puts(_(bar, string));     // => bar
        printf("%zu", _(bar, len)); // => 3

*   Delete this instance.

        _(bar, delete);

# Development

Build libyooc.a and tests

    make

Run coverage

    make yooc_coverage
