#include<iostream>
using namespace std;


// Array  Operations
// 1. Insertion Done
// 2. Deletion Done
// 3. Traversal Done
// 4. Searching Done
// 5. Update
// 6. Sorting

class Array{
    private:
        int *arr;
        int size;


    public:
    Array(int size){
        this->size = size;
        arr = new int[size];
    }

    // Insertion means Input in Array
    // Best Case Time Complexity: O(1)
    // Worst Case Time Complexity: O(n)
    // Average Case Time Complexity: O(n) 
    void input(){
        for(int i=0; i<size; i++){
            cout<<"Enter element "<<i+1<<": ";
            cin>>arr[i];
        }
    }
    //  Traversal means Printing the Array
    // Time Complexity: O(n)
    void traversal(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Deletion means removing the element from the array
    // Best Case Time Complexity: O(1)
    // Worst Case Time Complexity: O(n)
    // Average Case Time Complexity: O(n)
    void deletion(){
        int index;
        cout<<"Enter the index to delete: ";
        cin>>index;
        if(index<0 || index>=size){
            cout<<"Invalid Index"<<endl;
        }else{
            for(int i=index; i<size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
        }
    }

    // Searching means finding the element in the array
    // Best Case Time Complexity: O(1)
    // Worst Case Time Complexity: O(n)
    // Average Case Time Complexity: O(n)
    // This search is also called Linear Search
    void search(){
        int element;
        cout<<"Enter the element to search: ";
        cin>>element;
        for(int i=0; i<size; i++){
            if(arr[i] == element){
                cout<<"Element found at index "<<i<<endl;
                return;
            }
        }
        cout<<"Element not found"<<endl;
    }

    // Update means changing the value of the element at a particular index
    // Best Case Time Complexity: O(1)
    // Worst Case Time Complexity: O(1)
    // Average Case Time Complexity: O(1)
    void update(){
        int index, element;
        cout<<"Enter the index to update: ";
        cin>>index;
        cout<<"Enter the new element: ";
        cin>>element;
        if(index<0 || index>=size){
            cout<<"Invalid Index"<<endl;
        }else{
            arr[index] = element;
        }
    }

};



int main(){
    Array arr(5);
    arr.input();
    arr.traversal();
    return 0;
}