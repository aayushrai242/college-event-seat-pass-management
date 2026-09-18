# College Event Seat and Pass Management System

## DSA-II PBL Project

This project demonstrates the application of Data Structures and Algorithms to a **College Event Seat and Pass Management System**.

The prototype manages student registrations, event information, seat allocation and relationships between events. It uses the DSA concepts identified in the PBL report.

## DSA Concepts Used

### 1. Binary Search Tree (BST)
Student registration records are organized using student IDs. BST supports ordered storage and searching of student records.

**Time Complexity:** O(log n) average search/insert; O(n) in the worst case.

### 2. AVL Tree
An AVL Tree maintains balanced student registration records and supports efficient searching.

**Time Complexity:** O(log n) for search and insertion.

### 3. Heap / Max Heap
A Max Heap processes registrations according to priority. Higher-priority registrations are processed first.

**Time Complexity:** O(log n) for insertion and deletion; O(1) for accessing the highest-priority element.

### 4. Tree Traversal
Inorder and preorder traversal are used to systematically process tree-based student information.

**Time Complexity:** O(n).

### 5. Graph
A graph represents relationships between college events.

**Time Complexity:** O(V + E) for traversal/processing with an adjacency list.

### 6. Adjacency Matrix
An adjacency matrix stores direct connections between events.

**Time Complexity:** O(1) for checking a direct connection; O(V²) space.

### 7. Adjacency List
An adjacency list stores the connected events for each event.

**Time Complexity:** O(V + E) space.

## Project Features

- Student registration management
- Student searching using BST
- Balanced registration records using AVL Tree
- Priority-based registration processing using Max Heap
- Event seat allocation
- Tree traversal
- Event relationship representation using Graph
- Adjacency Matrix representation
- Adjacency List representation
- Direct event connection query

## Technologies Used

- C++
- Data Structures and Algorithms

## Project Structure

```text
college-event-seat-pass-management/
│
├── main.cpp
└── README.md
```

## How the Prototype Works

1. Student registration records are inserted into a Binary Search Tree.
2. A student can be searched using the BST.
3. The same student records are inserted into an AVL Tree to demonstrate balanced organization.
4. Registration requests are inserted into a Max Heap according to priority.
5. Available event seats are allocated to higher-priority registration requests first.
6. Events are represented as vertices of a graph.
7. Connections between events are represented using an Adjacency Matrix and an Adjacency List.
8. A connection query checks whether a direct relationship exists between two events.

## Compilation and Execution

```bash
g++ -std=c++17 main.cpp -o event
./event
```

## Project Scope

This is a prototype implementation based on the DSA concepts identified in the PBL report. The graph part demonstrates graph representation using an Adjacency Matrix and Adjacency List.

## PBL Details

**Project Title:** College Event Seat and Pass Management System  
**Course:** Data Structure and Algorithms – II  
**Course Code:** CCSE0301  
**Student:** Aayush Rai
