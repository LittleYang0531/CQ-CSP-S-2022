/*CSP-S RP++!*/
#include<bits/stdc++.h>
using namespace std;
struct file
{
	string bytes;
};
struct problem
{
	string name,description;
	file in[25],out[25];
};
struct judger
{
	file exe;
	string comp(string word)
	{
		return "NO";
	}
}gcc;
struct program
{
	string bytes;
	string run(judger gcc,string in)
	{
		return gcc.comp(bytes);
	}
};
struct person
{
	string name,number,place,school;
	program programs[4];
	int age,score;
	preson(string _name,string _number,string _place,string _school,int _age,int _score)
	{
		name=_name;
		number=_number;
		place=_place;
		school=_school;
		age=_age;
	}
};
struct competition
{
	string rules;
	problem pro[4];
	int time_start,time_finish;
};
struct CCF
{
	competition cspj,csps;
	void judge(person somebody)
	{
		for(int i=0;i<=3;i++)
			for(int j=0;j<25;j++)
				if(somebody.programs[i].run(gcc,cspj.pro[i].in[j].bytes)==cspj.pro[i].out[j].bytes)
					somebody.score++;
		//......
	}
	void excute(person somebody)
	{
		judge(somebody);
	}
}ccf;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	person me;
	me.name="secret";
	me.number="CQ-00000";
	me.place="CQ";
	me.school="secret";
	me.age=14;
	me.score=0;
	ccf.excute(me);
	return 0;
}
//希望下次普及组能降低难度（我也不奢求提高组能降低） 
//--来自同时参加了CSP-J和CSP-S的蒟蒻
/*CSP-S RP-=RP x_x*/

/*myh loves ljx forever!*/
