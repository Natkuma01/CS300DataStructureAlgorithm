//===============================================================================
// Name         : Project_Two.cpp
// Author       : Shimin Chan
// Description  : CS300 DSA: Analysis and Design - Project Two
// Date         : 8/16/2026
//===============================================================================
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>



using namespace std;

// represent a single course structure
struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;

    Course() = default;
};

// define strucutre for a node in the Binary Search Tree
struct Node {
    Course course;
    Node* right;
    Node* left;

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

// Define the Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    void destroyTree(Node* node);
    void insert(Node*& node, Course course);
    void inOrder(Node* node);
    Course* search(Node* node, string courseNumber);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void Insert(Course course);
    void PrintAll();
    Course* Search(string courseNumber);

};

// Default contructor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

// recursively destroys the tree to free up the memory
void BinarySearchTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// public method to insert a course
void BinarySearchTree::Insert(Course course) {
    insert(this->root, course);
}

// private recursive method to insert a course into the courseTree
void BinarySearchTree::insert(Node*& node, Course course) {
    
    // when the tree/ subtree is empty, this becomes the new root
    if (node == nullptr) {
        node = new Node(course);
    }
    // if the new course number is less, go to the left subtree
    else if (course.courseNumber < node->course.courseNumber) {
        insert(node->left, course);
    }
    // otherwise (means the course number is larger, then go to the right subtree)
    else {
        insert(node->right, course);
    }
}

// public method to print all courses in order
void BinarySearchTree::PrintAll() {
    cout << "\n------------Course List-------------------" << endl;
    this->inOrder(this->root);
    cout << "------------------------------------------" << endl;
}

// private recursive method for in-order traversal to print courses.
void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->course.courseNumber << ": " << node->course.title << endl;
        inOrder(node->right);
    }
}

// Display  the details of a single course
void displayCourse(const Course* course) {
    if (course == nullptr) {
        cout << "Course not found." << endl;
        return;
    }
    cout << "\n------------Course Information-------------------" << endl;
    cout << "Course Number: " << course->courseNumber << endl;
    cout << "Course Title: " << course->title << endl;
    cout << "Prerequisites: ";
    if (course->prerequisites.empty()) {
        cout << "No prerequisites." << endl;
    }
    else {
        for (int i = 0; i < course->prerequisites.size(); i++) {

            // if the prerequisites is the last item, start a new line, otherwise add a comma
            cout << course->prerequisites[i] << (i == course->prerequisites.size() - 1 ? "\n" : ", ");
        }
    }
    cout << "--------------------------------------------" << endl;
}

// public method to search for a course
Course* BinarySearchTree::Search(string courseNumber) {
    return search(this->root, courseNumber);
}

// private recursive mtheod to search for a course by course number
Course* BinarySearchTree::search(Node* node, string courseNumber) {

    // if course number is found return the course details, if node is null then return null
    if (node == nullptr || node->course.courseNumber == courseNumber) {
        return (node == nullptr) ? nullptr : &(node->course);
    }
    // if the number we are looking for is smaller, then search the left subtree
    if (courseNumber < node->course.courseNumber) {
        return search(node->left, courseNumber);
    }
    // otherwise search on the right subtree
    else {
        return search(node->right, courseNumber);
    }
}

void displayMenu() {
    cout << "\nWelcome to the course planner!" << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: " << endl;
}

bool loadCourseFromFile(string& fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << fileName << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        string part;
        vector<string> parts;

        // split the line by a comma
        while (getline(ss, part, ',')) {
            parts.push_back(part);
        }

        // we need at least 2 parts (course number, title)
        if (parts.size() >= 2) {
            Course course;
            course.courseNumber = parts[0];
            course.title = parts[1];

            // any subsequent parts are prerequisites
            for (int i = 2; i < parts.size(); i++) {
                course.prerequisites.push_back(parts[i]);
            }
            bst.Insert(course);
        }
    }
    file.close();
    cout << "Data Strucutre loaded successfully.";
    return true;
}

int main()
{
    BinarySearchTree courseTree;
    int choice = 0;
    bool dataLoaded = false;

    while (choice != 9) {

        displayMenu();
        cin >> choice;

        // validation for input
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            string filename = "ABCU_Advertising_Program_Input.csv";
            courseTree = BinarySearchTree();

            if (loadCourseFromFile(filename, courseTree)) {
                dataLoaded = true;
            }
            else {
                dataLoaded = false;
                cout << "Failed to load data structure." << endl;
            }

            break;
        }
        case 2:
            if (dataLoaded) {
                courseTree.PrintAll();
            }
            else {
                cout << "Please load the data file first - Option 1." << endl;
            }
            break;
        case 3:
            if (dataLoaded) {
                string courseToFind;
                cout << "Enter course number (eg. CSCI101): " << endl;
                cin >> courseToFind;
                Course* foundCourse = courseTree.Search(courseToFind);
                displayCourse(foundCourse);
            }
            else {
                cout << "Please load the data file first - Option 1." << endl;
            }
            break;
        case 9:
            cout << "Exit Program." << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }

    }
        return 0;
   
}


