#include<iostream>
#include<cmath>
using namespace std;

class Searching{
    private:
        int *arr;
        int size;

        Searching(int size){
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


        //Linear Search Algorithm =>
        //Best Case Time Complexity: O(1)
        //Worst Case Time Complexity: O(n)
        //Average Case Time Complexity: O(n)

        //Linear Search Algorithm
        // 1. Start from the leftmost element of the array
        // 2. Compare the target element with each element of the array
        // 3. If the target element matches with any of the element, return the index
        // 4. If the target element does not match with any of the element, return -1

        //Example:
        // Array: 5 2 9 1 5 6
        // Target: 9
        // 5 != 9
        // 2 != 9
        // 9 == 9 => Return 2

        int linearSearch(int target){
            for(int i=0; i<size; i++){
                if(arr[i] == target){
                    return i;
                }
            }
            return -1;
        }

        //Binary Search Algorithm =>
        //Best Case Time Complexity: O(1)
        //Worst Case Time Complexity: O(log n)
        //Average Case Time Complexity: O(log n)

        //Binary Search Algorithm
        // 1. Compare the target element with the middle element of the array
        // 2. If the target element matches with the middle element, return the index
        // 3. If the target element is greater than the middle element, then the target element must be in the right half of the array
        // 4. If the target element is smaller than the middle element, then the target element must be in the left half of the array
        // 5. Repeat the above steps until the target element is found

        //Example:
        // Array: 1 2 3 4 5 6 7 8 9
        // Target: 7
        // Middle Element: 5
        // 7 > 5 => Target Element is in the right half
        // Middle Element: 8
        // 7 < 8 => Target Element is in the left half
        // Middle Element: 7
        // 7 == 7 => Return 6

        int binarySearch(int target){
            int low = 0;
            int high = size - 1;

            while(low<=high){
                int mid = (low + high)/2;

                if(arr[mid] == target){
                    return mid;
                }
                else if(arr[mid] < target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return -1;
        }

        //Jump Search Algorithm =>
        //Best Case Time Complexity: O(1)
        //Worst Case Time Complexity: O(√n)
        //Average Case Time Complexity: O(√n)

        //Jump Search Algorithm
        // 1. Jump to the block where the target element is present
        // 2. Linearly search the target element in the block
        // 3. If the target element is found, return the index
        // 4. If the target element is not found, return -1

        //Example:
        // Array: 1 2 3 4 5 6 7 8 9
        // Target: 7
        // Block Size: √9 = 3
        // Jump to Block 3
        // Linearly search the target element in Block 3
        // 7 == 7 => Return 6

        int jumpSearch(int target){
            int jump = sqrt(size);
            int prev = 0;

            while(arr[min(jump, size)-1] < target){
                prev = jump;
                jump += sqrt(size);
                if(prev >= size){
                    return -1;
                }
            }

            for(int i=prev; i<min(jump, size); i++){
                if(arr[i] == target){
                    return i;
                }
            }
            return -1;
        }

};