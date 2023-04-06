#include <iostream>
#include <ctime>

using namespace std;

int top = -1; // imaginary top of the stack

void push(int arr[], int size, int element) {//inserting
    top = top + 1;
    if (top >= size) {
        cout << "Stack overflow" << endl;
    }
    else {
        arr[top] = element;
    }
}

void pop(int arr[]) { //deleting
    if (top == -1) {
        cout << "Stack underflow" << endl;
    }
    else {
        arr[top] = -1; // overwrite top element with sentinel value
        top = top - 1;
    }
}

bool isEmpty(){
    return top==-1;
}

bool isFull(int size){
    return top==size;
}

void StackTop(int arr[]){ //displaying the element on the top of stack
    if(isEmpty()){
        cout<<"Stack is empty";
    }
    else{
        cout<< arr[top];
    }
}

void display(int arr[]) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = new int[size]; // dynamically allocate array of size 'size'
    clock_t start, end;

    // Measure time to push elements onto stack
    start = clock();
    for (int i = 0; i < size; i++) {
        int element = rand() % 1000;
        push(arr, size, element);
    }


    // Measure time to pop elements from stack
    for (int i = 0; i < size; i++) {
        pop(arr);
    }
    end = clock();
    cout << "Time: "<<double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr; // free dynamically allocated memory

    return 0;
}
