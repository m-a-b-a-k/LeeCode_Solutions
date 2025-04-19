#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// Function to count subarrays with given XOR
int countSubarraysWithXOR(const vector<int>& arr, int k) {
    unordered_map<int, int> prefixXORCount;
    int count = 0;
    int currentXOR = 0;

    for (int num : arr) {
        currentXOR ^= num;

        // If currentXOR is equal to k, increment count
        if (currentXOR == k) {
            count++;
        }

        // If (currentXOR ^ k) exists in the map, add its count to result
        if (prefixXORCount.find(currentXOR ^ k) != prefixXORCount.end()) {
            count += prefixXORCount[currentXOR ^ k];
        }

        // Increment the count of currentXOR in the map
        prefixXORCount[currentXOR]++;
    }

    return count;
}
int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Count of subarrays with XOR " << k << " is: " << countSubarraysWithXOR(arr, k) << endl;
    return 0;
}
// Output: Count of subarrays with XOR 6 is: 4