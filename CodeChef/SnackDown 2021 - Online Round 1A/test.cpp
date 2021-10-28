class Solution {
    int64_t n;
    map<int64_t,int64_t> mp;
    public:
    
   
    
    int64_t solve(int64_t x, vector<int64_t> Adj[], vector<int64_t> &B){
        
        int64_t ans = 1;
      
        // children 
        int64_t cur = 1;
        int64_t up = n;
        for(int64_t child : Adj[x]){
            up -= B[child];
            cur *= B[child];
        }
        up--;
        
        if(up > 0) cur *= up;
        
        
        for(int64_t child:Adj[x]){
            ans = max(ans, solve(child, Adj, B));
        }
        
        
        // cout << x << ": " << cur << endl;
        mp[cur]++;
        return max(ans, cur);
    }
    
    
    int64_t dfs(int64_t x, vector<int64_t> Adj[], vector<int64_t> &Below){
        
        int64_t ans = 1;
        
        for(int64_t child : Adj[x]){
            ans += dfs(child, Adj, Below);
        }
        
        return Below[x] = ans;
    }
    
    
    
    int countHighestScoreNodes(vector<int>& parents) {
       
        n = parents.size();
        vector<int> Adj[n];
        mp.clear();
        
        for(int64_t i = 1;i < n;i++){
            int64_t u = i;
            int64_t v = parents[i];
            
            Adj[v].push_back(u);
        }
        
        vector<int64_t> Below(n, 0);
        dfs(0, Adj, Below);    
        
        int64_t ans = solve(0, Adj, Below);
        
        return mp[ans];
    }
};