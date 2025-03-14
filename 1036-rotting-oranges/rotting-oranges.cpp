class Solution {
public:
    bool checkIfAllRotted(vector<vector<int>>& grid)
    {
        for(vector<int> v : grid)
        {
            for(int i : v)
            {
                if(i == 1) return false;
            }
        }
        return true;
    }

    bool check(vector<vector<int>>& grid, int row, int col, char c)
    {
        if(c == 'l')
        {
            if(col > 0 && grid[row][col - 1] == 1) {grid[row][col - 1] = 2; return true;}
            else return false;
        }
        else if(c == 'r')
        {
            if(col < grid[0].size() - 1 && grid[row][col + 1] == 1) {grid[row][col + 1] = 2; return true;}
            else return false;
        }
        else if(c == 'u')
        {
            if(row > 0 && grid[row - 1][col] == 1) {grid[row - 1][col] = 2; return true;}
            else return false;
        }
        else if(c == 'd')
        {
            if(row < grid.size() - 1 && grid[row + 1][col] == 1) {grid[row + 1][col] = 2; return true;}
            else return false;
        }
        else return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
       int t = 0;

       int current = 0;
       queue<pair<int, int>> q;
       for(int i = 0; i < grid.size(); ++i)
       {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    current++;
                }
            }
       }

        int currentNext = 0;
        while(!checkIfAllRotted(grid) && !q.empty())
        {
            while(current--)
            {
                pair<int, int> p = q.front();
                int row = p.first;
                int col = p.second;
                if(check(grid, row, col, 'l')) {q.push({row, col - 1}); currentNext++;}
                if(check(grid, row, col, 'r')) {q.push({row, col + 1}); currentNext++;}
                if(check(grid, row, col, 'u')) {q.push({row - 1, col}); currentNext++;}
                if(check(grid, row, col, 'd')) {q.push({row + 1, col}); currentNext++;}
                q.pop();
            }
            t++;
            current = currentNext;
            currentNext = 0;
        }

        if(!checkIfAllRotted(grid)) return -1;
        else return t;
    }
};