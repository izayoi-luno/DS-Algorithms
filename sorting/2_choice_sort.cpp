#include<iostream>
#include<vector>
using namespace std;

class choiceSort{
public:
    vector<int> sortArray(vector<int> nums){
        if(nums.size() == 0) return nums;
        for(int i = 0; i < nums.size(); i++){
            int minIndex = i; // The default minimum number is the first one among the remain-set
            for(int j = i; j < nums.size(); j++){
                if(nums[j] < nums[minIndex]) minIndex = j; // !The way of finding max/min element in a set 
            }
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
        return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    choiceSort* A = new choiceSort();
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