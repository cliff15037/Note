Here I use a class named "Trie" as example.

In C++, the line "Trie trie;" is indeed the correct way to create an instance of the Trie class on the stack. 
And there is another expression "Trie trie = new Trie();" would be used if you were allocating the instance on the heap, 
which is common in languages like Java (Java only allows object creation on the heap).

C++ Memory Management: Stack vs. Heap
Stack Allocation:
"Trie trie;" instantiates a Trie object directly on the stack. 
This is straightforward and is managed automatically by the compiler. 
The object trie will be destroyed automatically when it goes out of scope, which means you don't need to manually manage the memory (no need to delete it).
Stack allocation is faster and is suitable for objects that are not too large and have a short lifespan confined to the scope in which they are declared.
Heap Allocation:

If you were to allocate a Trie object on the heap in C++, you would use the new keyword, but it requires a pointer to hold the address of the allocated memory. 
The correct syntax would be:
Trie* trie = new Trie();
This allocates memory on the heap, and the object persists until you explicitly delete it using delete trie;. 
This method is necessary for larger objects or objects whose lifetime must extend beyond the scope in which they are created. 
However, it also introduces the responsibility of managing memory manually to avoid memory leaks.
Using heap allocation also requires you to use pointers to access the object's methods and members, which introduces additional complexity.
