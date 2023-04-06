#include <iostream>
#include <ctime>

using namespace std;

int top = -1;

void Push(int arr[], int size, int element) {
    top = top + 1;
    if (top >= size) {
        cout << "Stack overflow" << endl;
    }
    else {
        arr[top] = element;
    }
}

void Pop(int arr[]) {
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

void StackTop(int arr[]){
    if(isEmpty()){
        cout<<"Stack is empty";
    }
    else{
        cout<< arr[top];
    }
}

void Display(int arr[]) {
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
    int *arr = new int[size]; 
    clock_t start, end;

    
    start = clock();
    Push(arr,size,8);
    Push(arr,size,10);
    Push(arr,size,5);
    Push(arr,size,11);
    Push(arr,size,15);
    Push(arr,size,23);
    Push(arr,size,6);
    Push(arr,size,18);
    Push(arr,size,20);
    Push(arr,size,17);
    Display(arr);
    for(int z=0;z<5;z++){
        Pop(arr);
    }
    
    Display(arr);
    Push(arr,size,4);
    Push(arr,size,30);
    Push(arr,size,3);
    Push(arr,size,1);
    Display(arr);
    end =clock();
    
    cout<< "Time :" << double(end-start)/CLOCKS_PER_SEC;

    return 0;
}