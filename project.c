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
void merger(){
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(f[ifc].at == s[isc].at){
				m[mc] = f[ifc];
				mc++;
				ifc++;
				m[mc]= s[isc];
				mc++;
				isc++;
			}
			else if(f[ifc].at < s[isc].at){
				m[mc]= f[ifc];
				mc++;
				ifc++;
}
			else if(f[ifc].at > s[isc].at){
				m[mc]= s[isc];
				mc++;
				isc++;
			}
			else;
		}
		if(mc != (fc+sc)){
			if(fc!=ifc){
				while(ifc!=fc){
					m[mc]= f[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc){
				while(isc!=sc){
					m[mc]= s[isc];
					mc++;
					isc++;
				}
			}
		}
	}
else if(fc==0){
		while(isc!=sc){
			m[mc]= s[isc];
			mc++;
			isc++;
		}
	}
	else if(sc==0){
		while(ifc!=fc){
			m[mc]= f[ifc];
			mc++;
			ifc++;
		}
	}
	else {
		printf("\n No valid Jobs available\n");
	}
}
