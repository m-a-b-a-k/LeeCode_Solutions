#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<int>ans;
      int left = 0;
      int right = m-1;
      int top = 0;
      int bottom = n-1;
      while((top <= bottom)&&(left <= right) ){
          for(int i = left; i <= right; i++){
              ans.emplace_back(matrix[top][i]);
          }
          top++;
          for(int i = top; i <= bottom; i++){
              ans.emplace_back(matrix[i][right]);
          }
          right--;
          if(top<=bottom){
              for(int i = right; i >= left; i--){
                  ans.emplace_back(matrix[bottom][i]);
              }
              bottom--;
          }
          if(left<=right){
              for(int i = bottom; i >= top; i--){
                  ans.emplace_back(matrix[i][left]);
              }
              left++;
          }
      }
      return ans;
    }
};

int main(){
  Solution s;
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> ans = s.spiralOrder(matrix);
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}