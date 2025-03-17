#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    vector<int> ansRow;
    long long ans;
    for(int row = 1; row <= numRows; row++){
        ans = 1;
        ansRow.clear();
        ansRow.emplace_back(ans);
        for(int col = 1; col < row; col++){
            ans = ans*(row-col);
            ans = ans/col;
            ansRow.emplace_back(ans);
        }
        result.emplace_back(ansRow);
    }
    return result;
  }
};

int main(){
  Solution s;
  vector<vector<int>> result = s.generate(6);
  for(auto row : result){
    for(auto col : row){
      cout << col << " ";
    }
    cout << endl;
  }
  return 0;
}