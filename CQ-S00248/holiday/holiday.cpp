#include <bits/stdc++.h> 
using namespace std;
long long n,m,k,yy[10001],xx[10001],a[2501],s[2501][2501],f[2501][2501],f1[2501],ans;
bool v[2501];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	k++;
	for(long long i=2;i<=n;i++)
		scanf("%lld",&a[i]);
	memset(s,0x3f,sizeof(s));
	for(long long i=1;i<=m;i++){
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
				f[i][j]=-1;
	for(int j=2;j<=n;j++)
	if(f[1][j]!=-1)
	for(long long i=2;i<=n;i++)
	if(i!=j){
		long long j1=1,j2=1,an1=-4e18,an2=-4e18;
		for(j1=2;j1<=n;j1++)
			if(f[1][j1]!=-1&&f[j1][i]!=-1&&(j1!=j&&j1!=i&&j1!=1))
				an1=max(an1,a[j1]);
		for(j2=2;j2<=n;j2++)
			if(f[j][j2]!=-1&&f[j2][i]!=-1&&j1!=j2&&(j2!=j&&j2!=i&&j2!=1))
				an2=max(an2,a[j2]);
		ans=max(ans,an1+an2+a[i]+a[j]);
	}
	printf("%lld",ans);
	return 0;
}
