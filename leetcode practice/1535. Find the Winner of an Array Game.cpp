class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
             if(k>=arr.size())
            return *max_element(arr.begin(),arr.end());
        int cnt=0,m=arr[0],x=arr[0],i=1;
        while(cnt!=k){
            arr.push_back(min(m,arr[i]));
            m=max(m,arr[i]);
            if(m==x)
                cnt++;
            else{
                x=arr[i];
                cnt=1;
            }
            i++;
        }
        return m;
    }
};
