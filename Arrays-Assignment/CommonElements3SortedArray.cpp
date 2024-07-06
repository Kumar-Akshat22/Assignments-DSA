#include <iostream>
#include <vector>

using namespace std;

// Approach: 3 Pointer
vector<int> findCommonElements(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{

    int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

    int i = 0; // For First vector
    int j = 0; // For Second Vector
    int k = 0; // For Third Vector

    vector<int> ans;

    while (i < n1 && j < n2 && k < n3)
    {

        if (v1[i] == v2[j] && v2[j] == v3[k])
        {
            if (ans.empty() || ans.back() != v1[i])
            {

                ans.push_back(v1[i]);
            }

            i++;
            j++;
            k++;
        }

        else if (v1[i] < v2[j])
        {

            i++;
        }

        else if (v2[j] < v3[k])
        {

            j++;
        }

        else
        {

            k++;
        }
    }

    if(ans.empty()){
        ans.push_back(-1);
    }

    return ans;

    // T.C -> O(n1 + n2 + n3)
    // S.C -> O(n)
}


int main()
{

    vector<int> arr1 = {1, 5, 5};
    vector<int> arr2 = {3, 4, 5, 5, 10};
    vector<int> arr3 = {5, 5, 10, 20};

    vector<int> ans = findCommonElements(arr1, arr2, arr3);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }
}