	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {
		 head = nullptr; 
    tail = nullptr; 
    numStudents = 0;
	}

	// return the number of students currently in the list
	int StudentList::listSize() {
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		Node* newNode = new Node(s); 

    if (head == nullptr) { 
        head = newNode; 
        tail = newNode; 
    } else {
        newNode->next = head; 
        head->prev = newNode; 
        head = newNode; 
    }
    numStudents++;
	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {Node* newNode = new Node(s); // Create a new node

    if (tail == nullptr) { 
        head = newNode; 
        tail = newNode; 
    } else {
        tail->next = newNode;
        newNode->prev = tail; 
        tail = newNode; 
    }
    numStudents++; 
	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		Node* current = head; 
    while (current != nullptr) { 
        cout << current->data.name << " "; 
        current = current->next; 
    }
    cout << endl;
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		if (tail == nullptr) { 
        cout << "Error: List is empty, cannot pop back." << endl;
        return; 
    }

    Node* temp = tail; 
    if (head == tail) { 
        head = nullptr; 
        tail = nullptr; 
    } else {
        tail = tail->prev; 
        tail->next = nullptr; 
    }

    delete temp; 
    numStudents--;
	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		if (head == nullptr) { 
        cout << "Error: List is empty, cannot pop front." << endl;
        return; 
    }

    Node* temp = head; 
    if (head == tail) { 
        head = nullptr; 
        tail = nullptr; 
    } else {
        head = head->next; 
        head->prev = nullptr; 
    }

    delete temp; 
    numStudents--;
	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		if (index < 0 || index > numStudents) { 
        cout << "Index out of bounds. Adding to back of the list." << endl;
        addBack(s); 
        return;
    }

    if (index == 0) { 
        addFront(s);
        return;
    }

    Node* newNode = new Node(s); 
    Node* current = head; 

    for (int i = 0; i < index - 1; i++) {
        current = current->next; 
    }

    newNode->next = current->next; 
    newNode->prev = current; 

    if (current->next != nullptr) {
        current->next->prev = newNode; 
    } else {
        tail = newNode; 
    }

    current->next = newNode; 
    numStudents++;
	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Student fixthis;
		return fixthis;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList fixthis;
		return fixthis;
	}

