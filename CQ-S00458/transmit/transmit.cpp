#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,q,k;
vector<int> a[100];

int lj(int x,int y,int t,int v[],bool p[])
{
	int i;bool w[n+1];
	for(i=1;i<=n;i++){
		w[i]=p[i];
	}
	if(x==y) return 0;
	if(t==k){
		w[x]=1;
		return lj(x,y,0,v,w)+v[x];
	}
	int r,ans=10e8;
	for(i=0;i<a[x].size();i++){
		if(p[a[x][i]]) continue;
		
		w[a[x][i]]=1;
		r=lj(a[x][i],y,t+1,v,p);
		
		
		ans=min(min(v[x]+lj(a[x][i],y,0,v,w),r),ans);
		w[a[x][i]]=0;
	}
	return ans;
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	int v[n+1],i,x,y;
	bool p[n+1]={0};
	for(i=1;i<=n;i++){
		cin>>v[i];
	}
	for(i=1;i<n;i++){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(i=0;i<q;i++){
		cin>>x>>y;
		p[x]=1;
		cout<<lj(x,y,0,v,p)<<endl;
	}
	
	
	return 0;
}
