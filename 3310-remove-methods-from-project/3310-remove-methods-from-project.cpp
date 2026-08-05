class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
      vector<vector<int>>g(n);
        vector<int>vis(n);
        for(auto &e:invocations) g[e[0]].push_back(e[1]);
        queue<int>q;
        q.push(k);
        vis[k]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        for(auto &e:invocations){
            if(!vis[e[0]] && vis[e[1]]){
                vector<int>ans;
                for(int i=0;i<n;i++)ans.push_back(i);
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)if(!vis[i]) ans.push_back(i);
        return ans;   
    }
};