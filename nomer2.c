#include<stdio.h>
#include<unistd.h>

int prima(int angka) {
        int i;
        for(i=2;i<=angka/2;i++) {
                if(angka%i==0) return 0;

        }
        return 1;
}

int main() {
        int inp,i;
        while(scanf("%d",&inp) && inp!=EOF) {
		int count=0;
		for(i=2;i<=inp;i++)
  	              if(prima(i)==1) count++;
		printf("%d\n",count);
        }
        return 0;
}

