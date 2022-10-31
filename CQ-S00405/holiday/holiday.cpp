#include<bits/stdc++.h>
#define MAXN 2505
#define MAXM 10010
#define R register
using namespace std;
int n,m,k,d[MAXN][MAXN];
long long ans,sum,s[MAXN],dis[MAXN];
bool hv[MAXN];
vector<int> p[MAXN],p2[MAXN];
struct node{
	int id,sum;
	bool friend operator<(node a,node b){
		return a.sum<b.sum;
	}
};
priority_queue<node> q;
bitset<MAXN> v,v2;
inline void dj(int mi){
	for(R int i=1;i<=n;i++) d[mi][i]=99999999;
	d[mi][mi]=0;
	while(q.size()) q.pop();
	v&=v2;
	q.push(node{mi,0});
	while(q.size()){
		node kk=q.top();
		q.pop();
		if(v[kk.id]) continue;
		//cout<<mi<<' '<<kk.id<<'\n';
		v[kk.id]=1;
		for(int i=0;i<p[kk.id].size();i++){
		//	cout<<kk.id<<' '<<p[kk.id][i]<<'\n';
			if(d[mi][p[kk.id][i]]>d[mi][kk.id]){
				d[mi][p[kk.id][i]]=d[mi][kk.id]+1;
				q.push(node{p[kk.id][i],d[mi][p[kk.id][i]]});
			}
		}
	}
}
inline void dfs(int k,int dep){
	if(v[k]) return;
	if(dep==4){
		if(hv[k]) ans=max(ans,sum);
		return;
	}
	v[k]=1;
	for(int j=0;j<p2[k].size();j++){
		sum+=s[p2[k][j]];
		dfs(p2[k][j],dep+1);
		sum-=s[p2[k][j]];
	}
	v[k]=0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),k++;
	for(R int i=2;i<=n;i++) scanf("%lld",&s[i]);
	int zz,z2;
	for(R int i=1;i<=m;i++){
		scanf("%d%d",&zz,&z2);
		p[zz].push_back(z2);
		p[z2].push_back(zz);
		if(zz==1||z2==1){
			hv[max(zz,z2)]=1;
		}
	}
	for(int i=1;i<=n;i++) dj(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<p[i].size();j++){
			d[i][p[i][j]]=1;
			//cout<<"i:"<<i<<"   j:"<<p[i][j]<<"   "<<d[i][p[i][j]]<<'\n';
		}
	}
	for(R int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++){
			if(d[i][j]>k) continue; 
			p2[i].push_back(j);
			p2[j].push_back(i);
			//cout<<i<<' '<<j<<' '<<d[i][j]<<'\n';
		}
	}
	v&=v2;
	dfs(1,0);
	cout<<ans<<'\n';
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
