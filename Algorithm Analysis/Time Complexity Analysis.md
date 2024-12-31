# Time Complexity:

## Introduction

Time complexity is a computational complexity concept that helps us understand how the runtime of an algorithm scales with the size of the input. In simple terms, time complexity gives us an idea of how the algorithm's performance grows as the input grows. 

Understanding time complexity is crucial for evaluating the efficiency of algorithms, particularly when dealing with large datasets or limited resources in environments such as embedded systems, web applications, and data processing systems.

---

## What is Time Complexity?

### Definition:
> Time complexity is the measure of the time an algorithm takes to complete as a function of the input size `n`. This is typically expressed using **Big O notation** (e.g., `O(n)`, `O(log n)`, `O(n²)`), which provides an upper bound on the time needed.

> Time complexity helps us abstract away the specifics of hardware, software, and other factors, focusing purely on the algorithm's efficiency in terms of input growth.

#### Example:
   1. For an algorithm that prints every element in an array of size `n`, the time complexity is `O(n)` because the runtime increases linearly with the size of the array.

---

## How to Calculate Time Complexity?

To calculate time complexity, focus on the most significant operations of an algorithm. Here's a step-by-step approach:

1. **Identify the basic operations** that dominate the execution time (loops, recursive calls, etc.).
2. **Count how many times these basic operations execute** as a function of the input size `n`.
3. **Express the time complexity in terms of Big O notation**, focusing on the dominant terms (terms that grow the fastest as `n` increases).

### Basic Operations:
- Assignment operations
- Comparisons (e.g., `if` statements)
- Arithmetic operations (e.g., addition, multiplication)
- Function calls (especially recursive calls)
- Loops (each iteration counts)

### Rule of Thumb:
1. Ignore lower-order terms (e.g., drop constants like `O(3n + 5)` becomes `O(n)`).
2. Focus on the highest-order term, as it dominates the growth for large `n`.

#### Example:
```python
def example_algorithm(arr):
    n = len(arr)       # 1 operation
    for i in range(n):  # Loop runs n times
        print(arr[i])   # 1 operation per loop iteration
```
Here, the loop runs `n` times, and each iteration performs one operation. Thus, the total time complexity is `O(n)`.

---

## Types of Time Complexity

### 1. **Constant Time (`O(1)`)**
An algorithm has constant time complexity if it performs a fixed number of operations regardless of the input size.

#### Example:
```python
def constant_time_algorithm(arr):
    return arr[0]
```
This function accesses the first element of the array, which is a constant-time operation. Therefore, its time complexity is `O(1)`.

### 2. **Linear Time (`O(n)`)**
An algorithm has linear time complexity if its runtime grows in direct proportion to the input size.

#### Example:
```python
def linear_time_algorithm(arr):
    for i in arr:
        print(i)
```
This function iterates through each element of the array, performing a single operation per element. Hence, its time complexity is `O(n)`.

### 3. **Logarithmic Time (`O(log n)`)**
An algorithm has logarithmic time complexity if its runtime grows logarithmically as the input size increases. This often occurs when the problem size is halved at each step.

#### Example:
```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```
In binary search, the array is halved at each iteration, leading to logarithmic time complexity `O(log n)`.

### 4. **Quadratic Time (`O(n²)`)**
An algorithm has quadratic time complexity if its runtime grows as the square of the input size. This often occurs with nested loops.

#### Example:
```python
def quadratic_time_algorithm(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n):
            print(arr[i], arr[j])
```
This algorithm has two nested loops, each iterating `n` times, leading to a time complexity of `O(n²)`.

### 5. **Cubic Time (`O(n³)`)**
An algorithm has cubic time complexity if its runtime grows as the cube of the input size. This occurs with three nested loops.

#### Example:
```python
def cubic_time_algorithm(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                print(arr[i], arr[j], arr[k])
```
With three nested loops, the time complexity becomes `O(n³)`.

### 6. **Exponential Time (`O(2^n)`)**
An algorithm has exponential time complexity if its runtime doubles with each additional input. This typically occurs in brute-force algorithms that explore all possibilities.

#### Example:
```python
def exponential_time_algorithm(n):
    if n == 0:
        return 1
    return 2 * exponential_time_algorithm(n - 1)
```
Each recursive call makes two new recursive calls, resulting in an exponential time complexity of `O(2^n)`.

### 7. **Factorial Time (`O(n!)`)**
An algorithm has factorial time complexity if its runtime grows as the factorial of the input size. This often happens in problems that involve generating all permutations or combinations.

