#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int dis[N],ben[N];
vector<int>b[N];
map<int,int>Y[N];
int fro[N]/*out*/,cnt1;
void del(int id){
	dis[id]=1,fro[ben[id]]--;
	if(fro[ben[id]]==1)cnt1++;
	else if(fro[ben[id]]==0)cnt1--;
}
void add(int id){
	dis[id]=0,fro[ben[id]]++;
	if(fro[ben[id]]==1)cnt1++;
	else if(fro[ben[id]]==2)cnt1--;
}
int main(){
	//满足每个点出度为1即可 
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ben[i]=x;
		fro[x]++;
		b[y].push_back(i);
		Y[x][y]=i;
	}
	for(int i=1;i<=n;i++)cnt1+=(fro[i]==1);
	int q;
	scanf("%d",&q);
	while(q--){
		int op,x,y;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			int id=Y[x][y];
			del(id);
		}
		if(op==2){
			scanf("%d",&x);
			for(int i=0;i<(int)b[x].size();i++){
				int id=b[x][i];
				if(!dis[id])del(id);
			}
		}
		if(op==3){
			scanf("%d%d",&x,&y);
			int id=Y[x][y];
			add(id);
		}
		if(op==4){
			scanf("%d",&x);
			for(int i=0;i<(int)b[x].size();i++){
				int id=b[x][i];
				if(dis[id])add(id);
			}
		}
		if(cnt1==n)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
