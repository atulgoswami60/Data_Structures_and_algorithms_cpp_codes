#include <bits/stdc++.h>
using namespace std;

// -------------------- Node Structure --------------------
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// -------------------- Linked List Class --------------------
class LinkedList {
private:
    Node* head;

public:

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Destructor
    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // -------------------- Insert at Beginning --------------------
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "Node inserted successfully.\n";
    }

    // -------------------- Insert at End --------------------
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == NULL) {
            head = newNode;
            cout << "Node inserted successfully.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Node inserted successfully.\n";
    }

    // -------------------- Insert at Position --------------------
    // Position starts from 1
    void insertAtPosition(int value, int position) {

        if (position < 1) {
            cout << "Invalid position.\n";
            return;
        }

        // Position 1 means beginning
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        // Move to node before required position
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of range.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted successfully.\n";
    }

    // -------------------- Delete from Beginning --------------------
    void deleteFromBeginning() {

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Node deleted successfully.\n";
    }

    // -------------------- Delete from End --------------------
    void deleteFromEnd() {

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        // Only one node
        if (head->next == NULL) {
            delete head;
            head = NULL;

            cout << "Node deleted successfully.\n";
            return;
        }

        Node* temp = head;

        // Find second-last node
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "Node deleted successfully.\n";
    }

    // -------------------- Delete from Position --------------------
    void deleteFromPosition(int position) {

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (position < 1) {
            cout << "Invalid position.\n";
            return;
        }

        // Delete first node
        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        // Move to node before the one to delete
        for (int i = 1; i < position - 1; i++) {

            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of range.\n";
                return;
            }

            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << "Node deleted successfully.\n";
    }

    // -------------------- Search --------------------
    void search(int value) {

        Node* temp = head;
        int position = 1;

        while (temp != NULL) {

            if (temp->data == value) {
                cout << "Element found at position "
                     << position << ".\n";
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found.\n";
    }

    // -------------------- Display --------------------
    void display() {

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL) {
            cout << temp->data;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << " -> NULL\n";
    }

    // -------------------- Count Nodes --------------------
    int countNodes() {

        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // -------------------- Reverse Linked List --------------------
    void reverse() {

        Node* previous = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {

            nextNode = current->next;

            current->next = previous;

            previous = current;
            current = nextNode;
        }

        head = previous;

        cout << "Linked list reversed successfully.\n";
    }

    // -------------------- Find Middle Node --------------------
    void findMiddle() {

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL &&
               fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element = " << slow->data << endl;
    }
};

// -------------------- Main Function --------------------
int main() {

    LinkedList list;

    int choice;
    int value;
    int position;

    do {

        cout << "\n========== LINKED LIST MENU ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Count Nodes\n";
        cout << "10. Reverse\n";
        cout << "11. Find Middle\n";
        cout << "0. Exit\n";
        cout << "======================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;

            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;

            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.insertAtPosition(value, position);
            break;

        case 4:
            list.deleteFromBeginning();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;

            list.deleteFromPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;

            list.search(value);
            break;

        case 8:
            list.display();
            break;

        case 9:
            cout << "Number of nodes = "
                 << list.countNodes() << endl;
            break;

        case 10:
            list.reverse();
            break;

        case 11:
            list.findMiddle();
            break;

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
