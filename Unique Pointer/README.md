
Notes:
A `pointer` is a type of variable that stores the address of an object in memory.
A `raw pointer` has no ownership semantics: copying or destroying it does nothing to the object it points to:
- If we delete the object that is being pointed to, this results in `dangling pointer`, a pointer that points to freed memory.
- The pointer can be destroyed while the object still exists, and if nobody calls `delete`, we have a memory leak.
- `*` dereferences the given address and returns the value, whereas `&` gives the address, so `*(&a)` = `a`
- Dereferencing a pointer just returns the value at that memory address, we can change the value of a variable by `*ptr = new_value`
- address of var returns a pointer, not the literal of the memory address
- Pointer size is dependent on architecture, but either 4/8 bytes
```
#include <iostream>

struct Widget {
    Widget()  { std::cout << "Widget constructed\n"; }
    ~Widget() { std::cout << "Widget destroyed\n"; }
};

void f() {
    Widget a; //This will be automatically destroyed because we have ~Widget()
    Widget* p = new Widget;   // object allocated on the heap, not destroyed because we have Widget* that doesn't have a destructor
}   // p goes out of scope here: the pointer variable is gone

int main() {
    f();
    std::cout << "f() returned\n";
}
```

Here, when p goes out of scope, we lose the pointer but the Widget object itself wasn't destroyed.
Before `f()` returns, we need to `delete` the `new Widget` that was created.

Storing memory on the `stack` holds local variables for each function call. When a function is called, a `frame` is 
set aside for the local variables, and when a function returns, the frame is released.

`Heap` is a large pool of memory that is requested explicitly at runtime. This is used
when we need an object to outlive the function or too large for stack. These are 
requested through `new` and is freed when `delete` is called.

`std::unique_ptr` is a move only type