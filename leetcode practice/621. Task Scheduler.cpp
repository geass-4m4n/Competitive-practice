class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mpp;
        int maxx = -1;
        for(auto x:tasks){
            mpp[x]++;
            maxx = max(maxx , mpp[x]);
        }
        int partitions = maxx - 1;
        int cnt = 0 ;
        for(auto x : mpp){
            if(x.second == maxx) ++cnt;
        }
        int emptyslots = partitions * (n - (cnt - 1)) ;
        if(emptyslots <= 0){
            return tasks.size() ;
        }
        else {
            int availabletasks = tasks.size() - maxx * cnt;
            int idles = max(0 , emptyslots - availabletasks);
            int ans = idles + tasks.size() ;
            return ans ;
        }
    }
};
