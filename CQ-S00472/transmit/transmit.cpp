#include<bits/stdc++.h>
using namespace std;
int t[200005],a[10000][10000];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
    int n,q,k,mi=INT_MAX;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++){
    	cin>>t[i];
		mi=min(mi,t[i]);
	}
    for(int i=1;i<=n-1;i++){
    	int x,y;
    	cin>>x>>y;
		a[x][y]=1;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
			if(a[x][y]==0)cout<<t[x]+t[y]+mi<<endl;
		else cout<<t[x]+t[y]<<endl;
	}
	return 0;
}
