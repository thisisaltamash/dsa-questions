class Solution {
public:
    int findMax(vector<int>& v){
        int maxi = INT_MIN;
        for(int x : v)
            maxi = max(maxi, x);
        return maxi;
    }

    long long calculatetotalhours(vector<int>& v, int hourly){
        long long totalh = 0;

        for(int x : v){
            totalh += (x + hourly - 1) / hourly;
        }

        return totalh;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
        int high = findMax(v);

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalh = calculatetotalhours(v, mid);

            if(totalh <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};