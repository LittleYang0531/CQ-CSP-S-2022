#include<bits/stdc++.h>
#define N 2505
#define M 20005 
using namespace std;
int n,m,k,d[N][N],h[N],cnt;
long long f[6][N];
long long a[N],ans;
int t[4];
vector<int> v[N];
bool bj[N];
struct bb{
	int to,next;
}w[M];
void ad(int x,int y){
	w[++cnt].to=y;
	w[cnt].next=h[x];
	h[x]=cnt;
}
void bfs(int s){
	for(int i=1;i<=n;i++)bj[i]=0;
	queue<int> q;
	q.push(s);
	d[s][s]=0;
	bj[s]=1;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=w[i].next){
			int y=w[i].to;
			if(!bj[y]){
				d[s][y]=d[s][x]+1;
				if(d[s][y]<=k+1)v[s].push_back(y);
				bj[y]=1;
				q.push(y);
			}
		}
	}
}
int dfs(int x,int t[4],long long s){
	if(f[x][t[x-1]])return f[x][t[x-1]];
	if(x==5){
		if(d[t[3]][1]<=k+1){
			ans=max(ans,s);
		}
		return 0;
	}
	if(x==1){
		for(auto i:v[1]){
			t[0]=i;
			long long tt=dfs(x+1,t,s+a[i]);
			ans=max(ans,tt+s);
			f[x+1][t[x-2]]=max(f[x+1][t[x-2]],tt);
		}
		t[0]=0;
	}else if(x==2){
		for(auto i:v[t[0]]){
			if(i!=1){
				t[1]=i;
				long long tt=dfs(x+1,t,s+a[i]);
				ans=max(ans,tt+s);
				f[x+1][t[x-2]]=max(f[x+1][t[x-2]],tt);
			}
		}
		t[1]=0;
	}else if(x==3){
		for(auto i:v[t[1]]){
			if(i!=1&&i!=t[0]){
				t[2]=i;
				long long tt=dfs(x+1,t,s+a[i]);
				ans=max(ans,tt+s);
				f[x+1][t[x-2]]=max(f[x+1][t[x-2]],tt);
			}
		}
		t[2]=0;
	}else if(x==4){
		for(auto i:v[t[2]]){
			if(i!=1&&i!=t[0]&&i!=t[1]){
				t[3]=i;
				long long tt=dfs(x+1,t,s+a[i]);
				ans=max(ans,tt+s);
				f[x+1][t[x-2]]=max(f[x+1][t[x-2]],tt);
			}
		}
		t[3]=0;
	}
	return f[x+1][t[x-2]];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);
		ad(y,x);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	dfs(1,t,0);
	printf("%lld\n",ans);
	return 0;
}
