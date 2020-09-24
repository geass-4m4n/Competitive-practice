class Solution {
public:
     long long dp[105][105];
    long long solve(int cur,int index,vector<vector<int>>&clips,int T){
        if(cur>=T){
            return 0;
        }
        if(index>=clips.size()){
            return INT_MAX;
        }
        if(cur<clips[index][0]){
            return INT_MAX;
        }
        if(dp[cur][index]!=-1){
            return dp[cur][index];
        }
        long long op1 =solve(clips[index][1],index+1,clips,T)+1;
        long long op2 =solve(cur,index+1,clips,T);
        return dp[cur][index]=min(op1,op2);
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        long long ans = solve(0,0,clips,T);
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};
