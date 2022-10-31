#include<bits/stdc++.h>
using namespace std;
long long n,q,k,ans,cnt,a[100050],fir[100050],dep[100050],fa[100050],dp1[100050],dp2[100050];//to LCA,the last one is chosen
struct edge{
	long long fr,to,nxt;
}e[200050];
void add(long long fr,long long to){
	e[++cnt].fr=fr;
	e[cnt].to=to;
	e[cnt].nxt=fir[fr];
	fir[fr]=cnt;
	return;
}
void dfs(long long x,long long la){
	dep[x]=dep[la]+1;
	fa[x]=la;
	for(int i=fir[x];i;i=e[i].nxt){
		if(e[i].to==la){
			continue;
		}
		dfs(e[i].to,x);
	}
	return;
}
long long LCa(long long x,long long y){
	while(x!=y){
		if(dep[y]>dep[x]){
			swap(x,y);
		}
		x=fa[x];
	}
	return x;
}
void sol(long long x,long long y){
	ans=0x3f3f3f3f3f3f3f3f;
	dp1[0]=dp2[0]=0;
	long long nw=x,lca=LCa(x,y),pos1=1,pos2=1;
//	cout<<lca<<endl;
	dp1[1]=a[nw];
	nw=fa[nw];
//	cout<<nw<<" "<<endl;
	while(nw!=fa[lca]){
//		cout<<nw<<" ";
		pos1++;
		dp1[pos1]=0x3f3f3f3f3f3f3f3f;
		for(int i=max(1ll,pos1-k);i<pos1;i++){
			dp1[pos1]=min(dp1[i],dp1[pos1]);
		}
//		cout<<pos1<<" "<<dp1[pos1]<<endl;
		dp1[pos1]+=a[nw];
		nw=fa[nw];
	}
//	cout<<endl;
//	cout<<endl;
	nw=y;
	dp2[1]=a[nw];
	nw=fa[nw];
	while(nw!=fa[lca]){
		pos2++;
		dp2[pos2]=0x3f3f3f3f3f3f3f3f;
		for(int i=max(1ll,pos2-k);i<pos2;i++){
			dp2[pos2]=min(dp2[i],dp2[pos2]);
		}
		dp2[pos2]+=a[nw];
		nw=fa[nw];
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp1[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<dp2[i]<<' ';
//	}
//	cout<<endl;
	for(int i=pos1;i>=max(1ll,pos1-k);i--){
		long long dis=pos1-i;
		for(int j=pos2;j>=max(1ll,pos2-k+dis);j--){
			long long tmp=dp1[i]+dp2[j];
			if(i==pos1&&j==pos2){
				tmp-=a[lca];
			}
			ans=min(ans,tmp);
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		long long fr,to;
		scanf("%lld%lld",&fr,&to);
		add(fr,to);
		add(to,fr);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		sol(x,y);
	}
	return 0;
}

