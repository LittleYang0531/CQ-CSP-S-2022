#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v,kkk,fir[1001][1001],kkk1[1001][1001],bj[1001],ssum;
struct dnm{
	int id,ojbk;
};
vector<dnm>van[1001];
bool check(){
	for(int i=1;i<=n;i++){
		ssum=0;
		for(int j=0;j<van[i].size();j++){
		if(van[i][j].ojbk){
		ssum++;
//		cout<<i<<" "<<van[i][j].id<<endl;
	}
}
//    cout<<ssum<<" ";
    if(ssum!=1)return 0;
}
/*
	for(int i=1;i<=n;i++)bj[i]=0;
	for(int i=1;i<=n;i++){
	if(bj[van[i][0].id]==1)return 0;
	else bj[van[i][0].id]==1;
	}*/
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    kkk1[i][j]=-1;
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&u,&v);
    	van[u].push_back({v,1});
    	fir[u][v]=1;
    	kkk1[u][v]=van[u].size()-1;
//    	cout<<kkk1[u][v]<<endl;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
	    scanf("%d",&kkk);
	    if(kkk==1){
	    scanf("%d%d",&u,&v);
//	    cout<<"van "<<u<<" "<<v<<" "<<van[u][kkk1[u][v]].id<<" "<<kkk1[u][v]<<endl;
	    van[u][kkk1[u][v]].ojbk=0;
		}
		if(kkk==2){
	    scanf("%d",&u);
	    for(int i=1;i<=n;i++)
	    if(kkk1[i][u]>=0)
	    van[i][kkk1[i][u]].ojbk=0;
		}
		if(kkk==3){
	     scanf("%d%d",&u,&v);
	    van[u][kkk1[u][v]].ojbk=1;
		}
		if(kkk==4){
	     scanf("%d",&u);
	    for(int i=1;i<=n;i++)
	    if(kkk1[i][u]>=0&&fir[i][u])
	    van[i][kkk1[i][u]].ojbk=1;
		}
		if(check())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
