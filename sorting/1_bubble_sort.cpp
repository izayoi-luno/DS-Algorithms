#include <iostream>
#include <vector>
using namespace std;

class bubbleSort{
    public:
    vector<int> sortArray(vector<int> nums){
        if(nums.size() == 0) return nums;
        // Compare N times
        for(int i = 0; i < nums.size(); i++){
            // Compare from the beginning to the length-1-i
            // This is since the last i+1 elements has already been sorted
            for(int j = 0; j < nums.size() - 1 - i; j++){
                if(nums[j+1] < nums[j]){
                    int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    bubbleSort* A = new bubbleSort();
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