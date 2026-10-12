# Custom Vector Implementation



Notes:

Pointers store the memory address of another variable.
References are aliases to an existing variable. It just allows us to access the same data.
If & is on the left, this is declaring a reference.
If & is on the right, this retrieves the memory address.
```
Vector& operator=(Vector&& a){
    if (this == &a){
        return *this;
    }
}
```
So we're checking if `this` (Vector*) == `&a` (memory address of `a`). `this` is a pointer, which means it stores the memory address.
Dereference `this` and return because we want a new alias for the Vector.