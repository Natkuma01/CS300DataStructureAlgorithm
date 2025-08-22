## **Project 1** 📂

This report analyzes a C++ program that reads course information (course names, numbers, and prerequisites) from a CSV file, 
stores the data, and provides the following functionality:
- Print all courses in sorted order.
- Search and display details of a specific course.
- The program parses the input file line by line, assigns fields, and stores prerequisites in a chosen data structure.

**Runtime Analysis**
Different data structures were evaluated:

✴️ Vector – Simple to implement, but searching requires O(n).

✴️ Hash Table – Provides average O(1) search but requires sorting for ordered output.

✴️ Binary Search Tree (BST) – Maintains sorted data naturally and allows average O(log n) search.

## **Project 2** 📂

Project Two builds on the design from Project One by implementing the full C++ course advising application. 
The program uses the Binary Search Tree (BST) data structure to store course information, allows users to load 
course data from a file, and provides a menu-driven interface to:

✅ Print all courses in alphanumeric order.

✅ Search and display details of a specific course and its prerequisites.

✅ Exit the program.

## Reflection on the Project 🪞 
1️⃣ **What was the problem you were solving in the projects for this course?**

The main problem I was solving was how to efficiently store and organize course information, such as course names, numbers, and prerequisites, so that users could easily look up details and view all courses in order. Also, need to ensure the search and retrieval process was fast and reliable.

2️⃣ **How did you approach the problem?**

I started by reviewing the data structures we learned, such as hash tables, vectors, linked lists, and binary search trees (BST). Each one has its strengths, but for this project, I decided to use a BST because it provides faster searching and keeps the data in sorted order naturally. This made it easier to implement both the “print all courses” feature and the “search for a specific course” feature. Choosing the right data structure was an important factor to making the program efficient and straightforward.

3️⃣ **How has your work on this project expanded your approach to designing software and developing programs?**

This project helped me see the importance of analyzing the problem before jumping into coding. By considering how the data would be used and what operations were most important, I was able to design a solution that fit the problem instead of just writing code that worked “for now”. Designing software is not just about solving the immediate problem, but also need to consider to improve the performance and scalability.

4️⃣ **How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**

Through this project, I learnt the value of writing clean and organized code. Since I had to parse files, build data structures, and create search functions, I broke down the program into smaller, modular functions that each handled one responsibility. This made the code easier to debug and understand. I also paid attention to comments and variable naming to keep the code readable. Overall, it made me more mindful of writing code that not only works but can also be easily maintained or adapted if requirements change in the future.

5️⃣ **How did you overcome any roadblocks you encountered while going through the activities or project?**

I feel a little challenging when arranging the logic for storing and retrieving courses using a Binary Search Tree. At first, it was difficult to make sure the insert and search functions worked correctly and that the data displayed in the right order. To overcome this, I went back to the pseudocode I had written before starting the project and carefully walked through it step by step. I even read it out loud to myself to check if the logic made sense. While coding, I also used print statements to trace the flow of data and confirm that values were being inserted and retrieved as expected. This process helped me identify mistakes early and make me feel more confidence with the BST logic work properly.

