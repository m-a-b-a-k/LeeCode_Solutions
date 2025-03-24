#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int times = n / 3 + 1;
    vector<int> ans;
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      if (cnt1 == 0 && el2 != nums[i])
      {
        cnt1 = 1;
        el1 = nums[i];
      }
      else if (cnt2 == 0 && el1 != nums[i])
      {
        cnt2 = 1;
        el2 = nums[i];
      }
      else if (el1 == nums[i])
        cnt1++;
      else if (el2 == nums[i])
        cnt2++;
      else
      {
        cnt1--;
        cnt2--;
      }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == el1)
        cnt1++;
      if (nums[i] == el2)
        cnt2++;
    }
    if (cnt1 >= times)
      ans.emplace_back(el1);
    if (cnt2 >= times)
      ans.emplace_back(el2);
    return ans;
  }
};

int main(){
  vector<int> v = {1,2,1};
  Solution sl;
  vector<int> result;
  result = sl.majorityElement(v);
  for(auto &el : result)
    cout<<el<<" ";
  return 0;
}
