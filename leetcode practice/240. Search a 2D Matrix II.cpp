class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
         int n = matrix.size();
        if( n == 0 ) return false;
        int m = matrix[0].size();
        if( m == 0 ) return false;
        
        
        int i = 0, j = m-1; 
        while( i < n && j >= 0 ) {
            if( target > matrix[i][j] )
                i++;
            else if ( target < matrix[i][j] )
                j--;
            else 
                return true;
        }
        return false;
    }
};
