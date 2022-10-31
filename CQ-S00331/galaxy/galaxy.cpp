#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int chudu[500005],dengyu0,dayu1;
bool cannot[500005];
int cnt=1,fir[500005],to[1000005],nex[1000005],fir1[500005],to1[1000005],nex1[1000005];
void add(int u,int v){
	to[++cnt]=v;
	nex[cnt]=fir[u];
	fir[u]=cnt;
	to1[++cnt]=u;
	nex1[cnt]=fir1[v];
	fir1[v]=cnt;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		chudu[u]++;
	}
	for(int i=1;i<=n;i++){
		if(chudu[i]==0)dengyu0++;
		if(chudu[i]>1)dayu1++;
	}
	scanf("%d",&q);
	while(q--){
		int t;scanf("%d",&t);
		if(t==1){
			int u,v;
			scanf("%d%d",&u,&v);
			for(int i=fir[u];i;i=nex[i])
				if(to[i]==v)
					{cannot[i]=1;break;}
			chudu[u]--;
			if(chudu[u]==1)dayu1--;
			if(chudu[u]==0)dengyu0++;
			if(dayu1==0&&dengyu0==0)printf("YES\n");
			else printf("NO\n");
		}
		else if(t==2){
			int k;
			scanf("%d",&k);
			for(int i=fir1[k];i;i=nex1[i])
				if(!cannot[i^1])
					{cannot[i^1]=1;chudu[to1[i]]--;if(chudu[to1[i]]==1)dayu1--;if(chudu[to1[i]]==0)dengyu0++;}
			if(dayu1==0&&dengyu0==0)printf("YES\n");
			else printf("NO\n");
		}
		else if(t==3){
			int u,v;
			scanf("%d%d",&u,&v);
			for(int i=fir[u];i;i=nex[i])
				if(to[i]==v)
					{cannot[i]=0;break;}
			chudu[u]++;
			if(chudu[u]==1)dengyu0--;
			if(chudu[u]==2)dayu1++;
			if(dayu1==0&&dengyu0==0)printf("YES\n");
			else printf("NO\n");
		}
		else{
			int k;
			scanf("%d",&k);
			for(int i=fir1[k];i;i=nex1[i])
				if(cannot[i^1])
					{cannot[i^1]=0;chudu[to1[i]]++;if(chudu[to1[i]]==1)dengyu0--;if(chudu[to1[i]]==2)dayu1++;}
			if(dayu1==0&&dengyu0==0)printf("YES\n");
			else printf("NO\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}