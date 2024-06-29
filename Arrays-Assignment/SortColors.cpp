#include <iostream>
#include <vector>

using namespace std;

// Approach 1: Using Counting
void sortColorsUsingCounting(vector<int>& v){

    int n = v.size();
    int zeroCount = 0 , oneCount = 0, twoCount = 0;

    // Iterate the vector to count for number of 0's, 1's, 2's
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            zeroCount++;
        
        else if (v[i] == 1)
            oneCount++;
    
    }
    
    twoCount = n - (zeroCount + oneCount);

    // Fill the vector according to the number of 0's, 1's, 2's
    fill_n(v.begin() , zeroCount , 0);
    fill_n(v.begin()+zeroCount , oneCount , 1);
    fill_n(v.begin()+zeroCount+oneCount , twoCount , 2);
}


// Approach 2: Using 3 Pointers
void sortColorsUsing3Pointer(vector<int>& v){

    int n = v.size();
    int l = 0, m = 0, h = n-1;

    while (m<=h)
    {

        // The idea is to compare with the v[m] value.
        if (v[m] == 1)
            m++;
        
        else if (v[m] == 0)
        {
            swap(v[l] , v[m]);
            l++;
            m++;
        }
        
        else{

            // v[m] == 2
            swap(v[m] , v[h]);
            h--;
        }

    }
}


int main(){

    vector<int> v = {2, 0, 1};
    // sortColorsUsingCounting(v);
    sortColorsUsing3Pointer(v);

    // Print the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }


    return 0;
}