#include<bits/stdc++.h>
using namespace std;
int n,m,k,l1,l2,r1,r2;
long long a[100005][2],ans;
struct node{int l,r;long long s1,s2,s3,s4;bool fl1,fl2,fl3;}t[400005][2];
void build(int p,int x,int y,int id){
	t[p][id].l=x,t[p][id].r=y;
	if(x==y){
		t[p][id].s1=(a[x][id]>0?a[x][id]:-1e9);
		t[p][id].s2=(a[x][id]>0?a[x][id]:1e9);
		t[p][id].s3=(a[x][id]<0?a[x][id]:-1e9);
		t[p][id].s4=(a[x][id]<0?a[x][id]:1e9);
		t[p][id].fl1=(a[x][id]>0);
		t[p][id].fl2=(a[x][id]==0);
		t[p][id].fl3=(a[x][id]<0);
	}
	else{
		build(p*2,x,(x+y)/2,id),build(p*2+1,(x+y)/2+1,y,id);
		t[p][id].s1=max(t[p*2][id].s1,t[p*2+1][id].s1);
		t[p][id].s2=min(t[p*2][id].s2,t[p*2+1][id].s2);
		t[p][id].s3=max(t[p*2][id].s3,t[p*2+1][id].s3);
		t[p][id].s4=min(t[p*2][id].s4,t[p*2+1][id].s4);
		t[p][id].fl1=(t[p*2][id].fl1||t[p*2+1][id].fl1);
		t[p][id].fl2=(t[p*2][id].fl2||t[p*2+1][id].fl2);
		t[p][id].fl3=(t[p*2][id].fl3||t[p*2+1][id].fl3);
	}
}
long long query1(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].s1;
	long long sum=-1e9;
	if(x<=(t[p][id].l+t[p][id].r)/2)sum=max(sum,query1(p*2,x,y,id));
	if(y>=(t[p][id].l+t[p][id].r)/2+1)sum=max(sum,query1(p*2+1,x,y,id));
	return sum;
}
long long query2(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].s2;
	long long sum=1e9;
	if(x<=(t[p][id].l+t[p][id].r)/2)sum=min(sum,query2(p*2,x,y,id));
	if(y>=(t[p][id].l+t[p][id].r)/2+1)sum=min(sum,query2(p*2+1,x,y,id));
	return sum;
}
long long query3(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].s3;
	long long sum=-1e9;
	if(x<=(t[p][id].l+t[p][id].r)/2)sum=max(sum,query3(p*2,x,y,id));
	if(y>=(t[p][id].l+t[p][id].r)/2+1)sum=max(sum,query3(p*2+1,x,y,id));
	return sum;
}
long long query4(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].s4;
	long long sum=1e9;
	if(x<=(t[p][id].l+t[p][id].r)/2)sum=min(sum,query4(p*2,x,y,id));
	if(y>=(t[p][id].l+t[p][id].r)/2+1)sum=min(sum,query4(p*2+1,x,y,id));
	return sum;
}
bool find1(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].fl1;
	if(x<=(t[p][id].l+t[p][id].r)/2&&find1(p*2,x,y,id))return 1;
	if(y>=(t[p][id].l+t[p][id].r)/2+1&&find1(p*2+1,x,y,id))return 1;
	return 0;
}
bool find2(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].fl2;
	if(x<=(t[p][id].l+t[p][id].r)/2&&find2(p*2,x,y,id))return 1;
	if(y>=(t[p][id].l+t[p][id].r)/2+1&&find2(p*2+1,x,y,id))return 1;
	return 0;
}
bool find3(int p,int x,int y,int id){
	if(x<=t[p][id].l&&t[p][id].r<=y)return t[p][id].fl3;
	if(x<=(t[p][id].l+t[p][id].r)/2&&find3(p*2,x,y,id))return 1;
	if(y>=(t[p][id].l+t[p][id].r)/2+1&&find3(p*2+1,x,y,id))return 1;
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i][0]);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i][1]);
	build(1,1,n,0),build(1,1,m,1);
	while(k--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(find2(1,l1,r1,0)&&find2(1,l2,r2,1))ans=0;
		else if(!find1(1,l1,r1,0)&&find2(1,l1,r1,0)&&!find3(1,l1,r1,0))ans=0;
		else if(!find1(1,l2,r2,1)&&find2(1,l2,r2,1)&&!find3(1,l2,r2,1))ans=0;
		else if(find2(1,l1,r1,0)&&find1(1,l2,r2,1)&&find3(1,l2,r2,1))ans=0;
		else if(find1(1,l1,r1,0)&&find2(1,l1,r1,0)&&!find3(1,l1,r1,0)&&!find1(1,l2,r2,1)&&!find2(1,l2,r2,1)&&find3(1,l2,r2,1))ans=0;
		else if(find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&!find1(1,l2,r2,1)&&find2(1,l2,r2,1)&&find3(1,l2,r2,1))ans=0;
		else if(find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&find1(1,l2,r2,1)&&find2(1,l2,r2,1)&&!find3(1,l2,r2,1))ans=0;
		else if(find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&!find3(1,l1,r1,0)&&find1(1,l2,r2,1)&&find2(1,l2,r2,1)&&!find3(1,l2,r2,1))ans=0;
		else if(!find1(1,l1,r1,0)&&find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&find1(1,l2,r2,1)&&!find2(1,l2,r2,1)&&!find3(1,l2,r2,1))ans=0;
		else if(!find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&!find1(1,l2,r2,1)&&find2(1,l2,r2,1)&&find3(1,l2,r2,1))ans=0;
		else if(find1(1,l1,r1,0)&&find1(1,l2,r2,1)&&!find2(1,l2,r2,1)&&!find3(1,l2,r2,1))ans=query1(1,l1,r1,0)*query2(1,l2,r2,1);
		else if(find3(1,l1,r1,0)&&!find1(1,l2,r2,1)&&!find2(1,l2,r2,1)&&find3(1,l2,r2,1))ans=query4(1,l1,r1,0)*query3(1,l2,r2,1);
		else if(find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&!find3(1,l1,r1,0)&&find3(1,l2,r2,1))ans=query2(1,l1,r1,0)*query4(1,l2,r2,1);
		else if(!find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&find1(1,l2,r2,1))ans=query3(1,l1,r1,0)*query1(1,l2,r2,1);
		else if(find1(1,l1,r1,0)&&!find2(1,l1,r1,0)&&find3(1,l1,r1,0)&&find1(1,l2,r2,1)&&find3(1,l2,r2,1))ans=max(query2(1,l1,r1,0)*query4(1,l2,r2,1),query3(1,l1,r1,0)*query1(1,l2,r2,1));
		printf("%lld\n",ans);
	}
	return 0;
}
