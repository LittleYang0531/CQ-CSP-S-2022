#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100010],b[100010];
//int lg[100010];
//const int inf=1000000001;
//typedef long long ll;
//struct stable{
//	int maz[100010][25],maf[100010][25],miz[100010][25],mif[100010][25];
//	void prework(int num[],int len){
//		for(int i=1;i<=len;i++){
//			maz[i][0]=-inf;maf[i][0]=-inf;
//			miz[i][0]=inf;mif[i][0]=inf;
//			if(num[i]>=0)maz[i][0]=miz[i][0]=num[i];
//			if(num[i]<=0)maf[i][0]=mif[i][0]=num[i];
//		}
//		for(int i=1;i<=lg[len];i++)
//		for(int j=1;j+(1<<i)-1<=len;j++){
//			maz[j][i]=max(maz[j][i-1],maz[j+(1<<(i-1))][i-1]);
//			maf[j][i]=max(maf[j][i-1],maf[j+(1<<(i-1))][i-1]);
//			miz[j][i]=min(miz[j][i-1],miz[j+(1<<(i-1))][i-1]);
//			mif[j][i]=min(mif[j][i-1],mif[j+(1<<(i-1))][i-1]);
//		}
//	}
//	int ask(int l,int r,int op){
//		int lgl=lg[r-l+1];
//		if(op==1)return max(maz[l][lgl],maz[r-(1<<lgl)+1][lgl]);
//		if(op==2)return max(maf[l][lgl],maf[r-(1<<lgl)+1][lgl]);
//		if(op==3)return min(miz[l][lgl],miz[r-(1<<lgl)+1][lgl]);
//		if(op==4)return min(mif[l][lgl],mif[r-(1<<lgl)+1][lgl]);
//	}
//	int minn(int l,int r){return min(ask(l,r,3),ask(l,r,4));}
//	int maxx(int l,int r){return max(ask(l,r,1),ask(l,r,2));}
//	bool havef(int l,int r){return ask(l,r,4)!=inf;}
//	bool havez(int l,int r){return ask(l,r,1)!=-inf;}
//}ast,bst;
//int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
//	for(int i=2;i<=100000;i++)lg[i]=lg[i/2]+1;
//	scanf("%d%d%d",&n,&m,&q);
//	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
//	ast.prework(a,n);
//	bst.prework(b,n);
//	for(int i=1;i<=q;i++){
//		int l1,r1,l2,r2;
//		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
//		int mina=ast.minn(l1,r1),maxa=ast.maxx(l1,r1),maxb=bst.maxx(l2,r2),minb=bst.minn(l2,r2);
//		int a1=ast.ask(l1,r1,(minb>0?1:3)),
//		a2=ast.ask(l1,r1,(maxb>0?2:4)),
//		b1=bst.ask(l2,r2,(maxa>0?3:1)),
//		b2=bst.ask(l2,r2,(mina>0?4:2));
//		int achs,bchs;
//		if(a1==inf||a1==-inf)achs=a2;
//		else if(a2==inf||a2==-inf)achs=a1;
//		else achs=a1*1ll*minb>a2*1ll*maxb?a1:a2;
//		if(b1==inf||b1==-inf)bchs=b2;
//		else if(b2==inf||b2==-inf)bchs=b1;
//		else bchs=b1*1ll*maxa<b2*1ll*mina?b1:b2;
//		printf("%lld\n",achs*1ll*bchs);
//	}
//	return 0;
//}
int lg[100010];
const int inf=1000000001;
typedef long long ll;
struct stable{
	int ma[100010][25],mi[100010][25];
	void prework(int num[],int len){
		for(int i=1;i<=len;i++)ma[i][0]=mi[i][0]=num[i];
		for(int i=1;i<=lg[len];i++)
		for(int j=1;j+(1<<i)-1<=len;j++){
			ma[j][i]=max(ma[j][i-1],ma[j+(1<<(i-1))][i-1]);
			mi[j][i]=min(mi[j][i-1],mi[j+(1<<(i-1))][i-1]);
		}
	}
	int maxx(int l,int r){
		int lgl=lg[r-l+1];
		return max(ma[l][lgl],ma[r-(1<<lgl)+1][lgl]);
	}
	int minn(int l,int r){
		int lgl=lg[r-l+1];
		return min(mi[l][lgl],mi[r-(1<<lgl)+1][lgl]);
	}
}ast,bst;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=2;i<=100000;i++)lg[i]=lg[i/2]+1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	ast.prework(a,n);
	bst.prework(b,m);
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1)printf("%lld\n",a[l1]*1ll*bst.minn(l2,r2));
		else if(l2==r2)printf("%lld\n",ast.maxx(l1,r1)*1ll*b[l2]);
		else printf("%lld\n",ast.maxx(l1,r1)*1ll*bst.minn(l2,r2));
	}
	return 0;
}
