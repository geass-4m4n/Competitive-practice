class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        if(n<3)
            return n;
        
        int ans=1;
        if(a[0]!=a[1])
            ans++;
        for(int i=2;i<a.size();i++)
        {
            if(a[i-2]==a[i] && a[i-1]==a[i])
            {
                a.erase(a.begin()+i);
                i--;
            }
            
        }
        
        return a.size();
    }
};
