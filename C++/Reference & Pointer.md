Syntax: References are indicated by the symbol &.
Binding: References must be initialized when declared and cannot change the object they reference.
Usage: References serve as aliases for variables, where operations on a reference actually manipulate the referenced object.
Memory: References essentially store the memory address of a variable, but are syntactically simpler and safer than pointers.

```cpp
int a = 5;
int &ref = a;  // References must be initialized when declared
ref = 10;  // This changes the value of a, which is now 10
```

Syntax: Pointers are indicated by the symbol *.
Binding: Pointers can change the object they point to during runtime.
Usage: Accessing the object pointed to by a pointer requires dereferencing (*).
Memory: Pointers store the memory address of a variable and allow access or modification of data in memory.
```cpp
int a = 5;
int *ptr;  // Pointers can be initialized after declaration
ptr = &a;
*ptr = 10;  // This changes the value of a, which is now 10


int b = 20;
ptr = &b;  // Pointers can point to different variables
```

Key Differences:
Initialization: References must be initialized when declared; pointers can be initialized after declaration.
Rebinding: Once initialized, a reference cannot be rebound; pointers can point to different addresses at any time.
Syntax Simplicity: References use simpler syntax resembling regular variables; pointers require * and & operators for operations.
Safety: References are generally considered safer as they avoid many pointer-related errors like null pointers and pointer arithmetic.

Pointer is a special variable, which is used to store memory address.
