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






class Solution {
    
    void solve(int x, int y,vector<vector<int>> &mat, set<string>&st, vector<vector<int>>&vis, string &path){
        int n = mat.size();
        int m = mat[0].size();
        
        if(x==n-1 && y==n-1){
            st.insert(path);
            return;
        }
        vis[x][y] = 1;
        vector<int>dx = {-1,1,0,0};
        vector<int>dy = {0,0,-1,1};
        vector<char>dp = {'U','D','L','R'};
        for(int i = 0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || !mat[nx][ny] || vis[nx][ny]) continue;
            path += dp[i];
            solve(nx,ny,mat,st,vis,path);
            path.pop_back();
        }
        vis[x][y] = 0;
    }
    
    
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        if(!mat[0][0]){
            ans.push_back("-1");
            return ans;
        } 
        
        set<string>st;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        string path  = "";
        solve(0,0,mat,st,vis,path);
        
        if(st.size()==0){
            ans.push_back("-1");
            return ans;
        } 
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
