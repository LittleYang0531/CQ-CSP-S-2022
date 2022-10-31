#include<bits/stdc++.h>
using namespace std;
int n,m,q,aa,bb,a[200005],b[200005],treea1[500005],treea2[500005],treeb1[500005],treeb2[500005],tree0[500005],l1,l2,r1,r2;
long long answer;
void build(int number,int l,int r) {
	if(l==r) {
		treea1[number]=a[l];
		return;
	}
	build(number<<1,l,l+r>>1);
	build(number<<1|1,(l+r>>1)+1,r);
	treea1[number]=min(treea1[number<<1],treea1[number<<1|1]);
	return;
}
void build1(int number,int l,int r) {
	if(l==r) {
		treea2[number]=a[l];
		//cout<<a[l]<<"";
		return;
	}
	build1(number<<1,l,l+r>>1);
	build1(number<<1|1,(l+r>>1)+1,r);
	treea2[number]=max(treea2[number<<1],treea2[number<<1|1]);
	return;
}
void build2(int number,int l,int r) {
	if(l==r) {
		treeb1[number]=b[l];
		return;
	}
	build2(number<<1,l,l+r>>1);
	build2(number<<1|1,(l+r>>1)+1,r);
	treeb1[number]=min(treeb1[number<<1],treeb1[number<<1|1]);
	return;
}
void build3(int number,int l,int r) {
	if(l==r) {
		treeb2[number]=b[l];
		return;
	}
	build3(number<<1,l,l+r>>1);
	build3(number<<1|1,(l+r>>1)+1,r);
	treeb2[number]=max(treeb2[number<<1],treeb2[number<<1|1]);
	return;
}
void build4(int number,int l,int r) {
	if(l==r) {
		if(a[l]==0) tree0[number]++;
		return;
	}
	build4(number<<1,l,l+r>>1);
	build4(number<<1|1,(l+r>>1)+1,r);
	if(tree0[number<<1]+tree0[number<<1|1]) tree0[number]=1;
	return;
}
int find1(int number,int le,int ri,int ll,int rr) { //寻找 a 的最大值
	//cout<<number<<" "<<treea2[number]<<" "<<le<<" "<<ri<<endl;
	if(le>rr||ri<ll) return -0x8f;
	if(ll<=le&&ri<=rr)return treea2[number];
	return max(find1(number<<1,le,le+ri>>1,ll,rr),find1(number<<1|1,(le+ri>>1)+1,ri,ll,rr));
}
int find2(int number,int le,int ri,int ll,int rr) { //寻找 b 的最小值
	if(le>rr||ri<ll) return 1e9;
	if(ll<=le&&ri<=rr) return treeb1[number];
	return min(find2(number<<1,le,le+ri>>1,ll,rr),find2(number<<1|1,(le+ri>>1)+1,ri,ll,rr));
}
int find3(int number,int le,int ri,int ll,int rr) { //寻找 a 的最小值
	if(le>rr||ri<ll) return 1e9;
	if(ll<=le&&ri<=rr) return treea1[number];
	return min(find3(number<<1,le,le+ri>>1,ll,rr),find3(number<<1|1,(le+ri>>1)+1,ri,ll,rr));
}
int find4(int number,int le,int ri,int ll,int rr) { //寻找 b 的最大值
//	cout<<number<<" "<<treeb2[number]<<" "<<le<<" "<<ri<<":"<<endl;
	if(le>rr||ri<ll) return -1e9;
	if(ll<=le&&ri<=rr) return treeb2[number];
	return max(find4(number<<1,le,le+ri>>1,ll,rr),find4(number<<1|1,(le+ri>>1)+1,ri,ll,rr));
}
int find5(int number,int le,int ri,int ll,int rr) { //寻找 1
	if(le>rr||ri<ll) return 0;
	if(ll<=le&&ri<=rr) return tree0[number];
	return max(find5(number<<1,le,le+ri>>1,ll,rr),find5(number<<1|1,(le+ri>>1)+1,ri,ll,rr));
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>0) aa++;
	}
	for(int j=1; j<=m; j++) {
		cin>>b[j];
		if(b[j]>0) bb++;
	}
	build(1,1,n);
	build1(1,1,n);
	build2(1,1,m);
	build3(1,1,m);
	build4(1,1,n);
	if(aa==n&&bb==m) { //性质一的题目
		for(int i=1; i<=q; i++) {
			cin>>l1>>r1>>l2>>r2;
			answer=find1(1,1,n,l1,r1)*find2(1,1,m,l2,r2);
			cout<<answer;
		}
		return 0;
	} else {
		long long maxna=0,maxnb=0,mixna=0,mixnb=0;
		for(int i=1; i<=q; i++) {
			cin>>l1>>r1>>l2>>r2;
			maxna=find1(1,1,n,l1,r1),mixnb=find2(1,1,m,l2,r2),mixna=find3(1,1,n,l1,r1),maxnb=find4(1,1,m,l2,r2);
			//	cout<<maxna<<" "<<mixna<<" "<<maxnb<<" "<<mixnb<<endl;
			if(mixnb<0) {
				long long ans=-1e9;
				if(mixna>0&&!find5(1,1,n,l1,r1)) ans=max(ans,mixnb*mixna);
				if(mixna>0&&find5(1,1,n,l1,r1)) ans=max(ans,0ll);
				if(mixna<0&&find5(1,1,n,l1,r1)) ans=max(ans,0ll);
				if(mixna<0&&maxnb<0) ans=max(ans,mixna*maxnb);
				if(mixna<0&&mixnb<0) {
					int mmmm=1e9;
					for(int j=l1; j<=r1; j++) if(a[j]-0<mmmm&&a[j]>0) mmmm=a[j];
					ans=max(ans,mmmm*mixnb);
				}
				if(mixna<0&&maxnb>0) {
					int mmmm=-1e9;
					for(int j=l2; j<=r2; j++) if(a[j]<0&&a[j]>mmmm) mmmm=a[j];
					ans=max(ans,max(mmmm*maxnb,maxnb*mixna));
				}
				cout<<ans<<endl;
			} else if(mixnb>0) {
				cout<<mixnb*maxna<<endl;
			}
		}
	}
	return 0;
}

