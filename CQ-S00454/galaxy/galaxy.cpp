#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,a[1000001],b[1000001],s,h,q,c[1000001],d[1000001],v,u,f;
queue <long long> qu[1000001],qk[1000001];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>k>>l;
		a[k]++;
		c[l]++;
		qu[l].push(k);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		d[i]=c[i];
		s+=c[i];
	}
	cin>>q;
	for(int j=1;j<=q;j++){
		v=0;
		cin>>h>>k;
		if(h==1){
			cin>>l;
			b[k]--;
			d[l]--;
			qk[l].push(k);
			while(v!=k){
				qu[l].push(v);
				v=qu[l].front();
				qu[l].pop();
			}
			s--;
		}
		if(h==2){
			s-=d[k];
			d[k]=0;
			u=qu[k].back();
			while(!qu[k].empty()){
				b[qu[k].front()]--;
				v=qu[k].front();
				qk[k].push(v);
				qu[k].pop();
			}
		}
		if(h==3){
			cin>>l;
			b[k]++;
			d[l]++;	
			qu[l].push(k);
			while(v!=k){
				qk[l].push(v);
				v=qk[l].front();
				qk[l].pop();
			}
			s++;
		}
		if(h==4){
			s+=(c[k]-d[k]);
			d[k]=c[k];
			
			u=qk[k].back();
			while(!qk[k].empty()){
				b[qk[k].front()]++;
				v=qk[k].front();
				qu[k].push(v);
				qk[k].pop();
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=1){
				cout<<"NO"<<endl;
				f=1;
				break;
			}
		}
        if(f==0)cout<<"YES"<<endl;
        else f=0;
	}
}
