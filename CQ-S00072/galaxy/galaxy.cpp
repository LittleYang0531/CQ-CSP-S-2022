#include<bits/stdc++.h>
using namespace std;
int n,m;
int q;
struct Node{
	int to,next;
}e[1000005];
int h[1000005],cnt;
void add(int x,int y){
	cnt++;
	e[cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int t;
		scanf("%d",&t);
		int u,v;
		if(t==1){
			scanf("%d%d",&u,&v);
		}
		else if(t==2){
			scanf("%d",&u);
		}
		if(t==3){
			scanf("%d%d",&u,&v);
		}
		else{
			scanf("%d",&u);
		}
		if(u==t||v==t){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
