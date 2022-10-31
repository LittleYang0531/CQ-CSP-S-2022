#include<bits/stdc++.h>
#define MAXN 500005
#define MAXD 30005
using namespace std;
int h[MAXN],s[MAXN],vst[MAXN],rem[50][MAXD],l[MAXN],ans,cnt,n,m,k,x,y,z;
struct edge{
	int to,next;
}e[MAXN];
void addedge(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void DFS(int v,int p,int sum,int q,int flag){
	if (p>5)return;
	if (sum<rem[p][v]&&flag==1)return;
	if (flag==1)rem[p][v]=sum;
	if (p==5&&v==1&&flag==1){	
		if (sum>ans)ans=sum;
		return;
	}
	for (int i=h[v];i;i=e[i].next){
		int u=e[i].to;
		if (vst[u]==0){
			vst[u]=1;
			DFS(u,p+1,sum+s[u],k,1);
			vst[u]=0;
		}
		if (q>0)DFS(u,p,sum,q-1,2);
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=2;i<=n;i++)scanf("%d",&s[i]),l[i]=s[i];
	sort(l+2,l+n+1);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if (k>=m){
		for (int i=n;i>=n-4;i--)ans+=l[i];
	}
	else DFS(1,0,0,k,1);
	cout <<ans<<endl;
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

8 8 100
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
