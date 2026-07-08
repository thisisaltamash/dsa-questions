class Solution {
public:
    int sumofd(vector<int>& arr, int div) {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] + div - 1) / div;   // ceil(arr[i] / div)
        }

        return sum;
    }

    int smallestDivisor(vector<int>& arr, int limit) {

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (sumofd(arr, mid) <= limit) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};