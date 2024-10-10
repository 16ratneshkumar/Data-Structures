# Linked List
- A linked list is a linear data structure where elements, known as nodes, are stored in a sequence, but they are not stored in contiguous memory locations like arrays. Instead, each node contains a reference (or a link) to the next node in the sequence. This linking forms a chain-like structure, making it easy to add or remove elements dynamically without needing to reallocate or shift elements.

## Key Components of a Linked List:

   1. **Node**: Each element in a linked list is represented as a node. A node typically contains:

       - **Data**: The value or information stored in the node.

       - **Next**: A reference (or address) to the next node in the sequence.

   2. **Head**: The first node in the linked list. If the list is empty, the head points to *null*.

   3. **Tail**: In some implementations, a tail pointer might be maintained to keep track of the last node for efficient insertion at the end.

---

## Types of Linked Lists:

   - [**Singly Linked List**](#singly-linked-list): <details><summary>Each node contains the address of the next node.</summary>In a **singly linked list**, each node has two parts: one part stores the data, and the other part holds the address of the next node in the sequence. You can only move in one direction, starting from the first node (head) and following the addresses until you reach the last node, which doesn't point to any other node.</details>
   

   - [**Doubly Linked List**](#double-linked-list): <details><summary>Each node contains two addresses: one to the next node and one to the previous node.</summary>In a **doubly linked list**, each node has three parts: one part stores the data, one part holds the address of the next node, and the other holds the address of the previous node. This lets you move both forward and backward through the list.</details>

   - [**Circular Linked List**](#circular-linked-list): <details><summary>The last node contains the address of the first node, forming a circular chain.</summary>In a circular linked list, the last node is connected back to the first node, so there's no natural end. This structure can be either singly or doubly linked, and it's useful when you need to cycle through the nodes repeatedly.</details>

---

## Singly Linked List:

- A **singly linked list** is the simplest form of a linked list where each node points to the next node in the sequence. It only allows traversal in one direction, starting from the head node and moving toward the tail.

- Structure of a Node in a Singly Linked List:
    ```plaintext
    +---------+--------+
    |   Data  |  Next  | 
    +---------+--------+
    ```

- **Example**:

    > Head → [10 | Next] → [20 | Next] → [30 | Null]

- Here, each node points to the next one, and the last node's pointer (Next) is *Null*, indicating the end of the list.

### Operations in a Singly Linked List:

1. **Traversal**:
    - Visiting each node in the list sequentially, starting from the head and moving toward the tail.
    - **Time Complexity**: O(n)


2. **Insertion**:

    - **At the beginning**:
        - Insert a new node before the current head node and update the head pointer to this new node.
        - **Time Complexity**: O(1)

    - **At the end**:
        - Traverse to the last node and update its Next pointer with new node.
        - **Time Complexity**: O(n)

    - **At a specific position**:
        - Traverse to the desired position and insert the new node.
        - **Time Complexity**: O(n)




3. **Deletion**:

    - **From the beginning**:
        - Remove the head node and update the head.
        - **Time Complexity**: O(1)

    - **From the end**:
        - Traverse to the second-last node and update its Next pointer to *Null*.
        - **Time Complexity**: O(n)

    - **From a specific position**:
        - Traverse to the node before the one to be deleted and update the pointer.
        - **Time Complexity**: O(n)

### Advantages of Singly Linked Lists:

   - **Dynamic Size**: They can grow or shrink at runtime without requiring any reallocation.

   - **Efficient Insertions/Deletions**: Inserting or deleting at the beginning or end is efficient as no shifting of elements is required (unlike arrays).


### Disadvantages:

   - **No Backward Traversal**: Since each node only has a reference to the next node, traversal can only be done in one direction.

   - **Higher Memory Usage**: Each node requires extra memory for the Next pointer.

   - **Access Time**: Random access is not possible; to access a node, you need to traverse the list from the head.


