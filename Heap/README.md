# **Heap Data Structure**
> It can implemented by linked list and array also.

## **Heap**
A **heap** is a special complete tree-based data structure that satisfies the **heap property**:
1. **Max-Heap Property**: The value of each node is greater than or equal to the values of its children. The maximum value is at the root.
2. **Min-Heap Property**: The value of each node is less than or equal to the values of its children. The minimum value is at the root.

> Heaps are generally implemented as binary trees, specifically as **binary heaps**.

---
### Types of Heaps

1. **Max-Heap**:
   - The largest element is stored at the root.
   - Every parent node has a value greater than or equal to its children.

   **Applications**:
   - Priority queues
   - Heap sort
   - Scheduling algorithms

2. **Min-Heap**:
   - The smallest element is stored at the root.
   - Every parent node has a value less than or equal to its children.

   **Applications**:
   - Priority queues (when smaller elements have higher priority)
   - Dijkstra’s shortest path algorithm
   - Prim’s minimum spanning tree algorithm

---
### Properties of Heaps

- **Array Representation**: Heaps are typically implemented using arrays, where the parent-child relationship can be defined as(`0 based indexing`):
  - Parent of node at index `i`: `floor((i - 1) / 2)`
  - Left child of node at index `i`: `2 * i + 1`
  - Right child of node at index `i`: `2 * i + 2`

- **Complete Binary Tree**: A heap is a complete binary tree, meaning all levels are fully filled except possibly the last, which is filled from left to right.

- **Height**: The height of a heap is `log(n)` where `n` is the number of nodes in the heap.

- **Space Complexity**: The space used by a heap is O(n), as all nodes are stored in an array.
---

### Building a Heap(Heapify)
- Heapify is the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.


#### Algorithm For MIN-HEAPIFY
```
MIN-HEAPIFY(A, i)
1. l ← LEFT(i)
2. r ← RIGHT(i)
3. if l ≤ A.heap-size and A[l] < A[i]
4.     smallest ← l
5. else
6.     smallest ← i
7. if r ≤ A.heap-size and A[r] < A[smallest]
8.     smallest ← r
9. if smallest ≠ i
10.    exchange A[i] with A[smallest]
11.    MIN-HEAPIFY(A, smallest)
```

#### Code For MIN-HEAPIFY
```cpp
int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void minHeapify(vector<int>& heap, int i, int heapSize) {
    int l = left(i); 
    int r = right(i);   
    int smallest = i;    

    if (l < heapSize && heap[l] < heap[smallest])
        smallest = l;

    if (r < heapSize && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}
```


> The design of the MaxHeapify algorithm is very similar to that of the MinHeapify algorithm, the only difference is that the < operator in the second
condition of entering the while loop is changed to >.


### Operations on Heaps

#### 1. **Insertion**
- Add the new element at the end of the heap.
- Repeatedly compare the added element with its parent and swap if needed.


#### Algorithm For Insertion
```
INSERT(A, key)
1. A.heap-size ← A.heap-size + 1
2. i ← A.heap-size - 1
3. A[i] ← key
4. while i > 0 and A[PARENT(i)] > A[i]
5.     exchange A[i] with A[PARENT(i)]
6.     i ← PARENT(i)
```

#### Code For Insertion
```cpp
void insert(vector<int>& heap, int key) {
    heap.push_back(key); // Add the new key at the end
    int i = heap.size() - 1;

    // Fix the min-heap property if violated
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]); // Swap with parent
        i = (i - 1) / 2;                 // Move to the parent
    }
}
```


#### 2. **Deletion**
- find the index of the value to delete
- put the last value in the heap at the index location of the item to delete
- verify heap ordering for each subtree which used to include the valu


#### Algorithm For Deletion
```
DELETE(A, i)
1. if i > A.heap-size or A.heap-size == 0
2.     return ERROR
3. A[i] ← A[A.heap-size - 1]
4. A.heap-size ← A.heap-size - 1
5. MIN-HEAPIFY(A, i)
```

#### Code For Deletion
```cpp
void deleteNode(vector<int>& heap, int i) {
    if (i >= heap.size()) {
        cout << "Index out of range!" << endl;
        return;
    }
    
    heap[i] = heap.back(); // Replace with the last element
    heap.pop_back();       // Remove the last element
    minHeapify(heap, i, heap.size()); // Fix the min-heap property
}
```


#### 3. **Search**
- Perform a linear search to find the required element.

#### Algorithm For Searching
```
SEARCH(A, key)
1. for i ← 0 to A.heap-size - 1
2.     if A[i] == key
3.         return i
4. return -1
```

#### Code For Searching
```cpp
int search(const vector<int>& heap, int key) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i] == key) return i; // Return index if found
    }
    return -1; // Return -1 if not found
}
```


#### 4. **Traversal**
- Traversing a heap is equivalent to traversing the array representation.


#### Algorithm For Traversal
```
TRAVERSE(A)
1. for i ← 0 to A.heap-size - 1
2.     print A[i]
```

#### Code For Searching
```cpp
void traverse(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}
```


---

### Time Complexity Summary

| Operation   | Best Case | Average Case | Worst Case |
|-------------|-----------|--------------|------------|
| Build Heap  | O(n)      | O(n)         | O(n)       |
| Insert      | O(1)      | O(log n)     | O(log n)   |
| Delete      | O(log n)  | O(log n)     | O(log n)   |
| Search      | O(1)      | O(n)         | O(n)       |
| Traversal   | O(n)      | O(n)         | O(n)       |

---

### Applications of Heaps
1. **Priority Queues**: Used to efficiently manage jobs with priorities.
2. **Heap Sort**: Sorting algorithm with O(n log n) complexity.
3. **Graph Algorithms**: Used in Dijkstra’s and Prim’s algorithms.
4. **Median Maintenance**: Maintain the median of a stream of numbers.
5. **Merge K Sorted Arrays**: Used to efficiently merge multiple sorted arrays.
6. **Interval Problems**: Solve overlapping interval scheduling problems.
7. **Top K Problems**: Efficiently find the top K largest or smallest elements in a dataset.
---