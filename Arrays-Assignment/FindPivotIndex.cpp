#include <iostream>
#include <vector>

using namespace std;

// Brute Force Approach
int findPivot(vector<int> &nums)
{

    int n = nums.size();
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int lsum = 0, rsum = 0;
        // Calculate the left sum
        for (int j = 0; j < i; j++)
        {
            lsum = lsum + nums[j];
        }

        // Calculate the right sum
        for (int k = i + 1; k < n; k++)
        {
            rsum = rsum + nums[k];
        }

        // Check whether the lsum and rsum are equal or not
        if (lsum == rsum)
        {
            ans = i;
            break;
        }
    }

    return ans;

    // T.C -> O(n*n)
    // S.C -> O(1)
}

// Optimized Approach
// Using Prefix Sum
int findPivotUsingPrefixSum(vector<int> &nums)
{

    int n = nums.size();
    int ans = -1;

    vector<int> lsum(n, 0);
    vector<int> rsum(n, 0);

    // Calculate the left sum
    for (int i = 1; i < n; i++)
    {
        lsum[i] = lsum[i - 1] + nums[i - 1];
    }

    // Calculate the right sum
    for (int i = n - 2; i >= 0; i--)
    {

        rsum[i] = rsum[i + 1] + nums[i + 1];
    }

    // Iterate the vector once again to check lsum equals rsum
    for (int i = 0; i < n; i++)
    {
        if (lsum[i] == rsum[i])
        {
            ans = i;
            break;
        }
    }
    return ans;

    // T.C -> O(n)
    // S.C -> O(n)
}

// More Optimized in terms of time and space complexity
int findPivotIndexOptimized(vector<int> &nums)
{

    int n = nums.size();
    int lsum = 0;
    int rsum = 0;
    int sum = 0;
    int ans = -1;

    // Calculate the total sum of the vector
    for (int i = 0; i < n; i++)
    {

        sum += nums[i];
    }

    // Iterate the array and check lsum equals rsum for each element
    for (int i = 0; i < n; i++)
    {

        rsum = sum - lsum - nums[i];
        if (lsum == rsum)
        {

            ans = i;
            break;
        }

        lsum = lsum + nums[i];
    }

    return ans;

    // T.C -> O(n)
    // S.C -> O(1)
}

int main()
{

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int ans = findPivotIndexOptimized(nums);
    cout << "The pivot index is: " << ans << endl;

    return 0;
}
