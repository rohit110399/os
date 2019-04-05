#include<stdio.h>

struct job{
	int pid;
	int at;
	int bt;
	int cmpt;
	int rbt;
}f[100], s[100], m[100];

int n, fc=0, sc=0, mc=0;
int quanta;

void roundRobin(){
	int time= m[0].at, mark=0, cc=0, i, rc;
	while(time!=120 && cc!=mc){
		for(i=0; i<=mark; i++){
			if(m[i].rbt > quanta){
				time += quanta;
				m[i].rbt -= quanta;
			}
			else if(m[i].rbt <=quanta && m[i].rbt !=0){
				time += m[i].rbt;
				m[i].rbt =0;
				m[i].cmpt = time;
				cc++;
			}
			else;
		}
		int start = mark+1;
		for(rc= start; rc<mc; rc++){
			if(m[rc].at <= time){
				mark++;
			}
		}
	}	
}
