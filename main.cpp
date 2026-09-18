#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/*
    DSA-II PBL PROJECT
    Project: College Event Seat and Pass Management System

    Concepts used from the report:
    Unit 1 - Trees:
      1. Binary Search Tree (BST)
      2. AVL Tree
      3. Heap / Max Heap
      4. Tree Traversal

    Unit 2 - Graphs:
      5. Graph
      6. Adjacency Matrix
      7. Adjacency List
*/

// ---------------- Student Record ----------------
struct Student {
    int id;
    string name;
    string event;
};

// ---------------- 1. Binary Search Tree ----------------
struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student s) {
        data = s;
        left = right = nullptr;
    }
};

class StudentBST {
    BSTNode* root = nullptr;

    BSTNode* insert(BSTNode* node, Student s) {
        if (node == nullptr)
            return new BSTNode(s);

        if (s.id < node->data.id)
            node->left = insert(node->left, s);
        else if (s.id > node->data.id)
            node->right = insert(node->right, s);

        return node;
    }

    BSTNode* search(BSTNode* node, int id) {
        if (node == nullptr || node->data.id == id)
            return node;

        if (id < node->data.id)
            return search(node->left, id);

        return search(node->right, id);
    }

    void inorder(BSTNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << "Student ID: " << node->data.id
             << " | Name: " << node->data.name
             << " | Event: " << node->data.event << endl;
        inorder(node->right);
    }

public:
    void insert(Student s) {
        root = insert(root, s);
    }

    void searchStudent(int id) {
        BSTNode* result = search(root, id);

        if (result != nullptr)
            cout << "Student found: " << result->data.name
                 << " | Event: " << result->data.event << endl;
        else
            cout << "Student not found.\n";
    }

    void showInorder() {
        cout << "\n--- BST Inorder Traversal ---\n";
        inorder(root);
    }
};

// ---------------- 2. AVL Tree ----------------
struct AVLNode {
    Student data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Student s) {
        data = s;
        left = right = nullptr;
        height = 1;
    }
};

class StudentAVL {
    AVLNode* root = nullptr;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* t = x->right;

