#include<iostream>
#include<vector>
using namespace std;

// It is an development and optimization based on insert sorting
// It is achieved by grouping the array and sorting in every group
// The original group numbers = length/2, then the groups are expanded to be only having numbers of group/2
// The numbers are called increment series and they are not neccessarily to be /2
/*
    Usually used increment series:
    1. shell increment: {n, n/2, n/2/2, ..., 1}
    2. Hibbard series: {2^k-1, ..., 3, 1}
    3. Sedgewick series: {..., 109, 41, 19, 5, 1} 9 * 4^i - 9 * 2^i + 1 or 4^i - 3 * 2^i + 1
*/

class shellSort{
public:
    vector<int> sortArray(vector<int> nums){
        if(nums.size() == 0) return nums;
        int current; // To store the value of the newly to be sorted element
        int len = nums.size();
        int gap = len / 2;
        while(gap > 0){
            for(int i = gap; i < len; i++){
                int preindex = i - gap; // The index of the already sorted sub-nums
                current = nums[i];
                while(preindex >= 0 && current < nums[preindex]){ // To find a position to insert
                    nums[preindex + gap] = nums[preindex];
                    preindex -= gap;
                }
                nums[preindex + gap] = current;
            }
            gap /= 2;
        }
        return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    shellSort* A = new shellSort();
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