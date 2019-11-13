# Lab 5

A simple vector class
---

In this lab you will implement a simple vector class `Vec`.
Everything for this lab class can go into the same source file.

The class `Vec` shall implement the following features:
* A **standard constructor** that allows to generate a `Vec` object
  via

  ```c++
  int N = 10;
  Vec v(N);
  ```

  In the standard constructor sufficient memory shall be allocated
  to store *N* values of type double.

* A **destructor** that cleans up the memory that has been
  allocated in the **constructor**.

* `void set(const int i, const double a)` and `double get(const int i)` member functions that allow to set and read, respectively, the value the *i*-th entry, i.e. that allow to do
the follwing:
```c++
...
Vec v(N);
double a = 5.2;
...
v.set(0,a);  // Set the value of the 1st entry to 5.2
cout << v.get(0) << endl;
```
Indices shall be 0-based, i.e. the first entry corresponds to index 0.
Make sure that ```get()``` and ```set()```
 member function prevents access to indices
outside of the valid range 0...N-1.

* A function `print` that prints the whole content of the
  vector to the screen. Per line print first the index, then the value.

* Extend the class such that every `Vec` object has a private
  `const string name` member. The standard constructor is then extended
  to take a further `string` parameter whos value is stored into the
  `const string name` variable.
  ```c++
  ...
  Vec v1(N,"vector 1");
  Vec v2(N);
  ...
  ```
  You will need a constructor initializer list to handle this.
  Make this `string` an optional argument with a default value "default",
  such that both lines from the code above are possible.

**Additionally** to the class, write a short program that uses all the functions that you wrote to verify your code.
