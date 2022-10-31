#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
queue<int>q;
int v[20010],nxt[20010],head[2510],tot;
int dis[2510][2510],dp1[2510],dp2[2510],dp3[2510],pts[2510];
int n,m,k;
long long ans;
void add(int fr,int to){
	v[++tot]=to;
	nxt[tot]=head[fr];
	head[fr]=tot;
	return;
}
void bfs(int s){
	dis[s][s]=0;
	q.push(s);
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		for(int i=head[pos];i!=0;i=nxt[i]){
			if(dis[s][v[i]]>dis[s][pos]+1){
				dis[s][v[i]]=dis[s][pos]+1;
				q.push(v[i]);
			}
		} 
	}
	return;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
//	freopen("E:\\CSP-S\\holiday\\holiday3.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	memset(dis,0x3f,sizeof(dis));
	for(int i=2;i<=n;i++){
		scanf("%d",&pts[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int i=2;i<=n;i++){
		if(dis[1][i]<=(k<<1)){
			for(int j=2;j<=n;j++){
				if(i==j)continue;
				if(dis[1][j]<=k&&dis[j][i]<=k){
					if(pts[j]>=pts[dp1[i]]){
						dp3[i]=dp2[i];
						dp2[i]=dp1[i];
						dp1[i]=j;
					}else{
						if(pts[j]>=pts[dp2[i]]){
							dp3[i]=dp2[i];
							dp2[i]=j;
						}else{
							if(pts[j]>=pts[dp3[i]]){
								dp3[i]=j;
							}
						}
					}
				}
			}
		}
	}
	for(int B=2;B<=n;B++){
		if(dis[1][B]>(k<<1))continue;
		for(int C=2;C<=n;C++){
			if(B==C)continue;
			if(dis[B][C]<=k&&dis[C][1]<=(k<<1)){
				int A=dp1[B];
				if(A==C){
					A=dp2[B];
				}
				int D=dp1[C];
				if(D==A||D==B){
					D=dp2[C];
					if(D==A||D==B){
						D=dp3[C];
					}
				}
				if(A==0||D==0)continue;
				ans=max(ans,pts[A]*1ll+pts[B]*1ll+pts[C]*1ll+pts[D]*1ll);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

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

*/
