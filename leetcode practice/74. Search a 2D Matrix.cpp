class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
        int n=a.size();
        if(n<1)return false;
            
        int m=a[0].size();
        
        int l=0;
        int h=n*m;
        h--;
        while(l<=h)
        {
            int mi=(l+h)/2;
            cout<<mi<<endl;
            int x=mi/m;
            int y=mi%m;
            int k=a[x][y];
            if(k==t)return true;
            else if(k>t)
                h=mi-1;
            else
                l=mi+1;
        }
        
        
        return false;
        
    }
};
