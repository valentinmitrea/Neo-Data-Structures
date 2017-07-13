# Neo Data Structures

Neo Data Structures is a library written in C that implements well-known generic data structures such as vector, linked list, queue, stack and many others.

The library is designed to be efficient and easy to use. Its functionalities are inspired from established data structures like `std::vector` in C++ or `ArrayList` in Java.

## Overview

NDS offers the following data structures:

* `NdsVector` - dynamically growing array that stores its elements sequentially (available from 1.0.0)
* `NdsSet` - an array in which each element is unique based on an equality function (TODO)
* `NdsHashSet` - an array in which each element is unique based on its hash value (TODO)
* `NdsList` - a doubly-linked list container (TODO)
* `NdsQueue` - implementation of the queue data structure (TODO)
* `NdsPriorityQueue` - a queue in which each element has a priority attached to it (TODO)
* `NdsStack` - implementation of the stack data structure (TODO)
* `NdsTreeMap` - an ordered dictionary of key-value pairs storing its elements using a Red-Black tree (TODO)
* `NdsHashMap` - an unordered dictionary of key-value pairs storing its elements into buckets (TODO)
* `NdsGraph` - a directed graph structure (TODO)
* `NdsUndirectedGraph` - an undirected graph structure (TODO)

## Installing

The instructions described below will allow you to build the library from sources and install it into the system.

### Prerequisites

You need these programs in order to be able to build the library:

* `git`
* `cmake` (2.8 or above)
* `gcc` (4.4.0 or above)

### Linux

You should check the official [releases](https://github.com/valentinmitrea/Neo-Data-Structures/releases) and choose one from there. After deciding on a version, you have to download its source code and unarchive it in a folder on your hard-disk.

Alternatively, if you want the latest **unstable** build of the library, you must open a terminal and clone the git repository somewhere on your the hard-disk.

```````````````````````````````````````````````````````````````
git clone https://github.com/valentinmitrea/Neo-Data-Structures
```````````````````````````````````````````````````````````````

Now you should go to the created project folder and open a terminal. Here you have to create a `build` folder and enter it.

```````````````````````
mkdir build && cd build
```````````````````````

In this folder you can run `cmake` and build the library.

````````
cmake ..
make
````````

To install the library you have to use the following command that may require administrator privileges:

````````````
make install
````````````

## Tests

The library has various automated tests designed to verify the functionality.

To run these tests on your local machine, you must open a terminal in the project's folder that was created by unarchiving a source code release or cloning the git repository. Here you have to create a `build` folder and enter it.

```````````````````````
mkdir build && cd build
```````````````````````

In this folder you can run `cmake` and build the library along with its tests.

`````````````````````````
cmake -DBUILD_TESTS=ON ..
make
`````````````````````````

To run all the tests in the library you must use `ctest`.

`````
ctest
`````

You can also execute only a section of the test suite. For example, to only run the tests for the `NdsVector` you have to use the following command:

````````````````````````
ctest -R test_nds_vector
````````````````````````

## Usage

After installing the library into your system, you should be able to use it in your C programs.

In order to compile the C programs that use NDS you have to link the library using the `-l` flag.

``````````````````````````````
gcc example.c -o example -lnds
``````````````````````````````

### Examples

There are various coding examples for each data structure available in the `examples` directory.

## Documentation

The offline documentation is available in the `doc` directory or in code commentaries inside the header files.

The online documentation is available on the main [website](http://www.mival.com/nds).

## Issues

If you have any issues or suggestions for improvement, you should submit them [here](https://github.com/valentinmitrea/Neo-Data-Structures/issues).

## History

You can review a history of the library by looking at the [Changelog](https://github.com/valentinmitrea/Neo-Data-Structures/blob/master/Changelog.txt) text file.

## Authors

* **Valentin Gabriel Mitrea** - [github](https://github.com/valentinmitrea) [gitlab](https://gitlab.com/valentinmitrea)

## License

This project is licensed under the LGPL 3.0 license - see the [LICENSE](https://github.com/valentinmitrea/Neo-Data-Structures/blob/master/LICENSE) file for details.

