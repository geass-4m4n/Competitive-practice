#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int n,q,x,cnt2=0,cnt4=0,cnt6=0,cnt8=0;
    cin>>n;
    map<int,int>m;
    while(n--){
        cin>>x,m[x]++;
    }
    cin>>q;
    for(auto i:m){
        if(i.second>=8) cnt8++;
        else if(i.second>=6) cnt6++;
        else if(i.second>=4) cnt4++;
        else if(i.second>=2) cnt2++;
    }
    while(q--){
        cin>>c>>x;
        if(c=='-'){
            if(m[x]==8) cnt8--,cnt6++;
            else if(m[x]==6) cnt6--,cnt4++;
            else if(m[x]==4) cnt4--,cnt2++;
            else if(m[x]==2) cnt2--;
            m[x]--;
        }else{
            if(m[x]==7) cnt8++,cnt6--;
            else if(m[x]==5) cnt6++,cnt4--;
            else if(m[x]==3) cnt4++,cnt2--;
            else if(m[x]==1) cnt2++;
            m[x]++;
        }
        if(((cnt2>1||cnt6||cnt8)&&cnt4>0)||(cnt6>0&&cnt2>0)||(cnt4>1)||(cnt8>0)||(cnt6>1)) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
