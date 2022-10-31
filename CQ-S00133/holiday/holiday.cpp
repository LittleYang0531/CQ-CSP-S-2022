#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll n,m,k,val[2505],first_a[2505],cnt,dis[2505],first_b[2505],ans;
struct q1{
	ll u,w,nex;
}a[20005],b[6250005];
void add(ll u1,ll w1,q1 a[],ll first[]){
	a[++cnt].u=u1;
	a[cnt].w=w1;
	a[cnt].nex=first[u1];
	first[u1]=cnt;
}
struct node{
	ll w1,num,numb;
	set<int> g;
	bool operator < (const node&t) const{
		return t.num>num;
	}
};
queue<node> q;
priority_queue<node> p;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(ll i=2;i<=n;i++){
		val[i]=read();
	}
	for(ll i=1,x,y;i<=m;i++){
		x=read();
		y=read();
		add(x,y,a,first_a);
		add(y,x,a,first_a);
	}
	for(ll j=1;j<=n;j++){
		memset(dis,127,sizeof(dis));
		node x;
		x.w1=j;
		x.num=0;
		q.emplace(x);
		dis[j]=0;
		while(!q.empty()){
			node k=q.front();
			q.pop();
			for(ll i=first_a[k.w1];i;i=a[i].nex){
				if(dis[a[i].w]>dis[k.w1]+1){
					dis[a[i].w]=dis[k.w1]+1;
					node x;
					x.w1=a[i].w;
					x.num=dis[a[i].w];
					q.emplace(x);
				}
			}
		}
		for(ll i=1;i<=n;i++){
			if(dis[i]<=k+1&&i!=j)
				add(j,i,b,first_b);
		}
	}
	memset(dis,128,sizeof(dis));
	for(ll i=first_b[1];i;i=b[i].nex){
		node k;
		k.w1=b[i].w;
		k.num=val[b[i].w];
		k.numb=1;
		k.g.insert(b[i].w);
		k.g.insert(1);
		p.emplace(k);
		dis[b[i].w]=val[b[i].w];
	}
	while(!p.empty()){
		node k=p.top();
		p.pop();
		if(dis[k.w1]>k.num)
			continue;
		for(ll i=first_b[k.w1];i;i=b[i].nex){
			if(k.numb==4&&b[i].w!=1)
				continue;
			if(dis[b[i].w]<k.num+val[b[i].w]){
				if(k.numb==4&&b[i].w==1){
					ans=max(ans,k.num);
					continue;
				}
				if(k.g.find(b[i].w)==k.g.end()){
					dis[b[i].w]=k.num+val[b[i].w];
					node x=k;
					x.g.insert(b[i].w);
					x.numb++;
					x.num=dis[b[i].w];
					x.w1=b[i].w;
					p.emplace(x);
				}
			}
		}
	}
	work(ans);
	return 0;
}