        x->right = y;
        y->left = t;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode* insert(AVLNode* node, Student s) {
        if (node == nullptr)
            return new AVLNode(s);

        if (s.id < node->data.id)
            node->left = insert(node->left, s);
        else if (s.id > node->data.id)
            node->right = insert(node->right, s);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // LL
        if (balance > 1 && s.id < node->left->data.id)
            return rightRotate(node);

        // RR
        if (balance < -1 && s.id > node->right->data.id)
            return leftRotate(node);

        // LR
        if (balance > 1 && s.id > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && s.id < node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preorder(AVLNode* node) {
        if (node == nullptr)
            return;

        cout << node->data.id << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    void insert(Student s) {
        root = insert(root, s);
    }

    void showPreorder() {
        cout << "\n--- AVL Preorder Traversal ---\n";
        preorder(root);
        cout << endl;
    }
};

// ---------------- 3. Max Heap ----------------
struct Registration {
    int studentId;
    string name;
    int priority;

    bool operator<(const Registration& other) const {
        return priority < other.priority;
    }
};

class RegistrationMaxHeap {
    priority_queue<Registration> heap;

public:
    void addRegistration(int id, string name, int priority) {
        heap.push({id, name, priority});
    }

    bool empty() {
        return heap.empty();
    }

    Registration getHighestPriority() {
        Registration r = heap.top();
        heap.pop();
        return r;
    }

    void showRegistrations() {
        priority_queue<Registration> copy = heap;

        cout << "\n--- Registration Priority Queue ---\n";

        while (!copy.empty()) {
            Registration r = copy.top();
            copy.pop();

            cout << "Student ID: " << r.studentId
                 << " | Name: " << r.name
                 << " | Priority: " << r.priority << endl;
        }
    }
};

// ---------------- 4. Seat Allocation ----------------
class EventSeats {
    int totalSeats;
    vector<bool> booked;

public:
    EventSeats(int seats) {
        totalSeats = seats;
        booked.resize(seats + 1, false);
    }

    int allocateSeat() {
        for (int i = 1; i <= totalSeats; i++) {
            if (!booked[i]) {
                booked[i] = true;
                return i;
            }
        }
        return -1;
    }

    void showSeats() {
        cout << "\n--- Event Seat Status ---\n";

        for (int i = 1; i <= totalSeats; i++) {
            cout << "Seat " << i << ": "
                 << (booked[i] ? "Allocated" : "Available")
                 << endl;
        }
    }
};

// ---------------- 5. Graph with Matrix and List ----------------
class EventGraph {
    int n;
    vector<string> events;
    vector<vector<int>> matrix;
    vector<vector<int>> adjacencyList;

public:
    EventGraph(vector<string> eventNames) {
        events = eventNames;
        n = events.size();

        matrix.resize(n, vector<int>(n, 0));
        adjacencyList.resize(n);
    }

    void addConnection(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n || u == v)
            return;

        matrix[u][v] = 1;
        matrix[v][u] = 1;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void showMatrix() {
        cout << "\n--- Adjacency Matrix ---\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    void showList() {
        cout << "\n--- Adjacency List ---\n";

        for (int i = 0; i < n; i++) {
            cout << events[i] << " -> ";

            for (int v : adjacencyList[i])
                cout << events[v] << " ";

            cout << endl;
        }
    }

    void checkConnection(int source, int destination) {
        if (source < 0 || destination < 0 ||
            source >= n || destination >= n) {
            cout << "Invalid event number.\n";
            return;
        }

        if (matrix[source][destination] == 1)
            cout << "Connection exists between "
                 << events[source] << " and "
                 << events[destination] << endl;
        else
            cout << "No direct connection between "
                 << events[source] << " and "
                 << events[destination] << endl;
    }
};

// ---------------- Main Program ----------------
int main() {

    cout << "============================================\n";
    cout << " COLLEGE EVENT SEAT AND PASS MANAGEMENT\n";
    cout << "               SYSTEM\n";
    cout << "============================================\n";

    vector<Student> students = {
        {103, "Rahul", "Tech Fest"},
        {101, "Amit", "Coding Workshop"},
        {105, "Neha", "Cultural Event"},
        {102, "Priya", "Tech Fest"},
        {104, "Ravi", "Coding Workshop"}
    };

    // ==========================================
    // UNIT 1 - BINARY SEARCH TREE
    // ==========================================
    StudentBST bst;

    for (Student s : students)
        bst.insert(s);

    bst.showInorder();

    cout << "\nSearching Student ID 102:\n";
    bst.searchStudent(102);

    // ==========================================
    // UNIT 1 - AVL TREE
    // ==========================================
    StudentAVL avl;

    for (Student s : students)
        avl.insert(s);

    avl.showPreorder();

    // ==========================================
    // UNIT 1 - MAX HEAP + SEAT ALLOCATION
    // ==========================================
    RegistrationMaxHeap registrations;

    registrations.addRegistration(103, "Rahul", 2);
    registrations.addRegistration(101, "Amit", 5);
    registrations.addRegistration(105, "Neha", 3);
    registrations.addRegistration(102, "Priya", 4);

    registrations.showRegistrations();

    EventSeats seats(4);

    cout << "\n--- Seat Allocation by Priority ---\n";

    while (!registrations.empty()) {
        Registration r = registrations.getHighestPriority();
        int seat = seats.allocateSeat();

        if (seat != -1) {
            cout << r.name << " (Priority "
                 << r.priority << ") -> Seat "
                 << seat << endl;
        } else {
            cout << r.name
                 << " -> Waiting List (No Seat Available)"
                 << endl;
        }
    }

    seats.showSeats();

    // ==========================================
    // UNIT 2 - GRAPH
    // ==========================================
    vector<string> events = {
        "TechFest",
        "Coding",
        "Cultural",
        "Workshop",
        "Seminar"
    };

    EventGraph graph(events);

    graph.addConnection(0, 1);
    graph.addConnection(0, 2);
    graph.addConnection(1, 3);
    graph.addConnection(2, 4);
    graph.addConnection(3, 4);

    graph.showMatrix();
    graph.showList();

    cout << "\n--- Event Connection Query ---\n";
    graph.checkConnection(0, 1);
    graph.checkConnection(0, 4);

    cout << "\n============================================\n";
    cout << "              END OF PROTOTYPE\n";
    cout << "============================================\n";

    return 0;
}
