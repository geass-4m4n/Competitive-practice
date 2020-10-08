class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
         stack<int> st;
        int n=A.size(), ans=0;
        st.push(0);
        for(int i=1; i<n; i++)
            if(A[st.top()]>A[i]) st.push(i);
        
        for(int i=n-1; i>=0; i--)
        {
           
            
            while(!st.empty() && A[st.top()]<=A[i]){
                ans=max(ans, i-st.top());
                st.pop();
            }
        }
        return ans;
        
    }
};
