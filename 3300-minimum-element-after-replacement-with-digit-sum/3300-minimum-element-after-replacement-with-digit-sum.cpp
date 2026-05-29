class Solution {
public:
    int minElement(vector<int>& nums) {
       int ans = INT_MAX;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int sum=0;

            while(num>0){
                sum+= (num%10);
                num/=10;
            }

            if(sum<ans) ans=sum;
        }
        return ans; 
    }
};