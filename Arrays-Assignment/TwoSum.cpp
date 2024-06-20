#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Also known by the name Key-Pair problem 

// Two Pointer Approach
vector<int> twoSum(vector<int> &arr, int target){

    // Array must be sorted to apply two pointer approach
    sort(arr.begin() , arr.end());

    int n = arr.size();
    int s = 0;
    int e = n-1;

    while (s<e)
    {
        cout << "INSIDE while loop" << endl;

        

        if(arr[s] + arr[e] == target){

            return {arr[s] , arr[e]};
        }

        else if (arr[s] + arr[e] < target)
        {
            s++;
        }

        else{

            e--;
        }
    }

    cout << "While loop executed" << endl;
    return {-1 , -1};
    
}


int main(){

    vector<int> arr = {10,4,1,2,3,7,20};
    int target = 24;

    vector<int> ans = twoSum(arr , target);
    cout << ans[0] << " , " << ans[1] << endl;

}