#### Example:
```python
def factorial_time_algorithm(n):
    if n == 1:
        return 1
    return n * factorial_time_algorithm(n - 1)
```
In this recursive factorial function, the time complexity is `O(n!)`.

---

## Best, Worst, and Average Case Time Complexities

1. **Worst Case**:
   - The maximum time an algorithm could take to complete.
   - Example: In linear search, the worst case happens when the target element is not present, leading to a time complexity of `O(n)`.

2. **Best Case**:
   - The minimum time an algorithm could take to complete.
   - Example: In linear search, the best case happens when the target element is the first element, leading to a time complexity of `O(1)`.

3. **Average Case**:
   - The expected time for the algorithm to complete for a typical input.
   - Example: In linear search, the average case happens when the target element is located near the middle of the array, leading to a time complexity of `O(n/2)`, which simplifies to `O(n)`.

---

## Common Time Complexities

| Time Complexity | Name            | Example Algorithms                         |
|-----------------|-----------------|--------------------------------------------|
| `O(1)`          | Constant        | Accessing an array element, swapping two variables |
| `O(log n)`      | Logarithmic     | Binary search                              |
| `O(n)`          | Linear          | Linear search, simple for loop             |
| `O(n log n)`    | Linearithmic    | Merge sort, quicksort (average case)       |
| `O(n²)`         | Quadratic       | Bubble sort, selection sort, insertion sort |
| `O(2^n)`        | Exponential     | Solving the subset sum problem via brute force |
| `O(n!)`         | Factorial       | Generating all permutations of a string    |

---

## Time Complexity of Common Algorithms

### 1. **Linear Search**:
   - Time complexity: `O(n)` in the worst case, since we may need to check all elements in the array.

### 2. **Binary Search**:
   - Time complexity: `O(log n)` in the best, worst, and average cases since the array is halved at each step.

### 3. **Merge Sort**:
   - Time complexity: `O(n log n)` for all cases (best, average, and worst).

### 4. **Quick Sort**:
   - Time complexity: `O(n log n)` on average, but `O(n²)` in the worst case (when the pivot is poorly chosen).

### 5. **Bubble Sort**:
   - Time complexity: `O(n²)` in the worst case, as it involves two nested loops.

### 6. **Depth First Search (DFS)**:
   - Time complexity: `O(V + E)` where `V` is the number of vertices and `E` is the number of edges.

### 7. **Breadth First Search (BFS)**:
   - Time complexity: `O(V + E)` for traversing all nodes and edges.

---

## Practice Problems

### Problem 1:
What is the time complexity of the following code?

```python
def find_max(arr):
    max_value = arr[0]
    for i in arr:
        if i > max_value:
            max_value = i
    return max_value
```
#### Solution:
The algorithm checks every element of the array once. Therefore, the time complexity is `O(n)`.

---

### Problem 2:
Analyze the time complexity of this nested loop:

```python
def print_pairs(arr):
    n = len(arr)
    for i in range(n):
        for j in range


        
## Practice Questions

### Question 1:
What is the time complexity of the following code?
```python
for i in range(n):
    for j in range(i, n):
        print(i, j)
```

#### Solution:
The outer loop runs `n` times, and for each iteration `i` of the outer loop, the inner loop runs `n - i` times. The total number of operations is the sum:
\[ n + (n-1) + (n-2) + \ldots + 1 = \frac{n(n+1)}{2} = O(n²) \]
Thus, the time complexity is `O(n²)`.

---

### Question 2:
Determine the time complexity of the following algorithm:
```python
for i in range(n):
    print("Hello")
```

#### Solution:
The loop runs `n` times, and each iteration prints a message. Hence, the time complexity is `O(n)`.

---

### Question 3:
Consider a binary search algorithm. What is its time complexity, and why?

#### Solution:
Binary search divides the search space in half with each iteration. Therefore, the time complexity is logarithmic, `O(log n)`, as the problem size is halved with each step.

---

### Question 4:
What is the time complexity of the following recursive function?
```python
def rec_func(n):
    if n <= 1:
        return 1
    else:
        return rec_func(n-1) + rec_func(n-1)
```

#### Solution:
The recursive function calls itself twice for each `n`, leading to an exponential growth in the number of function calls. The time complexity is `O(2^n)`.

---

### Question 5:
Find the time complexity of the following algorithm:
```python
def algorithm(n):
    i = 1
    while i < n:
        i *= 2
```

#### Solution:
The variable `i` is doubled each time, so the loop runs approximately `log n` times. Therefore, the time complexity is `O(log n)`.

---
<center><a href="Asymptotic Notation.md" target="_blank">Previous</a> 3 <a href="Space Complexity Analysis.md" target="_blank">Next</a></center>