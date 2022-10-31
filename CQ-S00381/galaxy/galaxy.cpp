#include<bits/stdc++.h>
#define LL long long
#define Max(x,y) (x<y?y:x)
#define Min(x,y) (x<y?x:y)
#define LLF (1e18+10)
using namespace std;
/*
int t[200005],las[200005],fir[2505],num;
void add(int u,int v){
	t[++num]=v;
	las[num]=fir[u];
	fir[u]=num;
}*/
int mp[1005][1005];
int sp[1005][1005];
int oud[1005];
int n,m,q;
int vxxr[1005];
queue<int> Q;
int bfs(int rt){
	while(Q.size())Q.pop();
	memset(vxxr,0,sizeof vxxr);
	Q.push(rt);
	vxxr[rt]=1;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=1;i<=n;i++){
			if(sp[u][i] == 0)continue;
			if(vxxr[i])return 1;
			vxxr[i]=1;
			Q.push(i);
		}
	}
	return 0;
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		oud[x]++;
		mp[x][y]=1;
		sp[x][y]=1;
	}
	int cnt=m;
	cin>>q;
	for(int i=1;i<=n;i++){
//			cout<<oud[i]<<' ';
//			if(oud[i] !=1){
//				fl=0;
//				break;
//			}
		}
	for(int i=1;i<=q;i++){
		int t,u;
		scanf("%d%d",&t,&u);
		if(t == 1){
			int v;
			scanf("%d",&v);
			sp[u][v]=0;
			cnt--;
			oud[u]--;
		}else if(t == 2){
			for(int i=1;i<=n;i++){
				if(sp[i][u] == 1){
					sp[i][u]=0;
					oud[i]--;
					cnt--;
				}
			}
		}else if(t == 3){
			int v;
			scanf("%d",&v);
			sp[u][v]=1;
			oud[u]++;
			cnt++;
		}else{
			for(int i=1;i<=n;i++){
				if(sp[i][u] == 0){
					sp[i][u]=1;
					oud[i]++;
					cnt++;
				}
			}
		}
		int fl=1;
		for(int i=1;i<=n;i++){
//			cout<<oud[i]<<' ';
			if(oud[i] !=1||bfs(i)){
				fl=0;
				break;
			}
		}
		if(fl){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	} 
	return 0;
}
