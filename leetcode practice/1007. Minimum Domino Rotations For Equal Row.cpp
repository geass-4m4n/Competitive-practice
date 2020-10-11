class Solution {
public:
    int solve(vector<int>& a, vector<int>& b,int k)
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==k)
                continue;
            if(b[i]==k)
                ans++;
            else
                return -1;
        }
        return ans;
        
    }
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n=a.size();
            if(n<1 || n!=b.size())
                return 0;
        
        int op1=a[0];
        int op2=b[0];
        
        int a1=solve(a,b,op1);
        int a2=solve(a,b,op2);
        int a3=solve(b,a,op1);
        int a4=solve(b,a,op2);
        
        if(a1==-1 && a2==-1 && a3==-1 &&a4==-1)
            return -1;
        
        if(a1==-1)
            a1=INT_MAX;
         if(a2==-1)
            a2=INT_MAX;
         if(a3==-1)
            a3=INT_MAX;
         if(a4==-1)
            a4=INT_MAX;
        
        return min(min(a1,a2),min(a3,a4));
        
    }
};
