class Solution {
public:

    // Check if we can split into at most k subarrays
    bool possible(vector<int>& nums, int k, long long maxSum) {

        long long sum = 0;
        int count = 1;     // At least one subarray

        for (int num : nums) {

            // Need a new subarray
            if (sum + num > maxSum) {
                count++;
                sum = num;
            }
            else {
                sum += num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = *max_element(nums.begin(), nums.end());

        long long high = 0;
        for (int x : nums)
            high += x;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (possible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;     // Try smaller answer
            }
            else {
                low = mid + 1;      // Increase allowed sum
            }
        }

        return ans;
    }
};