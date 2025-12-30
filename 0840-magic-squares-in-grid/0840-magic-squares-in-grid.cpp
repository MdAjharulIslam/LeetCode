class Solution {
public:

    bool isflag(int i, int j, vector<vector<int>>& grid){
         vector<int>v(10,0);
               bool flag=1;
                int r1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int r2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                int r3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                int c1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int c2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                int c3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                for(int k=i; k<i+3; k++){
                for(int l=j; l<j+3; l++){
                    int ele=grid[k][l];
                    if(ele==0 || ele>9 || v[ele]!=0){
                       return 0;
                    }
                    v[ele]++;
                }
                }
                if(r1==r2&&r2==r3&&r3==c1&&c1==c2&&c2==c3&&c3==d1&&d1==d2) return 1; 
                return 0; 
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        
        for(int i=0; i<=m-3; i++){
            for(int j=0; j<=n-3; j++){
                if(isflag(i,j,grid)) c++;
               
            }
        }
        return c;
    }
};