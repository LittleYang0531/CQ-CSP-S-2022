#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,ans,a[10050],fir[10050];
bool vis[2550];
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
void dfs(long long x,long long pa,long long ud,long long val){
	if(ud>4){
		return;
	}
	for(int i=fir[x];i;i=e[i].nxt){
		if(pa==k){
			if(ud==4&&e[i].to!=1){
				continue;
			}
			if(ud==4&&e[i].to==1){
				ans=max(val,ans);
//				for(int i=1;i<=n;i++){
//					cout<<vis[i];
//				}
//				cout<<endl;
				return;
			}
			if(vis[e[i].to]==0){
				vis[e[i].to]=1;
				dfs(e[i].to,0,ud+1,val+a[e[i].to]);
				vis[e[i].to]=0;
			}
		}else{
			if(ud==4&&e[i].to==1){
				ans=max(val,ans);
				return;
			}
			if(ud!=4&&e[i].to!=1&&vis[e[i].to]==0){
				vis[e[i].to]=1;
				dfs(e[i].to,0,ud+1,val+a[e[i].to]);
				vis[e[i].to]=0;
			}
			dfs(e[i].to,pa+1,ud,val);
		}
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		long long fr,to;
		scanf("%lld%lld",&fr,&to);
		add(fr,to);
		add(to,fr);
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}

