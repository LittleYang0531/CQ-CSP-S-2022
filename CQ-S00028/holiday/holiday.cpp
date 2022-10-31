#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
ll n,m,k;
ll val[maxn];
struct node{
	ll data,nxt;
}a[maxn];
ll first[maxn],cnt;
ll v[2505][2505];//¾àÀë 
ll vis[2505];
struct U{
	ll val;
	int id;
};
bool cmp(U x,U y){
	return x.val>y.val;
}
vector<U>B[2505],C[2505];
void add(int x,int y){
	a[++cnt].data=y;
	a[cnt].nxt=first[x];
	first[x]=cnt;
}
void bfs(int x){
	for(int i=1;i<=n;i++)vis[i]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int y=q.front();
		q.pop();
		vis[y]=1;
		for(int i=first[y];i;i=a[i].nxt){
			int k=a[i].data;
			if(vis[k])continue;
			v[x][k]=v[x][y]+1;
			if(vis[k]==0)q.push(k);
			vis[k]=1;
		}
	}
}
void init_s1(){
	for(int i=2;i<=n;i++){//A
		for(int j=2;j<=n;j++){//B
			if(i==j)continue;
			if(v[1][i]>k+1||v[i][j]>k+1)continue;
			B[j].push_back((U){val[i],i});
		}
	}
	for(int i=1;i<=n;i++)if(B[i].size())sort(B[i].begin(),B[i].end(),cmp);
}
void init_s2(){
	for(int i=2;i<=n;i++){//C
		for(int j=2;j<=n;j++){//D
			if(i==j)continue;
			if(v[i][j]>k+1||v[j][1]>k+1)continue;
			C[i].push_back((U){val[j],j});
		}
	}
	for(int i=1;i<=n;i++)if(C[i].size())sort(C[i].begin(),C[i].end(),cmp);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)bfs(i);
	init_s1();
	init_s2();
	ll ans=0;
	for(int i=2;i<=n;i++){//B
		for(int j=2;j<=n;j++){//C
			if(i==j)continue;
			if(B[i].size()==0||C[j].size()==0)continue;
			int p1=B[i][0].id,p2=C[j][0].id;
			if(p1!=p2&&p1!=j&&p2!=i){
				if(v[1][p1]>k+1||v[p1][i]>k+1||v[i][j]>k+1||v[j][p2]>k+1||v[p2][1]>k+1)continue;
				ans=max(ans,val[p1]+val[p2]+val[i]+val[j]);
			}
			else{
				for(int p=0;p<B[i].size();p++){
					p1=B[i][p].id;
					if(p1!=p2&&p1!=j&&p2!=i){
						if(v[1][p1]>k+1||v[p1][i]>k+1||v[i][j]>k+1||v[j][p2]>k+1||v[p2][1]>k+1)continue;
						ans=max(ans,val[p1]+val[p2]+val[i]+val[j]);
						break;
					}
				}
				p1=B[i][0].id,p2=C[j][0].id;
				for(int p=0;p<C[j].size();p++){
					p2=C[j][p].id;
					if(p1!=p2&&p1!=j&&p2!=i){
						if(v[1][p1]>k+1||v[p1][i]>k+1||v[i][j]>k+1||v[j][p2]>k+1||v[p2][1]>k+1)continue;
						ans=max(ans,val[p1]+val[p2]+val[i]+val[j]);
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//%%%
