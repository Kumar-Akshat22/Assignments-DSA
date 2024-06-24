#include <iostream>
#include <vector>

using namespace std;


// Approach: Sliding Window
double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        int s = 0;
        int e = k-1;
        double maxSum = 0 , currentSum = 0;

        // Calculate the initial Current Sum
        // T.C -> O(n)
        for(int i = s; i<=e; i++){

            currentSum += nums[i];
        }

        // Initialize the maximum sum
        maxSum = currentSum;

        // T.C -> O(n)
        while(e < n){

            s++;
            if(e+1 == n){
                break;
            }
            e++;
            
            // Start and End are updated
            // Calculate the new Current Sum
            currentSum = currentSum - nums[s-1] + nums[e];

            // Update the maxSum
            maxSum = max(maxSum , currentSum);
        }

        return maxSum/k;

        // Overall 
        // T.C -> O(n)
        // S.C -> O(1)   
}

int main(){

    vector<int> nums = {5};

    int k = 1;

    double ans = findMaxAverage(nums , k);

    cout << "The maximum average of the subarray is: " << ans << endl;

    return 0;

}