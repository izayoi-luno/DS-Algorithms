#include<iostream>
#include<vector>
using namespace std;

// For already sorted arrays it would be effective.
// Mahjong-like

class insertSort{
public:
    vector<int> sortArray(vector<int> nums){
        if(nums.size() == 0) return nums;
        int current; // To store the value of the newly to be sorted element
        for(int i = 0; i < nums.size() - 1; i++){
            int preindex = i; // The index of the already sorted sub-nums
            current = nums[preindex + 1];
            while(preindex >= 0 && current < nums[preindex]){ // To find a position to insert
                nums[preindex + 1] = nums[preindex];
                preindex--;
            }
            nums[preindex + 1] = current;
        }
        return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    insertSort* A = new insertSort();
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