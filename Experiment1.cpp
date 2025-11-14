// Stack

#include <iostream>
using namespace std;

class Stack {
protected:
    int arr[10], top, n, data;

public:
    Stack() {
        top = -1;
        n = 10;
    }

    void push() {
        int element;
        cout << "Input value to add to stack: ";
        cin >> element;
        if (top == n - 1) {
            cout << "ERROR: Stack Overflow - Maximum capacity reached!" << endl;
        } else {
            top++;
            arr[top] = element;
            cout << "Successfully added " << element << " to the stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "ERROR: Stack Underflow - Stack is empty!" << endl;
        } else {
            data = arr[top];
            top--;
            cout << "Removed element: " << data << endl;
        }
    }

    void traverse() {
        if (top == -1) {
            cout << "Stack is currently empty." << endl;
        } else {
            cout << "Stack elements (from top): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void overflow() {
        if (top == n - 1) {
            cout << "Stack Overflow!!" << endl;
            cout << "Pop elements to insert new elements!" << endl;
            pop();
        } else {
            push();
            cout << "Sufficient space to insert elements!" << endl;
        }
    }

    void underflow() {
        if (top == -1) {
            cout << "Stack Underflow!!" << endl;
            cout << "Push elements!" << endl;
            push();
        } else {
            traverse();
            cout << "No Underflow, elements are present!" << endl;
        }
    }
};

int main() {
    Stack S;
    int choice;
    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Overflow" << endl;
        cout << "5. Underflow" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: S.push(); break;
            case 2: S.pop(); break;
            case 3: S.traverse(); break;
            case 4: S.overflow(); break;
            case 5: S.underflow(); break;
            case 6:
                cout << "Exiting Program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }

    } while(choice != 6);

    return 0;
}
