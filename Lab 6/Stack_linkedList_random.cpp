#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* top = NULL;

void Push(int element) { //inserting
    Node* newNode = new Node();
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

void Pop() { //deleting
    if (top == NULL) {
        cout << "Stack underflow" << endl;
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool isEmpty() {
    return top == NULL;
}

void StackTop() { //displaying the top on the stack
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << top->data << endl;
    }
}

void Display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Elements: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;


    clock_t start, end;
    start = clock();

    for (int i = 0; i < size; i++) {
        int element = rand() % 100; // generate random value between 0 and 99
        Push(element);
    }
    for (int i = 0; i < size; i++) {
        Pop();
    }
    end = clock();

    cout <<  "Time: "<<double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
