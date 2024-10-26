#include<iostream>
#include<vector>
using namespace std;

// Using Devide-and-Conquer and recursion
// Similar to LeetCode #88 Merge 2 sorted arrays

class mergeSort{
public:
    vector<int> sortArray(vector<int> nums){
        int left = 0, right = nums.size() - 1;
        Merge_sort(nums, left, right);
        return nums;
    }
    // The process of merge two sorted arrays
    void Merge(vector<int> &nums, int left, int mid, int right){
        int temp[right - left + 1];
        int i = left;
        int j = mid + 1;
        int k = 0;

        while(i <= mid && j <= right){
            if(nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while(i <= mid) temp[k++] = nums[i++];
        while(j <= right) temp[k++] = nums[j++];

        for(int m = left, n = 0; m <= right; m++, n++){
            nums[m] = temp[n];
        }
    }
    // The process of recursion
    void Merge_sort(vector<int> &nums, int left, int right){
        if(left == right) return;

        int mid = (left + right) / 2;
        Merge_sort(nums, left, mid);
        Merge_sort(nums, mid+1, right);
        Merge(nums, left, mid, right);
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    mergeSort* A = new mergeSort();
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