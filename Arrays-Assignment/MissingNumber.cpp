#include <iostream>
#include <algorithm>

using namespace std;

// Approach 1: Using Maths
int findMissingNumber(int arr[] , int n){

    int sum1 = 0;

    // Calculate the sum of the elements of the array
    for (int i = 0; i < n; i++)
    {
        sum1+=arr[i];
    }

    // Calculate the sum of the range [0 , n]
    int sum2 = (n*(n+1))/2;

    return sum2 - sum1;

    // T.C -> O(n)
    // S.C -> O(1)

}

// Approach 2: Using XOR operator
int findMissingNumberUsingXOR(int arr[] , int n){

    int ans = 0;

    // XOR all the elements of array
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];

    }

    // XOR with [0 , n]
    for (int i = 0; i <= n; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

// Approach 3: Using Binary Search 
int findMissingNumberUsingBinarySearch(int arr[] , int n){

    sort(arr , arr+n);
    int s = 0;
    int e = n-1;

    int mid = s+(e-s)/2;
    int ans = -1;

    while (s<=e)
    {
        int num = arr[mid];
        int index = mid;
        int difference = num - index;

        if (difference == 0)
        {
            s = mid + 1;
        }

        else if (difference == 1)
        {
            ans = index;
            e = mid - 1;
        }
        
        mid = s+(e-s)/2;
    }

    return ans;
    
}

int main(){


    int arr[6] = {3, 0 , 2 , 4 , 6 , 1};
    int n = 6;

    int ans = findMissingNumberUsingBinarySearch(arr , n);

    cout << "Missing Number : "<< ans << endl;

    return 0;
}