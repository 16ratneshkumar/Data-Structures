# Documentation on Space Complexity with Examples and Practice Questions

## Introduction

Space complexity is a concept in computer science that measures the amount of memory an algorithm uses as a function of the input size. Just like time complexity evaluates how fast an algorithm executes, space complexity evaluates how much memory it requires. Understanding space complexity is crucial when working with systems with limited memory resources, such as embedded systems, mobile devices, or large-scale data processing tasks.

---

## What is Space Complexity?

### Definition:
Space complexity is the total amount of memory required by an algorithm, including both:
1. **Auxiliary space**: The extra space or temporary space used by the algorithm, excluding the space taken by the input data.
2. **Input space**: The memory required to store the input data.

It is generally expressed as a function of the input size `n`, similar to time complexity, and is often represented using asymptotic notations such as Big O (`O`), Omega (`Ω`), and Theta (`Θ`).

#### Example:
If an algorithm requires a fixed amount of space and additional space that grows linearly with the input size `n`, its space complexity would be `O(n)`.

---

## Components of Space Complexity

### 1. **Fixed Part**:
This refers to memory that does not depend on the size of the input data. It includes:
- Memory used to store constants and fixed-size variables.
- Static allocations, which are created at compile time and do not change during the execution of the algorithm.

### 2. **Variable Part**:
This refers to memory whose usage grows with the input size. It includes:
- Dynamic allocations, like dynamically created arrays, linked lists, recursion stack memory, etc.
- Space used by auxiliary variables like loops, recursive calls, or additional data structures like stacks and queues.

---

## Types of Space Complexity

### 1. **Constant Space Complexity (`O(1)`)**
Constant space complexity means that the algorithm uses a fixed amount of memory, regardless of the size of the input.

#### Example:
```python
def constant_space_algo(n):
    result = 0
    for i in range(n):
        result += i
    return result
```
In this algorithm, only a fixed amount of memory is used for the variables `result` and `i`, irrespective of the input size `n`. Therefore, the space complexity is `O(1)`.

### 2. **Linear Space Complexity (`O(n)`)**
Linear space complexity means that the memory usage grows proportionally with the input size `n`.

#### Example:
```python
def linear_space_algo(arr):
    new_arr = []
    for element in arr:
        new_arr.append(element * 2)
    return new_arr
```
Here, a new array `new_arr` is created, and its size grows linearly with the size of the input array `arr`. Hence, the space complexity is `O(n)`.

### 3. **Logarithmic Space Complexity (`O(log n)`)**
Logarithmic space complexity means that the memory usage grows logarithmically with the input size `n`. This often happens in recursive algorithms that reduce the problem size by half at each step, such as in binary search.

#### Example:
```python
def binary_search(arr, target, left, right):
    if left > right:
        return -1
    mid = (left + right) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search(arr, target, mid + 1, right)
    else:
        return binary_search(arr, target, left, mid - 1)
```
Each recursive call reduces the size of the problem by half. Since the depth of the recursion is `log n`, the space complexity of this algorithm is `O(log n)`.

### 4. **Quadratic Space Complexity (`O(n²)`)**
Quadratic space complexity means that the memory usage grows proportionally to the square of the input size. This typically happens when an algorithm requires a two-dimensional data structure such as a matrix.

#### Example:
```python
def create_matrix(n):
    matrix = [[0] * n for _ in range(n)]
    return matrix
```
The algorithm creates a `n x n` matrix, resulting in `O(n²)` space complexity.

---

## Space Complexity of Recursive Algorithms

In recursive algorithms, space complexity is influenced by the recursion stack. Each recursive call adds a new frame to the stack, which consumes additional memory.

### Example:
```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
```
For each call to `factorial(n)`, a new stack frame is created. Thus, the space complexity for this recursive algorithm is `O(n)` because the depth of recursion is `n`.

#### Recursive vs Iterative:
- **Recursive algorithms** can often use more space than iterative ones due to the extra memory required for the function call stack.
- **Iterative algorithms**, on the other hand, can often achieve the same result using `O(1)` space, as they don’t rely on recursion.

---

## Common Space Complexities

1. **Constant space (`O(1)`)**:
   - Algorithms that don’t allocate extra space or only use a small fixed amount of space.
   - Example: Swapping two variables.

2. **Linear space (`O(n)`)**:
   - Algorithms that allocate memory proportional to the input size.
   - Example: Storing an array or list of size `n`.

3. **Logarithmic space (`O(log n)`)**:
   - Recursive algorithms that reduce the problem size by half at each step, like binary search.

4. **Quadratic space (`O(n²)`)**:
   - Algorithms that require 2D matrices or similar data structures.
   - Example: Algorithms for dynamic programming using a `n x n` matrix.

---

## Examples of Space Complexity for Common Algorithms

1. **Linear Search**:
   - Time complexity: `O(n)`
   - Space complexity: `O(1)` (constant space since no extra memory is required)

2. **Binary Search**:
   - Time complexity: `O(log n)`
   - Space complexity: `O(log n)` (logarithmic space due to the recursion stack, or `O(1)` in an iterative version)

3. **Merge Sort**:
   - Time complexity: `O(n log n)`
   - Space complexity: `O(n)` (requires additional memory to store the merged arrays)

4. **Quick Sort**:
   - Time complexity: `O(n log n)` (average case), `O(n²)` (worst case)
   - Space complexity: `O(log n)` (average case) due to recursion stack, or `O(n)` if extra space is used for partitioning.

5. **Depth First Search (DFS)**:
   - Time complexity: `O(V + E)` (where `V` is the number of vertices and `E` is the number of edges)
   - Space complexity: `O(V)` due to the recursion stack (if recursive) or stack memory (if iterative)

6. **Breadth First Search (BFS)**:
   - Time complexity: `O(V + E)`
   - Space complexity: `O(V)` due to the queue used to store nodes at each level.

---

## Practice Questions

### Question 1:
What is the space complexity of the following algorithm?
```python
def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total
```

#### Solution:
The algorithm only uses a fixed amount of space (`total` and `num`), regardless of the input size. Therefore, the space complexity is `O(1)`.

---

### Question 2:
Consider the following recursive function:
```python
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
```
What is the space complexity?

#### Solution:
The space complexity is `O(n)` because the recursion stack grows in proportion to `n` (as the maximum depth of recursion is `n`).

---

### Question 3:
What is the space complexity of an algorithm that uses a 2D array to store intermediate results for dynamic programming (e.g., solving the longest common subsequence problem)?

#### Solution:
The space complexity is `O(n²)` if a `n x n` matrix is used to store results, where `n` is the size of the input.

---

### Question 4:
Determine the space complexity of the following code:
```python
def reverse_string(s):
    return s[::-1]
```

#### Solution:
The space complexity is `O(n)` because the slicing operation creates a new string of size `n` where `n` is the length of the input string.

---

### Question 5:
Consider an algorithm that reads an input array and uses a stack to store elements while processing. What is the space complexity?

#### Solution:
If the stack grows linearly with the input size, the space complexity is `O(n)`.

---

## Conclusion

Space complexity is a vital metric for evaluating how efficiently an algorithm utilizes memory. Understanding the space requirements of algorithms is particularly important in environments with limited memory resources. By analyzing both the fixed and variable parts of an algorithm’s space complexity, one can make informed decisions about which algorithm to use based on the available memory and performance trade-offs.

<center><a href="Time Complexity Analysis.md" target="_blank">Previous</a> 4 <a href="../Array/Array.md" target="_blank">Next</a></center>
