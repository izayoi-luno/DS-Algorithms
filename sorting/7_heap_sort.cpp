#include<iostream>
#include<vector>
using namespace std;

// Sometimes we do not need a complete sorted array but only part of it being sorted, for instance get the maximum/minimum, etc.

// 1. Treat the array to be sorted as a complete binary tree
// 2. Then convert the tree to be max heap or min heap
// The relationship between an array and its corresponding heap: i = n/2 is the last node of non-leaf nodes

// 3. After getting the binary heap, take the max/min number out of the heap
// Pay attention, since we cannot directly take the root (the max/min) out, we first swap the root and one leaf node (the first ele and the last ele in the corresponding array)
// 4. After taking the element, it could destroy the structure of the heap so it is needed to reconstruct the heap
// 5. Repeating the process (2 - 4)

// Ascending: max heap; Descending: min heap

class heapSort{
public:
    vector<int> sortArray(vector<int> nums){
        HeapSort(nums);
        return nums;
    }

    // To adjust the heap to be a max heap: it is a recursion process
    void heapify(vector<int> &nums, int i, int len){
        // !The index of the left and right node
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIndex = i; // Assume the max value is the node itself
        
        // Compare the node with its left and right nodes and record the index
        if(left < len && nums[left] > nums[maxIndex]) maxIndex = left;
        if(right < len && nums[right] > nums[maxIndex]) maxIndex = right;
        // Only when swapping the array ele need to adjust the heap
        if(maxIndex != i){
            swap(nums[i], nums[maxIndex]);
            heapify(nums, maxIndex, len);
        }
    }

    // To construct heap from array: it is a tranversal process
    void buildMaxHeap(vector<int> &nums, int len){
        // From the last non-leaf node begin
        for(int i = len / 2 - 1; i >= 0; i--) heapify(nums, i, len);
    }

    // Heap sorting
    void HeapSort(vector<int> &nums){
        int len = nums.size();
        buildMaxHeap(nums, len);
        while(len > 1){
            swap(nums[0], nums[len-1]);
            heapify(nums, 0, --len);
        }
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    heapSort* A = new heapSort();
    vector<int> test;
    int testEle;
    while(cin >> testEle){
        test.push_back(testEle);
        if(cin.get() == '\n') break;
    }
    printVector(test);
    cout << endl;
    test = A->sortArray(test);
    printVector(test);
    cout << endl;
    return 0;
}