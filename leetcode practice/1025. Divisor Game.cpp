class Solution {
public:
     int dp[1001];
    
    int solve(int N)
    {
        if(N == 1) 
            return false;
        if(dp[N] != -1) 
            return dp[N]; 
        for(int i = 1; i < N; i++)
        {
            if(N%i == 0){
                if(!solve(N-i))
                    return dp[N] = 1;
            }
        }
        return dp[N] == 0;
    }
    
    bool divisorGame(int N) {
        memset(dp, -1, sizeof(dp));
        return solve(N);
    }
    
    
};
