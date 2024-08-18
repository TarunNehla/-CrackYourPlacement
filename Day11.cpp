class Solution {

    int solve(int n, vector<vector<int>>& adj, vector<int>& ift){
        int ans = 0;
        for(auto it: adj[n]){
            ans = max(ans, ift[n]+solve(it,adj,ift));
        }
        return ans;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++){
            if(i==headID) continue;
            adj[manager[i]].push_back(i);
        }
        return solve(headID,adj,informTime);
    }
};

                                                                               
