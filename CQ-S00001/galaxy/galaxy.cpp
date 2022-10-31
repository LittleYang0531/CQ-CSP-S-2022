#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;

int n,m,q,cnt,flag;
int broken[maxn],in[maxn],out[maxn];
map<int,int> mp[maxn];

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++) {
		cin>>u>>v;
		mp[u][v]=i;
		out[u]++,in[v]++;
	}
	cin>>q;
	for(int i=1,t,u,v;i<=q;i++) {
		cin>>t;
		if(t==1) {
			cin>>u>>v;
			broken[mp[u][v]]=1;
			out[u]--,in[v]--;
		}
		if(t==2) {
			cin>>u;
			for(int j=1;j<=n;j++) if(mp[j][u]&&broken[mp[j][u]]==0) broken[mp[j][u]]=1,out[j]--,in[u]--;
		}
		if(t==3) {
			cin>>u>>v;
			broken[mp[u][v]]=0;
			out[u]++,in[v]++;
		}
		if(t==4) {
			cin>>u;
			for(int j=1;j<=n;j++) if(mp[j][u]&&broken[mp[j][u]]==1) broken[mp[j][u]]=0,out[j]++,in[u]++;
		}
		flag=1;
		for(int j=1;j<=n;j++) if(out[j]!=1) flag=0;
		cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}
