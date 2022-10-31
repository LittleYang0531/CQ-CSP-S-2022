#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
int n,m,q;
int cnt=0,cntt=0;
int h[MAXN],hh[MAXN];
int use[MAXN],vis[MAXN],vit[MAXN];
struct lyt{
	int to;
	int next;
}a[MAXN];
struct see{
	int to;
	int next;
}b[MAXN];
void add(int x,int y) {
	cnt++;
	a[cnt].to=y;
//	cout<<cnt<<"NBNBNBNB"<<y<<endl;
	a[cnt].next=h[x];
	h[x]=cnt;
	cntt++;
	b[cntt].to=x;
	b[cntt].next=hh[y];
	hh[y]=cntt;
	return;
}
void off_1(int x,int y){
	for(int i=h[x];i;i=a[i].next){
//		cout<<"wc"<<i<<" "<<a[i].to<<endl;
		if(a[i].to==y){
			use[x]--;
//			cout<<"off"<<i<<endl;
			vis[i]=1;
			break;
		}
	}
	return;
}
void off_2(int x){
	for(int i=hh[x];i;i=b[i].next){
//		cout<<"off"<<i<<endl;
		if(!vis[i]){
			use[b[i].to]--;
			vis[i]=1;
		}
	}
	return;
}
void open_1(int x,int y){
	for(int i=h[x];i;i=a[i].next){
		if(a[i].to==y){
			use[x]++;
//			cout<<"open"<<i<<endl;
			vis[i]=0;
			break;
		}
	}
	return;
}
void open_2(int x){
	for(int i=h[x];i;i=a[i].next){
		if(vis[i]){
//			cout<<"open"<<i<<endl;
			use[x]++;
		}
		vis[i]=0;
	}
	for(int i=hh[x];i;i=b[i].next){
		if(vis[i]){
//			cout<<"open"<<i<<endl;
			use[b[i].to]++;
		}
		vis[i]=0;
	}
	return;
}
bool fire_dfs(int x){
//	cout<<x<<endl;
	for(int i=h[x];i;i=a[i].next){
		int v=a[i].to;
		if(!vis[i]){
			if(vit[v]){
				return true;
			}else{
				vit[v]=1;
				if(fire_dfs(v)){
					return true;
				}
			}	
		}
	}
	return false;
}
bool fire(){
	for(int i=1;i<=n;i++){
		if(use[i]!=1){
			return false;
		}
		memset(vit,0,sizeof(vit));
		vit[i]=1;
		if(!fire_dfs(i)){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		use[u]++;
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		int type,u,v;
		scanf("%lld%lld",&type,&u);
		if(type==1){
			scanf("%lld",&v);
			off_1(u,v);
		}else if(type==2){
			off_2(u);
		}else if(type==3){
			scanf("%lld",&v);
			open_1(u,v);
		}else if(type==4){
			open_2(u);
		}
//		for(int j=1;j<=m;j++){
//			cout<<vis[j]<<" ";
//		}
//		cout<<endl;
//		for(int j=1;j<=n;j++)`{
//			cout<<use[j]<<" ";
//		}
//		cout<<endl;
		if(fire()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
