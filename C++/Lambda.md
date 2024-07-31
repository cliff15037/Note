The basic form of lambda:
```cpp
[capture](parameters) -> return_type {
    // function body
}
```
capture：define the ability for lambda to get outside variable. [=] means can capture all outside variables copy, 
[&] means can capture all outside variables reference.



```cpp
int main() {
    // Initialize the vector
    std::vector<std::vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};

    // Sort the vector ascending
    std::sort(books.begin(), books.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1]; // Comparing second elements
    });

    // Sort the vector descending
    std::sort(books.begin(), books.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1]; // Comparing second elements for descending order
    });


    // Print the sorted vector
    for (const auto& book : books) {
        std::cout << "[" << book[0] << "," << book[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```
