#include <iostream>
#include <vector>

using namespace std;

void wavePrintMatrix(vector<vector<int>>& mat){

    /*
    Intution:

    - Wave moves in horizontal direction, means we will keep column constant at a time and change the row value for every column value.
    - We will observe that every "even" numbered column is printed top - bottom.
    - All the "odd" numbered column is printed botton - top.
    - That's all, you have got the matrix printed in the wave form.

    */

    int rowSize = mat.size();
    int colSize = mat[0].size();

    cout << "Row: " << rowSize << " Column: " << colSize << endl;
    for(int j = 0; j<colSize; j++){

        // Even numbered column
        if(j%2 == 0){

            int i = 0;
            while(i < rowSize){

                cout << mat[i][j] << " ";
                i++;
            }
        }
        else{

            int i = rowSize - 1;
            while(i >= 0){

                cout << mat[i][j] << " ";
                i--;

            }
        }

        cout << endl;
    }
}

int main(){

    vector<vector<int>> v = {
                                {1 , 2 , 3},
                                {4 , 5 , 6},
                                {7, 8, 9},
                                {10, 11, 12},
                            };
    
    wavePrintMatrix(v);



    return 0;
}