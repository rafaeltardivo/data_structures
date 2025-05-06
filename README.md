# Data Structures Implementation

This repository contains implementations of various data structures in C, each with its own set of operations and features.

## Data Structures

### 1. Binary Search Tree (`binary_search_tree.c`)
- Operations:
  - Insert nodes
  - Delete nodes
  - Search for values
  - Traversal (pre-order, in-order, post-order)
  - Check if tree is empty
  - Clear tree

### 2. Queue (`queue.c`)
- Operations:
  - Enqueue elements
  - Dequeue elements
  - Check if queue is empty
  - Display front and rear elements
  - Display all elements
  - Clear queue

### 3. Stack (`stack.c`)
- Operations:
  - Push elements
  - Pop elements
  - Check if stack is empty
  - Display top element
  - Display all elements
  - Clear stack

### 4. Doubly Linked List (`doubly_linked_list.c`)
- Operations:
  - Insert nodes (at front, rear, or after a specific node)
  - Delete nodes
  - Display elements (forward and reverse)
  - Check if list is empty
  - Clear list

### 5. Magic Square (`magic_square.c` and `magic_square_bubble_sliding.c`)
- Features:
  - 4x4 magic square validation
  - Check for repeated numbers
  - Verify line, column, and diagonal sums
  - Display square

### 6. Queue to Stack Transfer (`queue_transfer_stack.c`)
- Operations:
  - Insert elements
  - Remove elements
  - Transfer elements between queue and stack
  - Display elements
  - Clear container

### 7. Singly Linked List (`singly_linked_list.c`)
- Operations:
  - Insert nodes (at front, rear, or after a specific node)
  - Delete nodes
  - Display elements
  - Check if list is empty
  - Clear list

### 8. Sorted Circular Linked List (`sorted_circular_linked_list.c`)
- Operations:
  - Insert nodes in sorted order
  - Delete nodes
  - Display elements
  - Check if list is empty
  - Clear list

## Compilation

To compile any of these programs, use:
```bash
gcc filename.c -o output_name
```

## Usage

Each program provides a menu-driven interface for interacting with the data structure. Follow the on-screen prompts to perform operations.

## Features

- Memory-safe implementations
- Error handling for edge cases
- User-friendly interfaces
- Standard C compliance
- Comprehensive operation sets for each data structure

## Notes

- All programs use standard C libraries
- Memory management is handled carefully to prevent leaks
- Input validation is implemented where necessary
- Programs follow consistent coding style and error handling patterns
