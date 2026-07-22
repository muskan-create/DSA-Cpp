class Solution {
public:
    int day(vector<int>& weights,int capacity){
        int day=0;
        int c=capacity;

        for(int i=0;i<weights.size();i++){
            if(c>=weights[i]){
                c-=weights[i];
            }
            else{
                day++;
                c=capacity-weights[i];
            }
        }

        day++;
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=0;
        int hi=0;

        for(int i=0;i<n;i++){
            hi+=weights[i];
            lo=max(lo,weights[i]);
        }

        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(day(weights,mid)<=days){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        return ans;
    }
};