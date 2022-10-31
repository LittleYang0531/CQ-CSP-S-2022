#include<bits/stdc++.h>
using namespace std;
int a[2222][2222],d[2222],v[2222],f[2222];
vector<int>fa[2222];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0,o=n;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		d[x]++;
		fa[y].push_back(x);
		f[y]++;
	}
	int q;
	cin>>q;
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y;
			cin>>x>>y;
			d[x]--;
			a[x][y]=0;
			if(d[x]+f[x]==0){
				v[x]=1;
			}
		}
		if(opt==3){
			int x,y;
			cin>>x>>y;
			d[x]++;
			a[x][y]=1;
			if(v[y]==1){
				v[y]=0;
			}
		}
		if(opt==2){
			int x;
			cin>>x;
			if(v[x]==0){
				v[x]=1;
			}
			for(int i=0;i<fa[x].size();i++){
				if(a[fa[x][i]][x]==0) continue;
				d[fa[x][i]]--;
			}
			f[x]=0;
		}
		if(opt==4){
			int x;
			cin>>x;
			if(v[x]==1){
				v[x]=0;
			}
			for(int i=0;i<fa[x].size();i++){
				if(a[fa[x][i]][x]==1) continue;
				d[fa[x][i]]++;
			}
			f[x]=fa[x].size();
		}
		int fl=0;
		for(int i=1;i<=n;i++){
			if(v[i]) continue;
			if(d[i]!=1){
				fl=1;
				break;
			}
		}
		if(fl){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	
	return 0;
}
//RP++!!!100£¡£¡£¡ 
