#include <bits/stdc++.h> 
using namespace std;
long long n,m,k,yy[10001],xx[10001],a[2501],s[2501][2501],f[2501][2501],f1[2501][2501],ans;
bool v[2501];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	memset(s,0x3f,sizeof(s));
	for(long long i=1;i<n;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		xx[i]=x;
		yy[i]=y;
		s[x][y]=s[y][x]=1;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			f[i][j]=0x3f3f3f3f,v[j]=0;
		f[i][i]=0;
		q.push(make_pair(0,i));
		while(!q.empty()){
			long long no=q.top().second;
			q.pop();
			if(v[no]==1)
				continue;
			v[no]=1;
			for(long long j=1;j<=n;j++)
				if(f[i][j]>f[i][no]+s[no][j]){
					f[i][j]=f[i][no]+s[no][j];
					q.push(make_pair(f[i][j],j));
				}
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			if(i!=j&&f[i][j]<=k)
				f[i][j]=a[j];
			else
				f[i][j]=0x3f3f3f3f3f;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			f1[i][j]=0x3f3f3f3f,v[j]=0;
		f1[i][i]=0;
		q.push(make_pair(0,i));
		while(!q.empty()){
			long long no=q.top().second;
			q.pop();
			if(v[no]==1)
				continue;
			v[no]=1;
			for(long long j=1;j<=n;j++)
				if(f1[i][j]>f1[i][no]+f[no][j]){
					f1[i][j]=f1[i][no]+f[no][j];
					q.push(make_pair(f1[i][j],j));
				}
		}
	}
	for(int i=1;i<=m;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",a[x]+f1[x][y]);
	}
	return 0;
}
