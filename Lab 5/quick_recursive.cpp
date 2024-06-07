# include <iostream>
# include <ctime>
using namespace std;

void swap(int *a,int *b){ //swapping two elements
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int arr[], int start, int end){ // quick sort is a divide and conquer algorithm
    int x = arr[end];                  // function to divide array into parts
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


void quick_sort(int arr[], int start, int end){
    if (start < end){        // recursive quick sort
        int q = partition(arr, start,end);
        quick_sort(arr, start, q - 1);
        quick_sort(arr, q + 1, end);
    }
}
int main(){
    int size;  // get the size of array as an input
    cin>>size;
    clock_t start,end;

    int arr[size];
    for(int index=0;index<size;index++){  // create random array
        arr[index]=rand()%10000;
    }
    start=clock();  // start the clock

    quick_sort(arr ,0 ,size);

    /*for(int i=0;i<size ;i++){
        cout<< arr[i]<<" ";
    }*/

    end =clock();  // end the clock
    double time =(double)(end-start)/CLOCKS_PER_SEC;
    cout<< time;



}