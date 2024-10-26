#include<iostream>
#include<vector>
using namespace std;
int MAX = 101;

class countingSort{
public:
    vector<int> sortArray(vector<int> nums){
        vector<int> count(MAX, 0);
        for(auto &x : nums) count[x]++; // !Record the times of appearance of each element

        // Put back array
        int k = 0;
        for(int num = 0; num < MAX; num++){
            while(count[num]){ // When count[num] is not 0
                nums[k++] = num;
                count[num]--;
            }
        }
    return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    countingSort* A = new countingSort();
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