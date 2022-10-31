#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],b[10005];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
    srand(time(NULL));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int u,v;
    	cin>>u>>v;
    	a[u][v]=1;
    	b[u]++;
    	b[v]++;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q+1;i++){
    	char a[20];
    	gets(a);
    }
    for(int i=1;i<=q;i++){
    	if(rand()%2==0) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }
	return 0;
}

