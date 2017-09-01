#include<bits/stdc++.h>

int main(){
	int num,mult,rn,q,r;
	while(scanf("%d",&num) != EOF){
		if(num==1){
			printf("0 0\n");
			continue;
		}
		num--;
		mult=6;
		rn=1;
		while(num>mult){
			num=num-mult;
			mult=mult+6;
			rn++;
		}
		r=num%rn;
		q=num/rn;
		switch(q){
			case 0:
			    printf("%d %d\n",rn-r, r);
				break;
			case 1:
			    printf("%d %d\n",-r, rn);
				break;
			case 2:
			    printf("%d %d\n",-rn, rn-r);
				break;
			case 3:
			    printf("%d %d\n",-rn+r, -r);
				break;
			case 4:
			    printf("%d %d\n",r, -rn);
				break;
			case 5:
			    printf("%d %d\n",rn, -rn+r);
				break;
			case 6:
			    printf("%d %d\n",rn-r, r);
				break;
		}
	}
    return 0;
}
