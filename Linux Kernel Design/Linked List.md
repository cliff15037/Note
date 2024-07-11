Here is a image of linked list.  
![image](https://github.com/cliff15037/Note/assets/81866031/97ba1937-9fd3-408d-82b0-d7c096daf98c)
How to remove a node from the linked list?
1. The straightforward solution as below:
```cpp
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

2. The advanced solution:
```cpp
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
