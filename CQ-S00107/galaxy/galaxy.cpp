#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int head[500005],nxt[500005],to[500005];
int d[500005],book[500005];
long long cnt;
void add(int u,int v){
	nxt[++cnt]=head[u];to[cnt]=v;
	head[u]=cnt;book[cnt]=1;
}
void init(){
	for(int i=1;i<=n;i++)
		for(int j=head[i];j;j=nxt[j])
			d[i]++;
}
void solve(int t){
	int u,v,flag;
	if(t==1){
		scanf("%d%d",&u,&v);
		flag=1;
		for(int i=head[u];i;i=nxt[i])
			if(to[i]==v&&book[i]){flag=0;d[u]--;book[i]=0;break;}
	}
	else if(t==2){
		scanf("%d",&u);
		for(int i=1;i<=n;i++)
			for(int j=head[i];j;j=nxt[j])
				if(to[j]==u&&book[j]){book[j]=0;d[i]--;}
	}
	else if(t==3){
		scanf("%d%d",&u,&v);
		for(int i=head[u];i;i=nxt[i])
			if(to[i]==v&&!book[i]){d[u]++;book[i]=1;break;}
	}
	else if(t==4){
		scanf("%d",&u);
		for(int i=1;i<=n;i++)
			for(int j=head[i];j;j=nxt[j])
				if(to[j]==u&&!book[j]){book[j]=1;d[i]++;}
	}
	flag=0;
	for(int i=1;i<=n;i++)
		if(d[i]!=1){flag=1;break;}
	if(flag)printf("NO\n");
	else printf("YES\n");
	//for(int i=1;i<=n;i++)cout<<d[i]<<endl;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	init();
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		solve(t);
	}
	return 0;
}
