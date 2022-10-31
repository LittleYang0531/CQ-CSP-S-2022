#include<bits/stdc++.h>
#define int long long
#define inf 10000000000
//belief2022
using namespace std;
struct node{
	int vol,to,next;
};
struct nd{
	int i,zhi,f,fr,fro;
};
node e[400086];
int rd(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n,k,qu,ben,o,leo=inf,dis[200005],head[400086],cnt,a[20005],ans,chao=inf;
queue<nd>q;
bool inq[200086];
void spf(int s){
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[s]=0;
	inq[s]=1;
	nd az;az.i=0;az.zhi=s;
	q.push(az);
	while(!q.empty()){
		nd x=q.front();
		nd azz;
		if(x.zhi==ben)leo=min(azz.f,leo);
		azz.i=x.i+1;azz.f=x.zhi ;azz.fr =x.f ;azz.fro=x.fr;
		if(x.i>k){
			k+=o;
			azz.f=min(min(x.f+e[x.zhi].vol,x.fr+e[x.zhi].vol),x.fro+e[x.zhi].vol);
		}
		for(int i=head[x.zhi];i;i=e[i].next){
			azz.zhi=e[i].to;
			if(dis[azz.zhi]>dis[x.zhi]+e[i].vol){
				dis[azz.zhi]=min(dis[azz.zhi],dis[x.zhi]+e[i].vol);
				if(inq[azz.zhi]==0){
					inq[azz.zhi]=1;
					q.push(azz);
				}
			}
		}
		inq[x.zhi]=0;
		q.pop();
	}
}
void spfa(int s){
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[s]=0;
	inq[s]=1;
	nd az;az.i=0;az.zhi=s;
	q.push(az);
	while(!q.empty()){
		nd x=q.front();
		nd azz;
		azz.i=x.i+1;
		for(int i=head[x.zhi];i;i=e[i].next){
			azz.zhi=e[i].to;
			if(dis[azz.zhi]>dis[x.zhi]+e[i].vol){
				dis[azz.zhi]=min(dis[azz.zhi],dis[x.zhi]+e[i].vol);
				if(inq[azz.zhi]==0){
					inq[azz.zhi]=1;
					q.push(azz);
				}
			}
		}
		inq[x.zhi]=0;
		q.pop();
	}
}
void add(int fr,int to,int da){
	e[++cnt].next=head[fr];
	e[cnt].to=to;
	head[fr]=cnt;
	e[cnt].vol=da;
}
main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=rd();qu=rd();k=rd();o=k;
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<n;i++){
		int x=rd(),y=rd();
		add(x,y,a[y]);
		add(y,x,a[x]);
	}
	while(qu--){
		int x=rd(),y;ben=rd();y=ben;
		if(k==1)spfa(x);
		else spf(x);
		cout<<dis[y]<<endl;
	}
}
