class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff,sum=nums[0]+nums[1]+nums[2],n=nums.size();
        diff=abs(target-sum);
        int l,r,tempsum,tempdiff;
        for(int i=0;i<n-2 && diff!=0 ;i++)
        {   l=i+1;
            r=n-1;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            while(l<r)
            {
                tempsum=nums[i]+nums[l]+nums[r];
                tempdiff=tempsum-target;
                if(abs(tempdiff)<diff)
                {
                    sum=tempsum;
                    diff=abs(tempdiff);
                }
                if(tempdiff==0) 
                    break;
                else if(tempdiff>0)
                    r--;
                else
                    l++;
            }
        }
    return sum;
    }
};