#include <iostream>
#include <functional>
#include <thread>

void increment( int &x )
{
  ++x;
}

int main()
{
  int i = 0;

  // Here, we bind increment to a COPY of i...
  std::bind( increment, i ) ();
  //                        ^^ (...and invoke the resulting function object)

  // i is still 0, because the copy was incremented.
  std::cout << i << std::endl;

  // Now, we bind increment to std::ref(i)
  std::bind( increment, std::ref(i) ) ();
  // i has now been incremented.
  std::cout << i << std::endl;

  // The same applies for std::thread!
  std::thread( increment, std::ref(i) ).join();
  std::cout << i << std::endl;
}

/*
Plain C++ reference & is an odd citizen, because it can be initialized but not re-assigned. E.g.:

int a, &ra = a;
int b, &rb = b;
ra = rb; // actually does a = b
Whereas plain pointer is a well-behaved citizen, it can be both initialized and re-assigned.

Hence ref() creates reference_wrapper which is a wrapper over a plain pointer. This wrapper can be initialized with a reference and it has an automatic conversion to plain reference &, e.g.:

int a;
auto ra = std::ref(a); 
int b;
auto rb = std::ref(b);
ra = rb; // now ra contains a pointer to b
int& rb2 = ra; // automatically converts to reference
It is mainly useful for functional style programming with lambdas or std::bind expressions. std::bind copies bound arguments, so if you'd like to bind a function argument to a reference reference_wrapper comes handy. E.g.:

void foo(int);

int i = 1;
auto f = std::bind(foo, i); // makes a copy of i
i = 2;
f(); // calls foo(1)

auto g = std::bind(foo, std::ref(i));
i = 3;
g(); // calls foo(3);
*/
