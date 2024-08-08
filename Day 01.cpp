vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>vis(V,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int a= q.front();
            q.pop();
            ans.push_back(a);
            for(auto it: adj[a]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }

void solve(int n,vector<int>adj[], vector<int>&ans, vector<int>&vis){
        vis[n] = 1;
        ans.push_back(n);
        for(auto it: adj[n]){
            if(!vis[it]){
                solve(it,adj,ans,vis);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>ans;
        
        solve(0,adj,ans,vis);
        return ans;
    }


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        if (image[sr][sc] == newColor) return image;

        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        vis[sr][sc] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            ans[x][y] = newColor;

            if (x > 0 && image[x-1][y] == initialColor && !vis[x-1][y]) {
                q.push({x-1, y});
                vis[x-1][y] = 1;
            }
            if (y > 0 && image[x][y-1] == initialColor && !vis[x][y-1]) {
                q.push({x, y-1});
                vis[x][y-1] = 1;
            }
            if (x < n-1 && image[x+1][y] == initialColor && !vis[x+1][y]) {
                q.push({x+1, y});
                vis[x+1][y] = 1;
            }
            if (y < m-1 && image[x][y+1] == initialColor && !vis[x][y+1]) {
                q.push({x, y+1});
                vis[x][y+1] = 1;
            }
        }

        return ans;
    }
