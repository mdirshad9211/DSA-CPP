#include<iostream>
using namespace std;

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
};



int main(){
    Array arr(5);
    arr.input();
    arr.traversal();
    return 0;
}