/*

Given an array arr[] of size N having integers in the range [1, N] with some of the elements missing. 
The task is to find the missing elements.

Note: There can be duplicates in the array.

*/ 

// Code
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Approach: Visiting Method
vector<int> findMissingElementsUsingVisitedMethod(vector<int> arr){

    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);

        if(arr[index - 1] > 0){

            arr[index - 1] *= -1;

        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Now, check for the positive values. They are the ones missing!
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0){
            
            ans.push_back(i+1);

        }
    }
    
    return ans;

    // T.C -> O(n)
    // S.C -> O(n)
    
}

// Approach: Sorting and Swapping
vector<int> findMissingElements(vector<int> arr){

    // Sort the vector
    int n = arr.size();

    vector<int> ans;

    int i = 0;
    while(i < n)
    {
        int index = arr[i] - 1;

        if(arr[i] != arr[index]){

            swap(arr[i] , arr[index]);

        }
        else{

            i++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != i+1){

            ans.push_back(i+1);

        }
    }
    
    return ans;

    // T.C -> O(n)
    // S.C -> O(n)

}

int main(){

    vector<int> v = {7, 4, 4, 3, 2, 7, 1};

    vector<int> ans = findMissingElements(v);

    cout << "The missing elements are: ";
    
    // Print the answer vector
    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }
    

    return 0;
}