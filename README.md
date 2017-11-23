# Lincoln-University-Object-Oriented
Storing any code created during the OOP module at Lincoln University. Feel free to use any of the code stored here (I'll add a license at some point).

### Pointers
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

### Arrays & Pointers
Arrays in C++ are just a name to the first location in memory (weird but c++ does this for *some* reason).

```c++
int iArray[] = {1,2,3,4,5} //Creating an int array with 5 values
int *ptr = iArray; //Creating a pointer to point to the first memory address
ptr++ //Increment the pointer (duh)
```
To explain the second line we're telling the ptr variable to point the the memory address of iArray (which is why I mentioned this in the previous sentance). From here the ptr variable can be incremented to go through the values. (I guess you could use arr[num] but still :upside_down_face:)

Example:
```c+++
int arr[] = { 1,2,3,4,5 };
int *ptr = arr;
std::cout << *ptr << std::endl;
ptr++;
std::cout << *ptr << std::endl;
//etc
```

You can't resize an array in c++ (dumb asf) so that's where vectors come in.

### Vectors
Vectors are like a nice, not stupid version of arrays (imo), it's basically the same.

Vectors are part of the STL so we need to import them.

```c++
#include <vector>
std::vector<int> iVector = { 1,2,3,4,5 }; //Int vector
std::cout << iVector[0] << std::endl; //1!
```

Vectors have some cool things like *size()*, *empty()*, *push_pack()* and ***resizing***.

Vectors also use the arr[num] syntax but also has another method.

*.at()* will do the same thing as iVector[num] but will bound check, to make sure it's actually still inside the vector and hasn't wandered off elsewhere.

```c++
std::cout << iVector.at(0) << std::endl; //1!
```