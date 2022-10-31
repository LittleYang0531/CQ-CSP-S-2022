#include<bits/stdc++.h>
#define int long long
using namespace std;//zaayyds!
int n,m,q;
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	srand(time(0));
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
	}
	cin>>q;
	for(int i=1;i<=n;i++){
		int c,l,r=1;
		cin>>c;
		if(c==1||c==3){
			cin>>l>>r;
		}else 
			cin>>l;
		if((c*l*r)%2==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
/*
NO
NO
YES
NO
YES
NO
NO
NO
YES
NO
NO
*/
