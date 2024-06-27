#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


// Approach 1: Using sort STL 
int findDuplicateUsingSort(vector<int>& v){

    sort(v.begin() , v.end());

    int ans = -1;
    // Check for the adjacent elements, if they are equal
    for (int i = 0; i < v.size()-1; i++)
    {
        if(v[i] == v[i+1]){

            ans = v[i];
            break;
        }
    }

    return ans;

    // T.C -> O(n*log(n))
}

// Approach 2: Visited marking element method
int findDuplicatesUsingVisitedMethod(vector<int>& v){

    int ans = -1;

    for (int i = 0; i < v.size(); i++)
    {
        int index = abs(v[i]);

        if(v[index] < 0){

            ans = index;
            break;
        }

        v[index] *= -1;
    }

    return ans;

    // T.C -> O(n)
    // S.c -> O(1)

}

// Approach 3: Positioning method
int findDuplicatesUsingPositioningMethod(vector<int>& v){

    while (v[0] != v[v[0]])
    {
        swap(v[0] , v[v[0]]);
    }

    return v[0];
    

}

int main(){

    vector<int> v = {3,1,3,4,2};

    int ans = findDuplicatesUsingPositioningMethod(v);

    cout << "The duplicate number is: " << ans << endl; 


    return 0;
}