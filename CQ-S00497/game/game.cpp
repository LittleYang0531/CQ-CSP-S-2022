#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1001],b[1001];
struct s{
	int l,r,pre;
}t[4001][1001];
void make_tree(int p,int l,int r,int k){
	t[p][k].l=l;
	t[p][k].r=r;
	if(l<r){
		int mid=(l+r)>>1;
		make_tree(2*p,l,mid,k);
		make_tree(2*p+1,mid+1,r,k);
		t[p][k].pre=min(t[2*p][k].pre,t[2*p+1][k].pre);
	}
	else
		t[p][k].pre=a[k]*b[l];
}
int ask(int p,int l,int r,int k){
	if(l<=t[p][k].l && t[p][k].r<=r)
		return t[p][k].pre;
	int mid=(t[p][k].l+t[p][k].r)>>1,min_=1e9;
	if(l<=mid)
		min_=min(min_,ask(2*p,l,r,k));
	if(mid<r)
		min_=min(min_,ask(2*p+1,l,r,k));
	return min_;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	if(n<=1000 && m<=1000){
		for(int i=1;i<=n;i++)
			make_tree(1,1,n,i);
		for(int i=0;i<p;i++){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			int max_=-1e9;
			for(int i=l1;i<=r1;i++)
				max_=max(max_,ask(1,l2,r2,i));
			printf("%d\n",max_);
		}
	} else {
		for(int i=0;i<p;i++){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			if(l1==r1){
				int max_=-1e9;
				for(int i=l2;i<=r2;i++)
					max_=max(max_,a[l1]*b[i]);
				printf("%d\n",max_);
			} else if(l2==r2){
				int max_=-1e9;
				for(int i=l1;i<=r1;i++)
					max_=max(max_,a[i]*b[l2]);
				printf("%d\n",max_);
			} else {
				int max_=-1e9;
				for(int i=l1;i<=r1;i++){
					int min_=1e9;
					for(int j=l2;j<=r2;j++)
						min_=min(min_,a[i]*b[j]);
					max_=max(max_,min_);
				}
				printf("%d\n",max_);
			}
		}
	}
	return 0;
}/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
