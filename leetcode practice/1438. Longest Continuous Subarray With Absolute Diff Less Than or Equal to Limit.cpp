class Solution {
public:
    int longestSubarray(vector<int>& a, int l) {
        
        int i = 0, j;
        multiset<int> set;
        int ans=1;
        for(j = 0; j < a.size(); j++){
            set.insert(a[j]);
            if(*set.rbegin() - *set.begin() > l){
                set.erase(set.find(a[i++]));
            }
            ans=max(ans,j-i+1);
        }
        return ans;
        
        
    }
};
