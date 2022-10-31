#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
}b[222222];
long long s[222222],cnt=0,k;
long long a[222222],d[2505][2505];
long long v[222222],f[22222][5],vis[22222][5][5];
long long add(long long x,long long y){
	cnt++;
	b[cnt].v=y;
	b[cnt].w=s[x];
	s[x]=cnt;
	return 0;
}
long long dfs(long long x,long long ss,long long id){
	d[id][x]=1;
	if(ss==k){
		return 0;
	}
	for(long long i=s[x];i;i=b[i].w){
		long long xx=b[i].v;
		if(v[xx]!=id){
			v[xx]=id;
			dfs(xx,ss+1,id);
		}
	}
	return 0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	long long n,m;
	cin>>n>>m>>k;
	k++;
	for(long long i=1;i<=n-1;i++){
		cin>>a[i+1];
	}
	for(long long i=1;i<=m;i++){
		long long x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(long long i=1;i<=n;i++){
		dfs(i,0,i);
	}
	for(long long i=2;i<=n;i++){
		if(d[1][i]){
			f[i][1]=a[i];
			vis[i][1][1]=i;
		}
	}
	for(long long yu=2;yu<=4;yu++){
		for(long long i=2;i<=n;i++){
			for(long long j=2;j<=n;j++){
				if(i==j) continue;
				if(f[j][yu-1]==0) continue;
				if(d[i][j]){
					
					long long fl=0;
					for(long long l=1;l<=yu-1;l++){
						if(vis[j][yu-1][l]==i){
							fl=1;
							break;
						}
					}
					
					if(fl) continue;
					
					if(f[i][yu]<f[j][yu-1]+a[i]){					
						f[i][yu]=f[j][yu-1]+a[i];
						for(long long l=1;l<yu;l++){
							vis[i][yu][l]=vis[j][yu-1][l];
						}
						vis[i][yu][yu]=i;
					}
				}
			}
		}
	}
//	for(long long yu=1;yu<=4;yu++){
//		for(long long i=2;i<=n;i++){
//			cout<<f[i][yu]<<" ";
//		}
//		cout<<endl;
//	}
	long long ans=0;
	for(long long i=2;i<=n;i++){
		if(d[i][1]){
			ans=max(ans,f[i][4]);
		}
	}
	cout<<ans;
	return 0;
}
//RP++!!!100!!!
