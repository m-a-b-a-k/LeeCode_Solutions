#include<iostream>
#include<vector>
#include <cstdint>
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> prev_map;
        for(uint16_t ii = 0; ii < nums.size(); ++ii) {
            auto it = prev_map.find(target - nums[ii]);
            if(it != prev_map.end()){
                return {it->second, ii};
            } else {
                prev_map[nums[ii]] = ii;
            }
        }
        return {};
    }
};
int main(){
    std::vector<int> vec = {2,7,11,15};
    Solution sl ;
    std::vector<int> result = sl.twoSum(vec, 9);
    for(const auto &x : result){
        std::cout<<x<<",";
    }
    
    return 0;
}