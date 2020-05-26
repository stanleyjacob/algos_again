class Solution {
public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph = {}; 
        for (int i = 0; i < n; ++i) {
            graph.push_back({});
        }
        
        int dfs_level = 0;
        
        vector<int> lowest_rank_arr = {};
        for (int i = 0; i < n; ++i) {
            lowest_rank_arr.push_back(i);
        } 
        
        vector<bool> visited = {};
        for (int i = 0; i < n; ++i) {
            visited.push_back(false);
        }
        
        for (vector<int> conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        } 
        
        vector<vector<int>> res = {};
        int prev_vertex = -1; 
        int curr_vertex = 0;
        
        dfs(res, graph, lowest_rank_arr, visited, dfs_level, prev_vertex, curr_vertex);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& res,
            vector<vector<int>>& graph,
            vector<int>& lowest_rank_arr,
            vector<bool>& visited,
            int dfs_level, 
            int prev_vertex, 
            int curr_vertex) {
        
        visited[curr_vertex] = true;
        lowest_rank_arr[curr_vertex] = dfs_level;
        
        for (int next_vertex : graph[curr_vertex]) {
            if (next_vertex == prev_vertex) {
                continue;
            }
            
            if (!visited[next_vertex]) {
                dfs(res, graph, lowest_rank_arr, visited, dfs_level + 1, curr_vertex, next_vertex);
            }
            
            lowest_rank_arr[curr_vertex] = min(lowest_rank_arr[curr_vertex], lowest_rank_arr[next_vertex]);
            if (lowest_rank_arr[next_vertex] >= (dfs_level + 1)) {
                res.push_back({curr_vertex, next_vertex});
            }
        }
    }
    
};
