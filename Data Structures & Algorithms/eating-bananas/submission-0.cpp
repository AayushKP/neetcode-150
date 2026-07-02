class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int pile : piles) {
            if (pile > maxPile)
                maxPile = pile;
        }

        int low = 1;
        int high = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                high = mid - 1;   // Try a smaller eating speed
            } else {
                low = mid + 1;    // Need a larger eating speed
            }
        }

        return low;
    }
};
