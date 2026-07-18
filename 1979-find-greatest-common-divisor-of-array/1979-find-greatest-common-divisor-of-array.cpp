class Solution {
public:
    int findGCD(vector<int>& nums) {
         int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        while (maxNum != 0) {
            int temp = maxNum;
            maxNum = minNum % maxNum;
            minNum = temp;

        }

        return minNum;
    }
};