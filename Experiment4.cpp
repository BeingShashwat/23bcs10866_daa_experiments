// Doubly Linked List (DLL)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at beginning
void insertBegin(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr, head};
    if (head != nullptr) head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at beginning
void deleteBegin(Node*& head) {
    if (head == nullptr) {
        cout << "ERROR: List is currently empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
    cout << "Successfully removed node from beginning.\n";
}

// Delete at end
void deleteEnd(Node*& head) {
    if (head == nullptr) {
        cout << "ERROR: List is currently empty!\n";
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    if (temp->prev != nullptr) temp->prev->next = nullptr;
    else head = nullptr;
    delete temp;
    cout << "Successfully removed node from end.\n";
}

// Display
void display(Node* head) {
    if (head == nullptr) {
        cout << "ERROR: List is currently empty!\n";
        return;
    }
    cout << "Current DLL contents: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int selection, value;
    do {
        cout << "\n=== Doubly Linked List Operations ===\n";
        cout << "1. Add Node at Start\n";
        cout << "2. Add Node at End\n";
        cout << "3. Remove Node from Start\n";
        cout << "4. Remove Node from End\n";
        cout << "5. Show List\n";
        cout << "6. Exit Program\n";
        cout << "Your choice: ";
        cin >> selection;

        switch (selection) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertBegin(head, value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertEnd(head, value);
                break;
            case 3:
                deleteBegin(head);
                break;
            case 4:
                deleteEnd(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout << "Program terminating.\n";
                break;
            default:
                cout << "ERROR: Invalid selection!\n";
        }
    } while (selection != 6);

    return 0;
}


//Circular Linked List (CLL)

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// // Insert at beginning
// void insertBegin(Node*& head, int val) {
//     Node* newNode = new Node{val, nullptr};
//     if (head == nullptr) {
//         head = newNode;
//         newNode->next = head;
//     } else {
//         Node* temp = head;
//         while (temp->next != head) temp = temp->next;
//         newNode->next = head;
//         temp->next = newNode;
//         head = newNode;
//     }
// }

// // Insert at end
// void insertEnd(Node*& head, int val) {
//     Node* newNode = new Node{val, nullptr};
//     if (head == nullptr) {
//         head = newNode;
//         newNode->next = head;
//     } else {
//         Node* temp = head;
//         while (temp->next != head) temp = temp->next;
//         temp->next = newNode;
//         newNode->next = head;
//     }
// }

// // Delete at beginning
// void deleteBegin(Node*& head) {
//     if (head == nullptr) {
//         cout << "List is empty!\n";
//         return;
//     }
//     if (head->next == head) {
//         delete head;
//         head = nullptr;
//         cout << "Deleted last node.\n";
//         return;
//     }
//     Node* temp = head;
//     Node* last = head;
//     while (last->next != head) last = last->next;
//     head = head->next;
//     last->next = head;
//     delete temp;
//     cout << "Deleted from beginning.\n";
// }

// // Delete at end
// void deleteEnd(Node*& head) {
//     if (head == nullptr) {
//         cout << "List is empty!\n";
//         return;
//     }
//     if (head->next == head) {
//         delete head;
//         head = nullptr;
//         cout << "Deleted last node.\n";
//         return;
//     }
//     Node* temp = head;
//     while (temp->next->next != head) temp = temp->next;
//     Node* del = temp->next;
//     temp->next = head;
//     delete del;
//     cout << "Deleted from end.\n";
// }

// // Display
// void display(Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty!\n";
//         return;
//     }
//     cout << "Circular Linked List: ";
//     Node* temp = head;
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     } while (temp != head);
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;
//     int choice, val;
//     do {
//         cout << "\n--- Circular Linked List Menu ---\n";
//         cout << "1. Insert at Beginning\n";
//         cout << "2. Insert at End\n";
//         cout << "3. Delete at Beginning\n";
//         cout << "4. Delete at End\n";
//         cout << "5. Display\n";
//         cout << "6. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value: ";
//                 cin >> val;
//                 insertBegin(head, val);
//                 break;
//             case 2:
//                 cout << "Enter value: ";
//                 cin >> val;
//                 insertEnd(head, val);
//                 break;
//             case 3:
//                 deleteBegin(head);
//                 break;
//             case 4:
//                 deleteEnd(head);
//                 break;
//             case 5:
//                 display(head);
//                 break;
//             case 6:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice!\n";
//         }
//     } while (choice != 6);

//     return 0;
// }
