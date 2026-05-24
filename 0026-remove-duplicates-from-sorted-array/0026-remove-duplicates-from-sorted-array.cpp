class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while(j < nums.size()){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
                j++; 
                continue;
            }
            j++;
        }
        return i+1;
    }
};