class Solution {
public:
    
    
    bool dfs(int x, vector<int> &color,vector<vector<int>>& graph,int c){
        
        color[x] = c;
        bool ans = true;
        
        for(int i = 0;i < graph[x].size();i++){
            int adj = graph[x][i];
            
            if(color[adj] == color[x]){
                return false;
            }else if(color[adj] == -1){
                ans &= dfs(adj, color, graph, c^1);
            }
            
            if(ans == false){
                break;
            }
        }
        
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);
        bool ans = true;
        
        
        for(int i = 0;i < n;i++){
            if(color[i] == -1)
                ans &= dfs(i, color, graph, 0); 
            
            if(ans == false){
                break;
            }
        }
        
        return ans;
    }
};