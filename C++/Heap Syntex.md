```cpp
#include <vector>
#include <algorithm> // for make_heap
#include <iostream>

using namespace std;

/*
  To make a heap in O(n), need to use make_heap function, not priority_queue
  make_heap simply reorganize the element in vector, but it is still a vector, can use function of vector
*/
int main() {
    // example
    vector<pair<int, int>> record = {{5, 0}, {3, 1}, {8, 2}, {1, 3}, {6, 4}};
    
    // transfer record to minHeap, O(n)
    make_heap(record.begin(), record.end(), greater<pair<int, int>>());

    // get the top element, O(1)
    cout << "the top: " << record.front().first << ", " << record[0].second << endl; // there are two method to get top

    // push a new wlwment, O(log n)
    record.push_back({2, 5});
    push_heap(record.begin(), record.end(), greater<pair<int, int>>());

    cout << "the new top: " << record.front().first << ", " << record.front().second << endl;

    // delete the top O(log n)
    pop_heap(record.begin(), record.end(), greater<pair<int, int>>());
    record.pop_back();

    cout << "the new top: " << record.front().first << ", " << record.front().second << endl;

    return 0;
}
```

===============================================

```cpp
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<pair<int, int>> record = {{5, 0}, {3, 1}, {8, 2}, {1, 3}, {6, 4}};
    
    // O(n log n)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap(record.begin(), record.end());
    
    // O(1)
    cout << "The top: " << minHeap.top().first << ", " << minHeap.top().second << endl;

    // O(log n)
    minHeap.push({2, 5});

    //O(1)
    cout << "The top after push: " << minHeap.top().first << ", " << minHeap.top().second << endl;

    // O(log n)
    minHeap.pop();

    //O(1)
    cout << "The top after delete: " << minHeap.top().first << ", " << minHeap.top().second << endl;

    return 0;
}
```
