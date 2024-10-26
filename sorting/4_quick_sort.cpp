#include<iostream>
#include<vector>
using namespace std;

// A good application of Devide-and-Conquer
// Use 2 pointers to avoid extra memory use ----> Called left-right-pointer method

class quickSort{
public:
    vector<int> sortArray(vector<int> nums){
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
    // Recursion structure to repeat the work of partition and sort
    void sort(vector<int> &nums, int left, int right){
        if(nums.size() < 1 || left < 0 || right >= nums.size() || left >= right) return;
        int i = partition(nums, left, right);
        if(i > left) sort(nums, left, i - 1);
        if(i < right) sort(nums, i + 1, right);
    }
    // partition of the array
    int partition(vector<int> &nums, int left, int right){
        int i = left;
        int j = right;
        int key = nums[left];

        while(i != j){
            while(i < j && nums[j] >= key) j--; // Find the element less than key in the right part of the array
            while(i < j && nums[i] <= key) i++; // Find the element greater than key in the left part of the array
            swap(nums[i], nums[j]); // swap to make sure that all elements in the left part are less than key and those in the right part are all greater than key 
        }

        swap(nums[i], nums[left]); // Put the key to "center" to devide the array
        return i;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    quickSort* A = new quickSort();
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