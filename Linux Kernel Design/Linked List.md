Here is a image of linked list.  
![image](https://github.com/cliff15037/Note/assets/81866031/97ba1937-9fd3-408d-82b0-d7c096daf98c)  
How to remove a node from the linked list?
1. The straightforward solution as below:
```cpp=
void remove_list_node(List *list, Node *target)
{
    Node *prev = NULL;
    Node *current = list->head;
    // Walk the list
    while (current != target) {
        prev = current;
        current = current->next;
    }
    // Remove the target by updating the head or the previous node.
    if (!prev)
        list->head = target->next;
    else
        prev->next = target->next;
}
```
In the first solution, we need to handle the exception, removing the head is different from removing other node.

2. The advanced "elegant" solution:
```cpp=
void remove_list_node(List *list, Node *target)
{
    // The "indirect" pointer points to the *address*
    // of the thing we'll update.
    Node **indirect = &list->head;
    // Walk the list, looking for the thing that 
    // points to the node we want to remove.
    while (*indirect != target)
        indirect = &(*indirect)->next;
    *indirect = target->next;
}
```

In the second solution, it is very difficult to understand, but only need 4 lines to do it.  
And there is no need to check the exception.

How to understand the second solution?  
First we need to check the structure of a node:  
![image](https://github.com/cliff15037/Note/assets/81866031/164b27bf-bb56-4c78-8a5d-d676af63e421)  
A node has a int value, and a pointer "next" which points to a node.  
Ok, then we start from illustrate "Node **indirect = &list->head;" in solution 2.  
![image](https://hackmd.io/_uploads/B1be1p6vC.png)  
The head and indirect in the image above are both in a rectangle, aka pointer, we can consider this rectangle as a memory space, rectangle head holds the address of node A, rectangle indirect holds the address of pointer head.  
Then, we start to do the while loop:  
while (*indirect != target)  
　　indirect = &(*indirect)->next;  
We assume the target now is node B.  
So at the first time "*indirect != target" is true, we will do "indirect = &(*indirect)->next;".  
![image](https://hackmd.io/_uploads/Syxqxp6PA.png)
As we can see in the image.  
(*indirect) is equal to head, so (*indirect)->next is equal to head->next.  
Thus, &(*indirect)->next is &(head->next), which is the address of the pointer variable in the node A.  
And we need to know that "the pointer variable in the node A" now store the value of the address of node B.  
Which means that, "*indirect" now is "a pointer inside node A, which points to node B".
Therefore, we jump out of the while loop.  
Finally, we do the last step in solution 2 "*indirect = target->next;"

        


