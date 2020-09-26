class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
         int temp[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                temp[i][j]=N;
        }
        for(auto i:mines)temp[i[0]][i[1]]=0;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0,k=N-1,u=0,d=0,l=0,r=0;j<N;j++,k--)
            {
                temp[i][j]=min(temp[i][j],u=(temp[i][j]==0?0:u+1));
                temp[i][k]=min(temp[i][k],d=(temp[i][k]==0?0:d+1));
                temp[j][i]=min(temp[j][i],l=(temp[j][i]==0?0:l+1));
                temp[k][i]=min(temp[k][i],r=(temp[k][i]==0?0:r+1));
            }
        }
        int res=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                res=max(res,temp[i][j]);
        }
        return res;
        
    }
};
