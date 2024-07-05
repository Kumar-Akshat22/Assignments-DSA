/*
QUESTION:

Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. 

*/

// CODE
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute-Force Approach: Use two loops
int findFirstRepeatingElement(vector<int>& v){

    int n = v.size();

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(v[i] == v[j]){

                return (i+1);
            }
        }
    }

    return -1;

    // T.C -> O(n*n)
    // S.C -> O(1)

}

// Approach: Using HashMap
int findFirstRepeating(vector<int>& v){

    int n = v.size();

    unordered_map<int , int> myTable;

    // Store the elements with their frequency of occurrence in the Hash Map
    for(int i = 0; i<n; i++){

        int num = v[i];
        myTable[num]++;
    }

    // Iterate the array and check which element has the frequency > 1
    for(int i = 0; i<n; i++){

        int num = v[i];

        if(myTable[num] > 1){

            return (i+1);
        }
    }

    return -1;

    // T.C -> O(n)
    // S.C -> O(1)
}

int main(){

    vector<int> v = {1, 5, 3, 4, 3, 5, 6};

    int ans = findFirstRepeatingElement(v);
    cout << ans << endl;
    return 0;
}