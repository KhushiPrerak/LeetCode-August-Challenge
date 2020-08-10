class Solution {
public:
    
    class Orange {
        public: 
        int row;
        int col;
        int time;
        Orange(int row, int col, int time) {
            this->row=row;
            this->col=col;
            this->time=time;
        }
    };
    
    int a[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n==0) return -1;
        int m=grid[0].size();
        if(m==0) return -1;
        
        queue<Orange> pending;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    grid[i][j]=0;
                    Orange orange(i,j,0);
                    pending.push(orange);
                }
            }
        }
        int ans = 0;
        while(!pending.empty()){
            Orange current = pending.front();
            pending.pop();
            
            ans = current.time;
            
            for(int k=0;k<4;k++) {
                int newRow = current.row + a[k][0];
                int newCol = current.col + a[k][1];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1) {
                    grid[newRow][newCol]=0;
                    Orange orange(newRow, newCol, current.time+1);
                    pending.push(orange);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};
