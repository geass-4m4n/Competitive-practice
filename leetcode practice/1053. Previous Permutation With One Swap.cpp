class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int ind=0;
        for(int i=A.size()-1;i>=1;i--){
            if(A[i]>=A[i-1]){
                continue;
            }else{
                ind=i-1;
                break;
            }
        }
        int s=ind+1,e=A.size()-1;
        int a=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(A[mid]<A[ind]){
                a=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        swap(A[ind],A[a]);
        return A;
    }
};
