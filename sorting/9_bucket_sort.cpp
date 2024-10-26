#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 10; // Assume data range is 0-100

class bucketSort{
public:
    vector<int> sortArray(vector<int> nums){
        // Put elements of nums into bucket
        int size = nums.size();
        vector<vector<int>> bucket(N); // definition of bucket: a 2-d array
        for(int i = 0; i < size; i++) bucket[nums[i] / 10].push_back(nums[i]); // !the way of putting in bucket

        // Sort each bucket and put back the element
        int k = 0;
        for(int i = 0; i < N; i++){
            sort(bucket[i].begin(), bucket[i].end()); // Use of sort algorithm in std
            int size = bucket[i].size();
            for(int j = 0; j < size; j++) nums[k++] = bucket[i].at(j); // !the way of putting back the element 
            bucket[i].clear();
        }
        return nums;
    }
};

void printVector(vector<int> vect){
    for(int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
}

int main(){
    bucketSort* A = new bucketSort();
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