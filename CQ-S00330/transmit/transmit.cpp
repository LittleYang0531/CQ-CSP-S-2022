#include <bits/stdc++.h>
using namespace std;
int n,q,k,v[200001],a[5001][5001],b[200001],minn;
void work(int num,int sum,int mu){
	if(num==mu){
		if(minn==-1) minn=sum;
		else minn=min(sum,minn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[num][i]==1&&b[i]==0){
			b[i]=1;
			work(i,sum+v[i],mu);
			b[i]=0;
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		minn=-1;
		b[s]=1;
		work(s,v[s],t);
		b[s]=0;
		cout<<minn<<endl;
	}
}
