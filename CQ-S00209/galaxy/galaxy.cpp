#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
int n,m,Q,tag[N],tag2[N],sum2;
ull val[N],val2[N],now[N],sum,tmp;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);srand(time(0));
	cin>>n>>m;for(int i=1;i<=n;i++)val[i]=rand()*rand(),tmp^=val[i];
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;val2[v]^=val[u],now[v]^=val[u],tag[v]++,tag2[v]++,sum^=val[u],sum2++;
	}
	cin>>Q;
	for(int i=1;i<=Q;i++){
		int op,u,v;
		cin>>op>>u;
		if(op==1)cin>>v,now[v]^=val[u],tag[v]--,sum2--,sum^=val[u];
		else if(op==2){
			sum2-=tag[u],tag[u]=0,sum^=now[u],now[u]=0;
		}
		else if(op==3)cin>>v,now[v]^=val[u],tag[v]++,sum2++,sum^=val[u];
		else if(op==4){
			sum2+=tag2[u]-tag[u],tag[u]=tag2[u],sum^=(val2[u]^now[u]),now[u]=val2[u];
		}
		if(sum2==n&&sum==tmp)puts("YES");else puts("NO");
	}
}
