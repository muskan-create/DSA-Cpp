class Solution {
public:
    int n;
    int getsum(vector<int> &cnt){
        return (max(0,cnt[2])+2)/3 + (max(cnt[3],0)+1)/2 + max(cnt[5],0) + max(cnt[7],0)
                            - (max(0,cnt[2])%3 == 1 && max(0,cnt[3])%2 == 1);
    }
    
    void op(vector<int> &cnt, char c, int val){
        int x = c - '0';
        if(!x) return;
        while(x%2 == 0) cnt[2] += val, x /= 2;
        while(x%3 == 0) cnt[3] += val, x /= 3;
        if(x == 5) cnt[5] += val;
        if(x == 7) cnt[7] += val;
    }
    
    void perform(vector<int> &cnt, string &nums, int i){
        int k = i+1, sum = getsum(cnt);
        while(sum < n-i-1){
            nums[k++] = '1';
            sum++;
        }
        
        if(max(0,cnt[2])%3 != 0 && max(0,cnt[3])%2 == 1){
            if(cnt[2]%3 == 2) nums[k++] = '2', cnt[2] -= 1;
            while(cnt[5] > 0) nums[k++] = '5', cnt[5] -= 1;
            nums[k++] = '6', cnt[2] -= 1, cnt[3] -= 1;
        }
        if(cnt[2]%3 == 1 && cnt[2] > 0) nums[k++] = '2', cnt[2] -= 1;
        if(cnt[3]%2 == 1 && cnt[3] > 0) nums[k++] = '3', cnt[3] -= 1;
        if(cnt[2]%3 == 2 && cnt[2] > 0) nums[k++] = '4', cnt[2] -= 2;
        
        while(cnt[5] > 0) nums[k++] = '5', cnt[5] -= 1;
        while(cnt[7] > 0) nums[k++] = '7', cnt[7] -= 1;
        while(cnt[2] > 0) nums[k++] = '8', cnt[2] -= 3;
        while(cnt[3] > 0) nums[k++] = '9', cnt[3] -= 2;
    }
    
    string smallestNumber(string nums, long long t) {
        vector<int> cnt(10);
        for(int i = 2; i <= 9; i++){
            while(t%i == 0) cnt[i]++, t /= i;
        }
        if(t != 1) return "-1";
        n = nums.size();
    
        for(int i = 0; i < n; i++){
            op(cnt, nums[i], -1);
            if(nums[i] == '0'){
                nums[i] = '1'; 
                if(getsum(cnt) <= n-i-1){
                    perform(cnt, nums, i);
                    return nums;
                }
            }
        }
        
        int sum = 0;
        for(int i = 2; i <= 9; i++) if(cnt[i] > 0) sum += cnt[i];
        if(sum == 0) return nums;
        
        nums = '0' + nums;
        while(nums.size() < 30) nums = '0' + nums;
        n = nums.size();        
        
        for(int i = n-1; i >= 0; i--){
            op(cnt, nums[i], 1);
            
            for(int j = nums[i]-'0'+1; j <= 9; j++){
                op(cnt, j+'0', -1);
                if(getsum(cnt) <= n-i-1){
                    nums[i] = j+'0';
                    perform(cnt, nums, i);
                    int idx = 0;
                    while(nums[idx] == '0') idx++;
                    return nums.substr(idx);
                }
                op(cnt, j+'0', 1);
            }            
        }
        return "-1";
    }
};