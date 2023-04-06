#include <iostream>
#include <ctime>

using namespace std;
struct Node { //creating linked list
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

void Pop() { // deleting
    if (top == NULL) {
        cout << "Stack underflow" << endl;
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool isEmpty() { //check the stack is empty or not
    return top == NULL;
}

void StackTop() { //displaying the element on top of the stack
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << top->data << endl;
    }
}

void Display() { // displaying the stack
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
    struct S;
    clock_t start, end;

    // Measure time to push elements onto stack
    start = clock();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    for(int z=0;z<5;z++){
        Pop();
    }
    
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    end =clock();
    
    cout<< "Time :"<< double(end-start)/CLOCKS_PER_SEC;// time in seconds

    end = clock();
    
    return 0;
}