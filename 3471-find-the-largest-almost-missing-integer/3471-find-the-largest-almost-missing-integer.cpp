class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
       int n = nums.size();

        int freq[51] = {};

        for (int x : nums) {
            freq[x]++;
        }

        if (k == 1) {
            for (int x = 50; x >= 0; x--) {
                if (freq[x] == 1) {
                    return x;
                }
            }

            return -1;
        }

        if (k == n) {
            int answer = 0;

            for (int x : nums) {
                answer = max(answer, x);
            }

            return answer;
        }

        int answer = -1;

        if (freq[nums[0]] == 1) {
            answer = max(answer, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            answer = max(answer, nums[n - 1]);
        }

        return answer;
    }
};