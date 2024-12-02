#include<iostream>
using namespace std;

class Sorting{
    private:
        int *arr;
        int size;

        public:
        Sorting(int size){
            this->size = size;
            arr = new int[size];
        }

        void input(){
            for(int i=0; i<size; i++){
                cout<<"Enter element "<<i+1<<": ";
                cin>>arr[i];
            }
        }

        void traversal(){
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        // Bubble Sort Algorithm =>
        //Best Case Time Complexity: O(n)
        //Worst Case Time Complexity: O(n^2)
        //Average Case Time Complexity: O(n^2)

        // Bubble Sort Algorithm
        // 1. Compare the adjacent elements
        // 2. Swap the elements if they are in the wrong order
        // 3. Repeat the above steps for all the elements
        // 4. Repeat the above steps for n-1 iterations
        // It is Stable Sorting

        //Give an in detail example of Bubble Sort Algorithm
        // 5 4 3 2 1 => 4 5 3 2 1 => 4 3 5 2 1 => 4 3 2 5 1 => 4 3 2 1 5

        // 4 3 2 1 5 => 3 4 2 1 5 => 3 2 4 1 5 => 3 2 1 4 5

        // 3 2 1 4 5 => 2 3 1 4 5 => 2 1 3 4 5

        // 2 1 3 4 5 => 1 2 3 4 5

        
    
        void bubbleSort(){
            for(int i=0; i<size; i++){
                for(int j = 0; j<size - i - 1; j++){
                    if(arr[j]>arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }

        //Optimized Bubble Sort
        void optimizedBubbleSort(){
            for(int i=0; i<size; i++){
                bool flag = false;
                for(int j = 0; j<size - i - 1; j++){
                    if(arr[j]>arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        flag = true;
                    }
                }

                if(!flag){
                    break; 
                }
            }
        }

        //Selection sort
        //Select the minimum element and put it at its correct ith position
        //Select Correct Element and put it at its right ith position
        //Best, Worst and Average Case Time Complexity: O(n^2)
        //Not a Stable Sorting
        //Used for small datasets


        void selectionSort(){
            for(int i = 0; i<size-1; i++){
                int mini = i;
                for(int j = i+1; j<size; j++){
                    if(arr[mini] > arr[j]){
                        mini = j;
                    }
                    swap(arr[i], arr[mini]);
                }
            }
        }


        //Insertion Sort
        //

         

        




        

};

int main(){
    Sorting s(5);
    s.input();
    s.traversal();
    s.optimizedBubbleSort();
    s.traversal();
    return 0;
}