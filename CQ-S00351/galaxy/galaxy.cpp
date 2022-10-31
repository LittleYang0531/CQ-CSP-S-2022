#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],n,m,c[500005],d[500005],q,u,v,t,e[500005],f[500005],po[8005][8005],top;
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	if(n>=1e3*8+1 || m>=1e3*8+1) {
		for(int i=1; i<=m; i++) {
			cin>>u>>v;
			++c[u];
		}
		cin>>q;
		for(long long i=1; i<=n; i++)
		{
			if(c[i]!=1)
				++top;e[i]=c[i];
		}
		for(long long i=1; i<=q; i++) {
			cin>>t;
			if(t==1) {
				cin>>u>>v;
				--e[u];
				if(e[u]==1)
					--top;
				if(e[u]==0)
					++top;
			} else {
				cin>>u>>v;
				++e[u];
				if(e[u]==1)
					--top;
				if(e[u]==2)
					++top;
			}
			if(top==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	} else {
		for(int i=1; i<=m; i++) {
			cin>>u>>v;
			po[u][v]=1;
			++c[u];
		}
		cin>>q;
		for(long long i=1; i<=n; i++)
		{
			if(c[i]!=1)
			++top;e[i]=c[i];
		}
		for(long long i=1; i<=q; i++) {
			cin>>t;
			if(t==1) {
				cin>>u>>v;
				++po[u][v];
				--e[u];
				if(e[u]==1)
					--top;
				if(e[u]==0)
					++top;
			} else if(t==3) {
				cin>>u>>v;
				--po[u][v];
				++e[u];
				if(e[u]==1)
					--top;
				if(e[u]==2)
					++top;
			}	else if(t==2) {
				cin>>u;
				for(int j=1; j<=n; j++) {
					if(po[j][u]==1) {
						++po[j][u];
						--e[j];
						if(e[j]==1)
							--top;
						if(e[j]==0)
							++top;
					}
				}
			} else {
				cin>>u;
				for(int j=1; j<=n; j++) {
					if(po[j][u]==2) {
						--po[j][u];
						++e[j];
						if(e[j]==1)
							--top;
						if(e[j]==2)
							++top;
					}
				}
			}
			if(top==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
