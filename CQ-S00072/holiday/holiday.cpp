#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long s[2505];
long long Map[2505][2505];
long long cnt[2505];
long long f[10005];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;++i){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;++i){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		cnt[a]++;
		cnt[b]++;
		Map[a][cnt[a]]=b;
		Map[b][cnt[b]]=a;
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=cnt[i];++j){
			f[Map[i][j]]=max(f[Map[i][j]],f[i]+s[Map[i][j]]);
		}
	}
	long long maxn=0;
	for(int i=1;i<=n;++i){
//		cout<<f[i]<<" ";
		maxn=max(maxn,f[i]);
	}
//	cout<<endl;
	printf("%lld",maxn);
	return 0;
}
