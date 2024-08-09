bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool ans = false;
        
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                queue<pair<int,int>>q;
                q.push({i,-1});
                vis[i] = 1;
                 while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(auto it: adj[a]){
                if(vis[it] && it!=b){
                    ans = true;
                    return ans;
                }
                else if(!vis[it]){
                    q.push({it,a});
                    vis[it] = 1;
                }
            }
            
        }               
            }
        }



bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool ans = false;
        
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                queue<pair<int,int>>q;
                q.push({i,-1});
                vis[i] = 1;
                 while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(auto it: adj[a]){
                if(vis[it] && it!=b){
                    ans = true;
                    return ans;
                }
                else if(!vis[it]){
                    q.push({it,a});
                    vis[it] = 1;
                }
            }
            
        }               
            }
        }



	int minStepToReachTarget(vector<int>&k,vector<int>&t,int n)
	{
	    // Code here
	    if(k[0]==t[0] && k[1]==t[1]) return 0;
	    int x = k[0];
	    int y = k[1];
	    x--; y--;
	    vector<vector<int>>b(n,vector<int>(n,0));
	    queue<pair<int,int>>q;
	    q.push({x,y});
	    b[x][y] = 1;
	    int ct = 0;
	    while(!q.empty()){
	        int sz = q.size();
	        ct++;
	        for(int i = 0; i<sz;i++){
	            int xx = q.front().first;
	            int yy = q.front().second;
	            q.pop();
	            vector<int>dx = {2,2,-2,-2,1,1,-1,-1};
	            vector<int>dy = {1,-1,1,-1,2,-2,2,-2};
	            for(int j = 0; j<8;j++){
	                int nx = dx[j]+xx;
	                int ny = dy[j]+yy;
	                if(nx>=n || ny>=n || nx<0 || ny<0 || b[nx][ny]) continue;
	                b[nx][ny] = ct;
	                q.push({nx,ny});
	            }
	        }
	    }
	    return b[t[0]-1][t[1]-1];
	}


