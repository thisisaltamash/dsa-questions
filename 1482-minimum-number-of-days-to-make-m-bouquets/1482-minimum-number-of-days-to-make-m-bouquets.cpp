class Solution {
public:

    bool possible(vector<int>& arr, int m, int k, int day){
        int cnt = 0;
        int noOfb = 0;

        for(int i = 0; i < arr.size(); i++){

            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfb += cnt / k;
                cnt = 0;
            }
        }

        noOfb += cnt / k;

        return noOfb >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {

        long long val = 1LL * m * k;

        if(val > arr.size()) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int x : arr){
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        int low = mini;
        int high = maxi;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(possible(arr, m, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};