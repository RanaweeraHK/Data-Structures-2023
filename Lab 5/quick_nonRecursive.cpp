# include <iostream>
# include <ctime>
using namespace std;


void swap(int *a,int *b){ // swapping two elements
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int arr[], int start, int end){ // quick sort is a divide and conquer algorithm
    int x = arr[end];                      // function to divide array into parts
    int i = start - 1;
    for (int j = start; j <= end- 1; j++){
    if (arr[j] <= x){
        i++;
        swap (&arr[i], &arr[j]);
    }
    }
    swap (&arr[i + 1], &arr[end]);
    return (i + 1);
    }


void quickiterative(int arr[], int start, int end) {
    int stack[end - start + 1];  // create a stack of size 
    int top = -1;  // initialize top of stack

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) {
        end = stack[top--]; // keep popping
        start = stack[top--];

        int pivot = partition(arr, start, end); //pointing a pivot

        if (pivot - 1 > start) { //push left elements in the quick sort to left side of the stack
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }

        if (pivot + 1 < end) { //push right elements in the quick sort to right side of the stack
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }
    }
}



int main(){
    int size;       // get the size of array as user input
    cin>>size;
    clock_t start,end;

    int arr[size];
    for(int index=0;index<size;index++){ // creating a random array
        arr[index]=rand()%10000;
    }
    start=clock();  // start the clock
    quickiterative(arr, 0, size-1);

    end =clock();  // end the clock

    double time =(double)(end-start)/CLOCKS_PER_SEC;
    cout<< time;
}


