# Asymptotic Notation

## Introduction

Asymptotic notation is a mathematical tool used to describe the limiting behavior of a function as the input size approaches infinity. It is widely used in computer science to evaluate the time and space complexities of algorithms, focusing on how they scale with larger inputs. The primary asymptotic notations include Big O (`O`), Omega (`Ω`), and Theta (`Θ`), each providing different bounds on an algorithm’s complexity.

---

## Types of Asymptotic Notation

### 1. **Big O Notation (`O`)** – Upper Bound

Big O notation represents an upper bound on the growth rate of a function. It is primarily used to describe the worst-case scenario of an algorithm.

#### Definition:
> Let `f(n)` and `g(n)` be two functions. We say: 𝑓(𝑛)=𝑂(𝑔(𝑛)) if and only if there exist positive constants `c` and `n_0` such that:𝑓(𝑛)≤𝑐⋅𝑔(𝑛)  ∀𝑛≥𝑛<sub>0</sub>​


#### Example:
1. Consider a sorting algorithm like Bubble Sort, which has a time complexity of `n² + n + 2`. The Big O for this algorithm is `O(n²)` because, as `n` increases, the `n²` term dominates the others.
2. A linear search through an array has a time complexity of `O(n)`, where `n` is the number of elements in the array.

#### More Examples of Big O:
- Constant time complexity: `O(1)` (e.g., accessing an array element by index)
- Logarithmic time complexity: `O(log n)` (e.g., binary search)
- Linearithmic time complexity: `O(n log n)` (e.g., Merge Sort)
- Quadratic time complexity: `O(n²)` (e.g., Bubble Sort, Insertion Sort) and so on.

---

### 2. **Omega Notation (`Ω`)** – Lower Bound

Omega notation represents the lower bound of an algorithm. It describes the minimum time or space complexity required for an algorithm to complete.

#### Definition:
> Let `f(n)` and `g(n)` be two functions. We say: 𝑓(𝑛)=Ω(𝑔(𝑛)) if and only if there exist positive constants `c` and `n_0` such that: 𝑓(𝑛)≥𝑐⋅𝑔(𝑛)  ∀𝑛≥𝑛<sub>0</sub>

#### Example:
1. In a best-case scenario, Quick Sort operates with a time complexity of `Ω(n log n)`, though its worst-case complexity is `O(n²)`.

---

### 3. **Theta Notation (`Θ`)** – Tight Bound

Theta notation defines both an upper and a lower bound, providing a tight bound on the growth of a function.

#### Definition:
> Let `f(n)` and `g(n)` be two functions. We say: 𝑓(𝑛)=Θ(𝑔(𝑛)) if and only if there exist positive constants `c_1`, `c_2`, and `n_0` such that:  𝑐<sub>1</sub>⋅𝑔(𝑛)≤𝑓(𝑛)≤𝑐<sub>2</sub>⋅𝑔(𝑛)  ∀𝑛≥𝑛<sub>0</sub>


#### Example:
1. The time complexity of the Merge Sort algorithm is `Θ(n log n)` in both the worst and average cases, meaning its running time grows at the rate of `n log n`.

#### More Examples of Theta Notation:
- Linear time complexity: `Θ(n)` (e.g., iterating through a list once)
- Quadratic time complexity: `Θ(n²)` (e.g., nested loops, Matrix Multiplication)

---

## Other Asymptotic Notations

### **Little O Notation (`o`)**:
Little O represents an upper bound that is not tight, meaning `f(n)` grows strictly slower than `g(n)`.

#### Definition:
> Let `f(n)` and `g(n)` be two functions. We say: 𝑓(𝑛)=𝑜(𝑔(𝑛))  if, for every constant `c > 0`, there exists an `n_0` such that:𝑓(𝑛)<𝑐⋅𝑔(𝑛)    ∀𝑛≥𝑛<sub>0</sub>

#### Example:
If `f(n) = n` and `g(n) = n²`, then `f(n) = o(n²)` because `n` grows slower than `n²`.

### **Little Omega Notation (`ω`)**:
Little Omega describes a lower bound that is not tight, meaning `f(n)` grows strictly faster than `g(n)`.

#### Definition:
> Let `f(n)` and `g(n)` be two functions. We say: 𝑓(𝑛)=𝜔(𝑔(𝑛)) if, for every constant `c > 0`, there exists an `n_0` such that:𝑓(𝑛)>𝑐⋅𝑔(𝑛)    ∀𝑛≥𝑛<sub>0</sub>


#### Example:
If `f(n) = n²` and `g(n) = n`, then `f(n) = 𝜔(n)` because `n²` grows faster than `n`.

---

## Examples of Asymptotic Notations for Common Algorithms

1. **Linear Search**:
   - Best case: `Ω(1)` (if the target is the first element)
   - Worst case: `O(n)` (if the target is the last element or not present)

2. **Binary Search**:
   - Best case: `Ω(1)` (if the target is the middle element)
   - Worst and average case: `O(log n)` (halving the search space each time)

3. **Bubble Sort**:
   - Best case: `Ω(n)` (if the array is already sorted)
   - Worst and average case: `O(n²)` (due to nested loops)

4. **Merge Sort**:
   - Best, worst, and average case: `Θ(n log n)` (dividing the array into halves and merging them back)

5. **Insertion Sort**:
   - Best case: `Ω(n)` (if the array is already sorted)
   - Worst and average case: `O(n²)` (if the array is in reverse order)

---


## Conclusion

Asymptotic notation is an essential tool for evaluating the efficiency of algorithms, helping developers and engineers determine their scalability and performance for large input sizes. Understanding Big O, Omega, and Theta notations enables one to make informed decisions when choosing or optimizing algorithms. With practice and real-world application, you can apply these concepts effectively to design efficient algorithms.



<center><a href="Growth Function.md" target="_blank">Previous</a> 2 <a href="Time Complexity Analysis.md" target="_blank">Next</a></center>