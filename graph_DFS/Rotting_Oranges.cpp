class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<pair<int,int>,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int oranges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
                oranges++;
                
            }
            if (grid[i][j] == 1) {
                oranges++;
            }
        }
    }   

    int mintime = 0;
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    int rotten_oranges = 0;

    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int t = q.front().second;
        q.pop();
        
        mintime = max(mintime, t);
        rotten_oranges++;

        for (int d = 0; d < 4; d++) {
            int x = i + dirx[d];
            int y = j + diry[d];

            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1) {
                vis[x][y] = 1;
                grid[x][y] = 2;
                q.push({{x, y}, t + 1});
            }
        }
    }
    
    if (rotten_oranges != oranges ) {
        return -1; 
    }

    return mintime;
}

};