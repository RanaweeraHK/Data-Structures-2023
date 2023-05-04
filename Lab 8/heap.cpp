#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest =root; //defining largest as root
   int left = 2*root+1 ;
   int right =2*root+2;

   if(left<n && arr[left]>arr[largest]) //if left child is larger than root
      largest=left;

   if(right<n && arr[right]>arr[largest]) //if right child is larger than root
      largest =right;

   if(largest != root){ //if largest!=root
      swap(arr[root],arr[largest]);
      heapify(arr,n,largest); //recursion
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i =n/2-1;i>=0;i--){
      heapify(arr,n,i);
   }
  
   // extracting elements from heap one by one
   for(int j =n-1;j>0;j--){
      swap(arr[0],arr[j]);
      heapify(arr,j,0); //call max heapify
   }

   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int size; 
   cout<<"Enter the size of array :"<<" "; // asking the size of array from the user
   cin>> size;
   int heap_arr[size];
   cout<<"Input array"<<endl;
   for(int i=0;i<size ;i++){ //getting the elements of the array
    cin>> heap_arr[i];
   }
   //displayArray(heap_arr,size);
  
   heapSort(heap_arr, size);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, size);
}

