#include<bits/stdc++.h>
using namespace std;
int n,m,q,opt,u,v;
int po[10005][10005];
void cheak() {
	bool o=0;
	for(int i=1; i<=n; i++) {
		int sum=0;
		for(int j=1;j<=n;j++){
			if(po[i][j]==1) sum++; 
		}
		if(sum!=1) {
			o=1;
			break;
		}
	}
	if(o==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		po[u][v]=1;
		po[u][0]++;
	}
	cin>>q;
	int opt;
	while(q--) {
		cin>>opt;
		if(opt==1) {
			cin>>u>>v;
			po[u][v]=0;
			po[u][0]--;
			cheak();
		}
		if(opt==2) {
			cin>>u;
			for(int i=1; i<=n; i++) po[i][u]=0;
			po[u][0]=0;
			cheak();
		}
		if(opt==3) {
			cin>>u>>v;
			po[u][v]=1;
			po[u][0]++;
			cheak();
		}
		if(opt==4) {
			cin>>u;
			for(int i=1; i<=n; i++) po[i][u]=1;
			po[u][0]=n;
			cheak();
		}
	}
	return 0;
}
