#qcp - QuickCheck for C++

qcp is a QuickCheck unit test framework for C++. It is used for pure functional testing by feeding your function with random generated inputs many times. Now it's running based on GoogleTest.

This project is inspired by ScalaCheck & QuickCheck. Since there are currently no usable QuickCheck for doing unit test in C++.

## Example

Here is an example to test integer arithmetics:

    SPECIFICATION(int_arithmetics) {
    
        Property<int, int>("add 2 integer is no greater than add their absolute values") = [](int lhs, int rhs) {
            return lhs + rhs <= abs(lhs) + abs(rhs);
        };
    
        Property<int>("WRONG: bad math, a integer is greater than it plus 1") = [](int a) {
            return a > a + 1;
        };
    
    }

And test result will show the input fails test:

![example][1]

## How to Use?

Please refer to the `examples` source code about how to add generator for user-defined class.

Generators are far from finished, still under construction.

## Requirement

* Compiler supports C++ 11 vardic template to compile.
* GoogleTest

## License

[New BSD License](http://opensource.org/licenses/BSD-3-Clause)


  [1]: https://raw.github.com/xinhuang/qcp/master/doc/images/example.png
