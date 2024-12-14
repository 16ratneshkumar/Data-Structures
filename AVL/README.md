**AVL Tree Documentation**
> It can be implemented using a linked list.

### Definition
An **AVL tree** is a self-balancing binary search tree (BST). Named after its inventors **Adelson-Velsky and Landis**, the AVL tree ensures that the heights of the two child subtrees of any node differ by at most modules one(-1,0,1). If at any time the balance factor exceeds this limit, the tree is rebalanced through rotations.

---

### Properties of AVL Trees
1. **Binary Search Tree Property**:
   - Every node in the left subtree of a node has a key less than the node’s key.
   - Every node in the right subtree of a node has a key greater than the node’s key.

2. **Balance Factor**:
   - Defined as the difference between the heights of the left and right subtrees of a node.
   - For any node, `Balance Factor = Height(left subtree) - Height(right subtree)`.
   - Balance factor must be one of {-1, 0, 1} for the tree to be balanced.

3. **Height Property**:
   - The height of an AVL tree with `n` nodes is O(log n), ensuring efficient operations.

4. **Rotations**:
   - Used to rebalance the tree. Four types of rotations are:
     - **Left Rotation (LL)**
     - **Right Rotation (RR)**
     - **Left-Right Rotation (LR)**
     - **Right-Left Rotation (RL)**

---

### Rotations in AVL Trees
Rotations are used to maintain the balance property of AVL trees.

#### 1. Right Rotation (LL Imbalance)
   - **Condition**: Balance Factor of the node **> 1**, and the Balance Factor of its **left child ≥ 0**.
   - **Reason**: The left subtree is too heavy, and the imbalance is caused by the left child's **left subtree**.

**Algorithm**:
```
RIGHT-ROTATE(y)
1. x ← y.left
2. T2 ← x.right
3. x.right ← y
4. y.left ← T2
5. y.height ← 1 + max(HEIGHT(y.left), HEIGHT(y.right))
6. x.height ← 1 + max(HEIGHT(x.left), HEIGHT(x.right))
7. return x
```

**Code**
```cpp
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    // Return the new root
    return x;
}
```

#### 2. Left Rotation (RR Imbalance)
   - **Condition**: Balance Factor of the node **< -1**, and the Balance Factor of its **right child ≤ 0**.
   - **Reason**: The right subtree is too heavy, and the imbalance is caused by the right child's **right subtree**.

**Algorithm**:
```
LEFT-ROTATE(x)
1. y ← x.right
2. T2 ← y.left
3. y.left ← x
4. x.right ← T2
5. x.height ← 1 + max(HEIGHT(x.left), HEIGHT(x.right))
6. y.height ← 1 + max(HEIGHT(y.left), HEIGHT(y.right))
7. return y
```

**Code**
```cpp
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    // Return the new root
    return y;
}
```

#### 3. Left-Right Rotation (LR Imbalance)
   - **Condition**: Balance Factor of the node **> 1**, and the Balance Factor of its **left child < 0**.
   - **Reason**: The left subtree is too heavy, but the imbalance is caused by the left child's **right subtree**.
   - **Solution**:
     - First, perform a **Left Rotation** on the **left child**.
     - Then, perform a **Right Rotation** on the **node**.

**Algorithm**:
```
LEFT-RIGHT-ROTATE(node)
1. node.left ← LEFT-ROTATE(node.left)
2. result ← RIGHT-ROTATE(node)
3. return result
```

**Code**
```cpp
Node* rotateLeftRight(Node* node) {
    // Perform left rotation on left child
    node->left = rotateLeft(node->left);

    // Perform right rotation on the node
    return rotateRight(node);
}
```

#### 4. Right-Left Rotation (RL Imbalance)
   - **Condition**: Balance Factor of the node **< -1**, and the Balance Factor of its **right child > 0**.
   - **Reason**: The right subtree is too heavy, but the imbalance is caused by the right child's **left subtree**.
   - **Solution**:
     - First, perform a **Right Rotation** on the **right child**.
     - Then, perform a **Left Rotation** on the **node**.
**Algorithm**:
```
RIGHT-LEFT-ROTATE(node)
1. node.right ← RIGHT-ROTATE(node.right)
2. result ← LEFT-ROTATE(node)
3. return result
```

**Code**
```cpp
Node* rotateRightLeft(Node* node) {
    // Perform right rotation on right child
    node->right = rotateRight(node->right);

    // Perform left rotation on the node
    return rotateLeft(node);
}
```
---

