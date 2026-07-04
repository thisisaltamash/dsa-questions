class Solution {
public:

    // Finds the first position where target can be placed
    // (First occurrence of target)
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;          // Possible answer
                high = mid - 1;     // Search on left side
            } else {
                low = mid + 1;      // Search on right side
            }
        }

        return ans;
    }

    // Finds the first position greater than target
    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = mid;          // Possible answer
                high = mid - 1;     // Search on left side
            } else {
                low = mid + 1;      // Search on right side
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = lowerBound(nums, target);

        // Target not present
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        // Last occurrence = upperBound - 1
        int last = upperBound(nums, target) - 1;

        return {first, last};
    }
};