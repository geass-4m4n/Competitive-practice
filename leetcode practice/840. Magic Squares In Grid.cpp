class Solution {
public:
    bool solution(vector<vector<int>>&grid,int start_row,int end_row,int start_col,int end_col){
        unordered_map<int,int>mp;
        int d1_sum =grid[start_row][start_col]+grid[start_row+1][start_col+1]+grid[start_row+2][start_col+2];
        int d2_sum =grid[start_row][end_col]+grid[start_row+1][end_col-1]+grid[start_row+2][end_col-2];
       
        if(d1_sum!=d2_sum){
            return false;
        }
        int sum  = d1_sum;
        
        //check for row sum;
        for(int i=start_row;i<=end_row;i++){
            int cur_sum =0;
            for(int j=start_col;j<=end_col;j++){
                if(grid[i][j]>9 or grid[i][j]<1){
                    return false;
                }
                if(mp.find(grid[i][j])!=mp.end()){
                    return false;
                }
                else{
                    mp[grid[i][j]]=1;
                }
                cur_sum+=grid[i][j];
            }
            if(cur_sum!=sum){
                return false;
            }
        }
        for(int j=start_col;j<=end_col;j++){
            int cur_sum=0;
            for(int i=start_row;i<=end_row;i++){
                cur_sum+=grid[i][j];
            }
            if(cur_sum!=sum){
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        if(m<3 or n<3){
            return 0;
        }
        int ans =0;
        int start_col =0;
        int start_row =0;
        int end_col =2;
        int end_row =2;
        int i,j;
        int p,q;
        for(i=start_row,j=end_row;j<m;i++,j++){
            for(p=start_col,q=end_col;q<n;p++,q++){
                if(solution(grid,i,j,p,q)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
