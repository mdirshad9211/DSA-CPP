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


        // Insertion Sort Algorithm =>
        // Best Case Time Complexity: O(n)
        // Worst Case Time Complexity: O(n^2)
        // Average Case Time Complexity: O(n^2)

        // Insertion Sort Algorithm
        // 1. Iterate from arr[1] to arr[n-1]
        // 2. Compare the current element (key) to its predecessor
        // 3. If the key element is smaller than its predecessor, compare it to the elements before.
        //    Move the greater elements one position up to make space for the swapped element.

        // Example:
        // Initial Array: 5 2 9 1 5 6
        // Pass 1: 2 5 9 1 5 6 (2 is inserted before 5)
        // Pass 2: 2 5 9 1 5 6 (9 is already in the correct position)
        // Pass 3: 1 2 5 9 5 6 (1 is inserted before 2)
        // Pass 4: 1 2 5 5 9 6 (5 is inserted before 9)
        // Pass 5: 1 2 5 5 6 9 (6 is inserted before 9)

        void insertionSort(){
            for(int i = 1; i<size; i++){
                int temp = arr[i];
                int j = i-1;

                while(j>=0 && temp <= arr[j]){
                    arr[j+1] = arr[j];
                    j = j-1;
                }
                arr[j+1] = temp;

            }

        } 


        //Merge Sort
        // Based on Divide and Conquer algorithms
        //Best, Worst and Average Case Time Complexity: O(N logN)
        //Not an In-place Sorting Algorithm
        //Stable Sorting Algorithm

        //Merge Sort Algorithm
        // 1. Divide the array into two halves
        // 2. Recursively sort the two halves
        // 3. Merge the sorted halves

        // Example:
        // Initial Array: 38 27 43 3 9 82 10
        // Step 1: 38 27 43 3 | 9 82 10
        // Step 2: 38 27 | 43 3 | 9 82 | 10
        // Step 3: 27 38 | 3 43 | 9 82 | 10
        // Step 4: 3 27 38 43 | 9 10 82
        // Step 5: 3 9 10 27 38 43 82

        void merge(int l, int m, int r){
            int n1 = m - l + 1;
            int n2 = r - m;

            int L[n1], R[n2];

            for(int i = 0; i<n1; i++){
                L[i] = arr[l+i];
            }

            for(int j = 0; j<n2; j++){
                R[j] = arr[m+1+j];
            }

            int i = 0;
            int j = 0;
            int k = l;

            while(i<n1 && j<n2){
                if(L[i] <= R[j]){
                    arr[k] = L[i];
                    i++;
                }else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while(i<n1){
                arr[k] = L[i];
                i++;
                k++;
            }

            while(j<n2){
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        void mergeSort(int l, int r){
            if(l<r){
                int m = l + (r-l)/2;
                mergeSort(l, m);
                mergeSort(m+1, r);
                merge(l, m, r);
            }
        }

        //Quick Sort
        //Based on Divide and Conquer Algorithm
        //Best Case Time Complexity: O(n log n)
        //Worst Case Time Complexity: O(n^2)
        //Average Case Time Complexity: O(n log n)
        //Not a Stable Sorting Algorithm
        //In-place Sorting Algorithm

        //Quick Sort Algorithm
        // 1. Choose a pivot element
        // 2. Partition the array around the pivot
        // 3. Recursively apply the partitioning to the sub-arrays

        // Example:
        // Initial Array: 38 27 43 3 9 82 10
        // Step 1: 38 27 43 3 9 82 10
        // Step 2: 10 27 43 3 9 82 38
        // Step 3: 10 27 9 3 43 82 38
        // Step 4: 10 9 3 27 43 82 38
        // Step 5: 3 9 10 27 43 82 38
        // Step 6: 3 9 10 27 38 82 43


        int partition(int low, int high){
            int pivot = arr[high];
            int i = low - 1;

            for(int j = low; j<=high-1; j++){
                if(arr[j] < pivot){
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i+1], arr[high]);
            return i+1;
        }

        void quickSort(int low, int high){
            if(low<high){
                int pi = partition(low, high);
                quickSort(low, pi-1);
                quickSort(pi+1, high);
            }
        }


        
        



         

        




        

};

int main(){
    Sorting s(5);
    s.input();
    s.traversal();
    s.insertionSort();
    s.traversal();
    return 0;
}