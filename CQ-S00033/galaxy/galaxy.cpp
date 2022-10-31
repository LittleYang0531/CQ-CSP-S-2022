#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q;
int g[5003][5003];
int d[500003],cnt;
vector<int> e[500003];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		d[u]++;
		if(n<=5e3) g[u][v] = 1;
		if(n<=5e3) e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1) cnt++;
	}
	cin >> q;
	while(q--){
		int t,u,v,lst;
		cin >> t;
		if(t==1 || t==3){
			cin >> u >> v;
			lst=d[u]; 
			if(t==1){
				d[u]--;
				if(n<=5e3) g[u][v]=0;
			}else{
				d[u]++;
				if(n<=5e3) g[u][v]=1;
			}
			if(lst!=1){
				if(d[u]==1) cnt++;
			}else{
				if(d[u]!=1) cnt--;
			}
		}else{
			cin >> u;
			if(t==2){
				for(int i=0;i<e[u].size();i++){
					v=e[u][i];
					if(g[v][u]){
						lst = d[v];
						g[v][u]=0;
						d[v]--;
						if(lst==1) cnt--;
						else{
							if(d[v]==1) cnt++;
						}
					}
				}
			}else{
				for(int i=0;i<e[u].size();i++){
					v=e[u][i];
					if(!g[v][u]){
						lst = d[v];
						g[v][u]=1;
						d[v]++;
						if(lst==1) cnt--;
						else{
							if(d[v]==1) cnt++;
						}
					}
				}
			}
		}
		if(cnt==n){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}

