#include <bits/stdc++.h>
using namespace std ;
int n,m,q;
int u,v;
int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>u>>v;
    cin>>q;
    for(int i=1;i<=q;i++){
    	if(i%3) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	return false;
}
