#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// Function to find the largest subarray with sum 0
int largestSubarrayWithSumZero(vector<int>& arr) {
    unordered_map<int, int> sumIndexMap; // Map to store sum and its index
    int maxLength = 0; // Variable to store the maximum length of subarray
    int sum = 0; // Variable to store the cumulative sum

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Update the cumulative sum

        // If the cumulative sum is 0, update maxLength
        if (sum == 0) {
            maxLength = i + 1;
        }

        // If the cumulative sum has been seen before, update maxLength
        if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[sum]);
        } else {
            // Store the index of the first occurrence of this sum
            sumIndexMap[sum] = i;
        }
    }
    return maxLength; // Return the maximum length of subarray with sum 0
}
// Main function to test the largestSubarrayWithSumZero function
int main() {
    vector<int> arr = {1, -1, 2, -2, 3, -3, 4}; // Example array
    int result = largestSubarrayWithSumZero(arr); // Call the function
    cout << "The length of the largest subarray with sum 0 is: " << result << endl; // Output the result
    return 0; // Return success
}
// Output: The length of the largest subarray with sum 0 is: 6