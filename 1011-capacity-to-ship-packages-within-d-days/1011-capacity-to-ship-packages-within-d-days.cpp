class Solution {
public:

    // Returns how many days are needed with given capacity
    int countDays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {

            // Current package fit ho jayega
            if (load + weights[i] <= capacity) {
                load += weights[i];
            }
            // Naya din start karo
            else {
                days++;
                load = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = countDays(weights, mid);

            if (requiredDays <= days) {
                high = mid - 1;   // Chhoti capacity try karo
            }
            else {
                low = mid + 1;    // Capacity badhao
            }
        }

        return low;
    }
};