class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> dirx={-1,1,0,0};
        vector<int> diry={0,0,-1,1};

        queue<pair<int,int>> q;
        int ei=entrance[0];
        int ej=entrance[1];

        q.push({ei,ej});
        vis[ei][ej]=1;
     
        int count=0;
         while (!q.empty()) {
            int size = q.size();
            count++;
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int x = i + dirx[d];
                    int y = j + diry[d];

                    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && maze[x][y] != '+') {
                        if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && !(x == ei && y == ej)) {
                            return count;
                        }
                        q.push({x, y});
                        vis[x][y] = 1;
                    }
                }
            }
        }

        return -1;
    }
};