### **Imbalance Table**:

| **Imbalance Type**                | **Balance Factor** (Node) | **Balance Factor** (Child) | **Rotation to Apply**     |
|------------------------------------|---------------------------|----------------------------|---------------------------|
| Left-Left (LL) Imbalance           | `> 1`                    | `≥ 0`                     | Right Rotation (RR)       |
| Right-Right (RR) Imbalance         | `< -1`                   | `≤ 0`                     | Left Rotation (LL)        |
| Left-Right (LR) Imbalance          | `> 1`                    | `< 0`                     | Left-Right Rotation (LR)  |
| Right-Left (RL) Imbalance          | `< -1`                   | `> 0`                     | Right-Left Rotation (RL)  |

---

### Operations

#### Search
- Follows the same logic as a binary search tree, comparing the key to the node and moving left or right accordingly.

**Algorithm**
```
AVL-SEARCH(node, key)
1. If node is NULL or node.key = key
2.     return node
3. If key < node.key
4.     return AVL-SEARCH(node.left, key)
5. Else
6.     return AVL-SEARCH(node.right, key)
```

**Code**
```cpp
Node* search(Node* node, int key) {
    if (node == nullptr || node->key == key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}
```

#### Insertion
- Insert the node in the appropriate position as in a BST.
- Check the balance factor of all ancestors of the inserted node.
- Rebalance the tree using rotations if the balance factor is violated.

**Algorithm**
```
AVL-INSERT(node, key)
1. If node is NULL
2.     Create a new node with key and return it
3. If key < node.key
4.     node.left ← AVL-INSERT(node.left, key)
5. Else if key > node.key
6.     node.right ← AVL-INSERT(node.right, key)
7. Else
8.     return node  // Duplicate keys are not allowed
9. Update height of node
10. BalanceFactor ← HEIGHT(node.left) - HEIGHT(node.right)
11. If BalanceFactor > 1 and key < node.left.key
12.     return RIGHT-ROTATE(node)  // Left-Left case
13. If BalanceFactor > 1 and key > node.left.key
14.     node.left ← LEFT-ROTATE(node.left)  // Left-Right case
15.     return RIGHT-ROTATE(node)
16. If BalanceFactor < -1 and key > node.right.key
17.     return LEFT-ROTATE(node)  // Right-Right case
18. If BalanceFactor < -1 and key < node.right.key
19.     node.right ← RIGHT-ROTATE(node.right)  // Right-Left case
20.     return LEFT-ROTATE(node)
21. Return node
```

**Code**
```cpp
Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node{key, nullptr, nullptr, 1}; // Create a new node

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    // Update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getHeight(node->left) - getHeight(node->right);

    // Handle rotations
    if (balance > 1 && key < node->left->key) // Left-Left case
        return rotateRight(node);

    if (balance > 1 && key > node->left->key) { // Left-Right case
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key > node->right->key) // Right-Right case
        return rotateLeft(node);

    if (balance < -1 && key < node->right->key) { // Right-Left case
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}
```

#### Deletion
- Remove the node as in a BST.
- Check and rebalance the tree if the balance factor of any node is violated.

**Algorithm**
```
AVL-DELETE(node, key)
1. If node is NULL
2.     return NULL
3. If key < node.key
4.     node.left ← AVL-DELETE(node.left, key)
5. Else if key > node.key
6.     node.right ← AVL-DELETE(node.right, key)
7. Else
8.     If node.left is NULL
9.         return node.right
10.    Else if node.right is NULL
11.        return node.left
12.    successor ← MINIMUM(node.right)
13.    node.key ← successor.key
14.    node.right ← AVL-DELETE(node.right, successor.key)
15. Update height of node
16. BalanceFactor ← HEIGHT(node.left) - HEIGHT(node.right)
17. If BalanceFactor > 1 and HEIGHT(node.left.left) ≥ HEIGHT(node.left.right)
18.     return RIGHT-ROTATE(node)  // Left-Left case
19. If BalanceFactor > 1 and HEIGHT(node.left.left) < HEIGHT(node.left.right)
20.     node.left ← LEFT-ROTATE(node.left)  // Left-Right case
21.     return RIGHT-ROTATE(node)
22. If BalanceFactor < -1 and HEIGHT(node.right.right) ≥ HEIGHT(node.right.left)
23.     return LEFT-ROTATE(node)  // Right-Right case
24. If BalanceFactor < -1 and HEIGHT(node.right.right) < HEIGHT(node.right.left)
25.     node.right ← RIGHT-ROTATE(node.right)  // Right-Left case
26.     return LEFT-ROTATE(node)
27. Return node
```

