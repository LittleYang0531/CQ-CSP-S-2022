#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=5e5+5,mod=1e9+7,sd1=19260817,sd2=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return (long long)a*b%mod;}
int n,m,q;
int pw1[N],pw2[N];
int s1,s2,t1,t2;
int a1[N],a2[N],mark[N];
vector<int> v1[N],v2[N];
inline void ins(int x){
	s1=add(s1,pw1[x]),s2=add(s2,pw2[x]);	
}
inline void del(int x){
	s1=add(s1,mod-pw1[x]),s2=add(s2,mod-pw2[x]);	
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=in(),m=in();
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++){
		pw1[i]=mul(pw1[i-1],sd1);
		pw2[i]=mul(pw2[i-1],sd2);
		t1=add(t1,pw1[i]),t2=add(t2,pw2[i]);
		mark[i]=1;	
	}
	for(int i=1;i<=m;i++){
		int x=in(),y=in();
		a1[y]=add(a1[y],pw1[x]);
		a2[y]=add(a2[y],pw2[x]);
		ins(x);
	}
	q=in();
	while(q--){
		int op=in(),x=in(),y;
		if(op==1){
			y=in(),del(x);
			v1[y].push_back(x);
		}
		if(op==3){
			y=in(),ins(x);
			v2[y].push_back(x);
		}
		if(op==2||op==4){
			for(int y:v1[x])ins(y);
			for(int y:v2[x])del(y);
			v1[x].clear(),v2[x].clear();
			if(op==2&&mark[x]){
				s1=add(s1,mod-a1[x]);
				s2=add(s2,mod-a2[x]);
				mark[x]=0;
			}
			if(op==4&&!mark[x]){
				s1=add(s1,a1[x]);
				s2=add(s2,a2[x]);
				mark[x]=1;	
			}
		}
		if(s1==t1&&s2==t2)puts("YES");
		else puts("NO");
	}
	return 0;
}
