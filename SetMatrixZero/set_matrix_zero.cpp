#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix.size();
    bool firstRowZero = false;
    bool firstColoumnZero = false;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                if(i == 0) firstRowZero = true;
                if(j == 0) firstColoumnZero = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(firstRowZero){
        for(int i=0; i<n; i++){
            matrix[0][i] = 0;
        }
    }
    if(firstColoumnZero){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}