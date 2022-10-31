#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
}b[444444];
long long s[444444],cnt=0;
long long add(long long x,long long y){
	cnt++;
	b[cnt].v=y;
	b[cnt].w=s[x];
	s[x]=cnt;
	return 0;
}
long long f[444444],st[444444],a[444444];
long long ans=0,o=0;
long long k;
long long dfs(long long x,long long y,long long fa){
	st[++o]=x;
	if(x==y){
		f[st[1]]=a[st[1]];
		for(long long i=2;i<=o;i++){
			f[st[i]]=0x3f3f3f3f3f3f3f3f;
			for(long long j=1;j<=k;j++){
				f[st[i]]=min(f[st[i]],f[st[max(i-j,1ll)]]+a[st[i]]);
			}
			ans=f[st[o]];
		}
		o--;
		return 0;
	}
	for(long long i=s[x];i;i=b[i].w){
		long long xx=b[i].v;
		if(xx!=fa){
			dfs(xx,y,x);
		}
	}
	o--;
	return 0;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	long long n,q;
	cin>>n>>q>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-1;i++){
		long long x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		ans=0;
		dfs(x,y,0);
		cout<<ans<<endl;
	}
	return 0;
}
//RP++!!!100!!!
