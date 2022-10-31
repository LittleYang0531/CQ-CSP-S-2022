#include<bits/stdc++.h>
using namespace std;
int n,q,k;
int ls[100005],fs[100005],v[100005];
long long ans,g;
void add(int x,int y){
	ls[x]=fs[y];fs[x]=y;ls[y]=ls[fs[x]];
	ls[y]=fs[x];fs[y]=x;ls[x]=ls[fs[y]];
}
void z(int a,int b,int x){
	if(g>k) ans-=v[x];return;
	if(x!=b){
		g++;
		ans+=v[x];
		z(a,b,fs[x]);
	}else{
		return;
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		ans=v[a]+v[b];
		g=1;
		z(a,b,ls[a]);
		cout<<ans<<endl;
	}
	return 0;
}
