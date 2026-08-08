class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         vector<int> right(word2.size(),-1);
        if(word2.size()==1) return {0};

        int r = word2.size()-1;
        for(int i = word1.size()-1; i>=0;i--){
            if(word2[r]==word1[i]){
                right[r]=i;
                r--;
            }
            if(r<0){
                break;
            }
        }

      
        vector<int> res;
        int l = 0;
        bool used = false;
        for(int i = 0; i<word1.size();i++){
            if(word1[i]==word2[l]){
                res.push_back(i);
                l++;
            }
            else if(!used && (l==word2.size()-1 || i<right[l+1])){
                used = true;
                res.push_back(i);
                l++;
            }
            if(l>=word2.size()) return res;
        }

        return {};
    }
};