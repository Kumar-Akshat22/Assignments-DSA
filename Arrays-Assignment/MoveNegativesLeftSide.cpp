// Problem:
// Given an array of integers that contains positive and negative numbers.
// Your task is to move all the negative numbers to the left side of the array.
// Assumption: The order of the elements is not required.

// Code
#include <iostream>
#include <vector>

using namespace std;

void moveNegativesLeft(vector<int>& nums){

    int n = nums.size();

    // 's' will maintain all the negative numbers
    int s = 0;

    // 'e' will maintain all the positive numbers
    int e = n-1;

    while (s <= e)
    {
        if (nums[s] > 0 && nums[e] < 0)
        {
            swap(nums[s] , nums[e]);
            s++;
            e--;
        }

        else
        {
            if (nums[s] < 0)
                s++;

            if(nums[e] > 0)
                e--;
        }
    }

    // T.C -> O(n)
    // S.C -> O(1)
}

int main()
{

    vector<int> nums = {-1,-2,-3,-4,-5};

    // Print the vector before changing
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    moveNegativesLeft(nums);

    cout << endl;

    // Print the vector
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
    // OVerall:
    // T.C -> O(n)
    // S.C -> O(1)

    return 0;
}