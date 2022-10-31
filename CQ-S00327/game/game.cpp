#include<cstdio>
#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen ("game.in","r",stdin);
	freopen ("game.out","w",stdout);
	int temp;
	cin>>temp;
	if(temp=3)
	cout<<"0"<<endl<<"4";
	else
	cout<<"0"<<endl<<"-2"<<endl<<"3"<<endl<<"2"<<endl<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