**Code**
```cpp
Node* deleteNode(Node* node, int key) {
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == nullptr)
            return node->right;
        else if (node->right == nullptr)
            return node->left;

        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }

    // Update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getHeight(node->left) - getHeight(node->right);

    // Handle rotations
    if (balance > 1 && getHeight(node->left->left) >= getHeight(node->left->right)) // Left-Left case
        return rotateRight(node);

    if (balance > 1 && getHeight(node->left->left) < getHeight(node->left->right)) { // Left-Right case
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getHeight(node->right->right) >= getHeight(node->right->left)) // Right-Right case
        return rotateLeft(node);

    if (balance < -1 && getHeight(node->right->right) < getHeight(node->right->left)) { // Right-Left case
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}
```

#### Traversal
- AVL trees support in-order, pre-order, post-order, and level-order traversals.

**Algorithm: IN-ORDER TRAVERSAL**
```
INORDER(node)
1. If node is NOT NULL
2.     INORDER(node.left)
3.     PRINT node.key
4.     INORDER(node.right)
```

**Code**
```cpp
void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    std::cout << node->key << " ";
    inOrder(node->right);
}
```


**Algorithm: PRE-ORDER TRAVERSAL**
```
PREORDER(node)
1. If node is NOT NULL
2.     PRINT node.key
3.     PREORDER(node.left)
4.     PREORDER(node.right)
```

**Code**
```cpp
void preOrder(Node* node) {
    if (node == nullptr)
        return;

    std::cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}
```


**Algorithm: POST-ORDER TRAVERSAL**
```
POSTORDER(node)
1. If node is NOT NULL
2.     POSTORDER(node.left)
3.     POSTORDER(node.right)
4.     PRINT node.key
```
**Code**
```cpp
void postOrder(Node* node) {
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->key << " ";
}
```


**Algorithm**
```
LEVELORDER(root)
1. If root is NULL
2.     return
3. Create an empty queue Q
4. ENQUEUE(root)
5. While Q is NOT EMPTY
6.     node ← DEQUEUE(Q)
7.     PRINT node.key
8.     If node.left is NOT NULL
9.         ENQUEUE(node.left)
10.    If node.right is NOT NULL
11.        ENQUEUE(node.right)
```

**Code**
```cpp
#include <queue>

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        std::cout << node->key << " ";

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}
```
---

### **Traversal Table**:

| Traversal Type  | Order of Processing (Root, Left, Right)            |
|------------------|---------------------------------------------------|
| **In-Order**     | Left → Root → Right                              |
| **Pre-Order**    | Root → Left → Right                              |
| **Post-Order**   | Left → Right → Root                              |
| **Level-Order**  | Nodes visited level-by-level from top to bottom  |

---

### Time Complexities

| Operation      | Time Complexity |
|----------------|-----------------|
| Search         | O(log n)        |
| Insert         | O(log n)        |
| Delete         | O(log n)        |
| Traversal      | O(n)            |


---

### Applications of AVL Trees
1. **Databases**:
   - Used for indexing and maintaining a balanced structure for faster retrieval.
2. **File Systems**:
   - Helps in efficient organization of directories and files.
3. **Search Operations**:
   - Suitable for applications requiring frequent searches due to its logarithmic height.
4. **Network Routing**:
   - AVL trees can store routing tables where balanced height ensures quick updates and lookups.
5. **Memory Management**:
   - Used in memory allocation systems to manage free blocks efficiently.


---

### Advantages of AVL Trees
1. **Guaranteed Balance**:
   - Ensures O(log n) time complexity for search, insertion, and deletion.
2. **Faster Lookups**:
   - Compared to unbalanced trees, AVL trees provide quicker search times due to their height guarantee.
3. **Automatic Self-Balancing**:
   - Dynamically adjusts itself to remain balanced after insertions and deletions.


---

### Disadvantages of AVL Trees
1. **Complex Rotations**:
   - Rotations during insertion and deletion add overhead and complexity.
2. **Memory Overhead**:
   - Requires additional space for storing height information and managing rotations.
3. **Not Suitable for All Workloads**:
   - Insertion and deletion are slower compared to simpler BSTs when rebalancing is frequently required.
4. **Limited Efficiency in Static Datasets**:
   - For datasets that do not change often, simpler data structures like standard BSTs or arrays may suffice.

---