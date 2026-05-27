class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int  maxlen = 0;
        int len = 0;
        for(int i = 0;i<s.size();i++){
            vector<int> hash(256,0);
            for(int j = i;j<s.size();j++){
                if(hash[s[j]] == 1){
                    break;
                }
                len = j-i+1;
                maxlen = max(len,maxlen);
                hash[s[j]] = 1;
            }
        }
        return maxlen;
    }
};