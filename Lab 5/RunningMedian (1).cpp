#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double median(vector<int>& arr) {
    int size = arr.size();
    if (size % 2 == 0) { // IF THE LENGTH OF THE ARRAY IS ODD
        int mid = size / 2;
        return ((double)(arr[mid] + arr[mid - 1]) / 2.0);
    } else {  //IF THE LENGTH OF THE ARRAY IS EVEN
        return (double)arr[size / 2];
    }
}

int main() {
    int size;
    cin >> size; //GET THE LENGTH OF ARRAY AS INPUT

    vector<int> arr;
    for(int index=0;index<size;index++){  // create random array
        int val=rand()%100;
    
        arr.push_back(val); //ADD THOSE VALUES INTO THE ARRAY

        sort(arr.begin(), arr.end());  //SORTING
        double median_val = median(arr);  //CALLING MEDIAN FUNCTION
        
        cout.precision(1); //OUTPUT FORMATTING
        cout<< "[";
        for(int z=0;z<arr.size();z++){
            cout << arr[z];
            if(z!= arr.size()-1){
                cout<<",";
            }; }
        
        cout<<"]"<<setw(size*5-arr.size()*3 );


        cout << fixed<<median_val << endl;
        cout<<endl;
    }

    return 0;
}