# Lincoln-University-Object-Oriented
Storing any code created during the OOP module at Lincoln University. Feel free to use any of the code stored here (I'll add a license at some point).

#### Pointers
Example:
```c++
int x = 6; //Defines an variable named x as an integer with the value of 6
std::cout << &x << // returns the memory address of x, given by &{var} something like 0096FB24
```
We can assign the memory address just returned above to another variable
```c++
int *y = &x; //This looks a little weird imo
```
So here the variable **y** is being assigned the location of **x**

**y** is a pointer to our **x** integer and is assigned the location of **x**

We can also use this to set values through dereferenced pointers
```c++
*y = 4;
std::cout << x << std::endl; //x is now 4 as we changed the value at the memory address
```

*tl;dr*
memory location = &
create a point *{var}
dereferencing changes things.

