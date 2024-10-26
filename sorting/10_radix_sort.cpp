#include<iostream>
#include<vector>
#include<algorithm> // max_element
using namespace std;
const int N = 10;

class radixSort{
public:
    vector<int> sortArray(vector<int> nums){
        int base = 1;
        int maxDigit = getMaxDigit(nums);
        vector<vector<int>> bucket(N);
        for(int i = 0; i < maxDigit; i++){
            // Push the numbers of the original array to the bucket
            for(int j = 0; j < nums.size(); j++){
                int num = nums[j] / base % 10;
                bucket[num].push_back(nums[j]);
            }
            // Push back the numbers to the original array
            int index = 0;
            for(int j = 0; j < bucket.size(); j++){
                for(int k = 0; k < bucket[j].size(); k++) nums[index++] = bucket[j].at(k);
                bucket[j].clear();
            }
            base *= 10;
        }
        return nums;
    }

    int getMaxDigit(vector<int> &nums){
        int maxData = *max_element(nums.begin(), nums.end()); // Find the maximum number among the array
        // Find the maximum digit according to the maximum number
        int maxDigit = 0; // Using an iteral to achieve this
        while(maxData){
            maxData /= 10;
            maxDigit++;
        }
        return maxDigit;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    radixSort* A = new radixSort();
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