#include <iostream>
#include <vector>

using namespace std;

int twoPointer(vector<int>& nums){

    int n = nums.size();
    int i = 1;
    int j = 0;

    while (i < n)
    {
        if(nums[i] == nums[j]) i++;

        else nums[++j] = nums[i++];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return j+1;
    
}

int main(){

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = twoPointer(nums);

    cout << "\nThe number of unique elements are: " << ans << endl;

    return 0;
}