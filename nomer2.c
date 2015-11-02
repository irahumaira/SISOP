#include<stdio.h>
#include<pthread.h>

void *prima(void *args) {
	int i,j;
	int n=*((int *) args);
	for(i=2;i<=n/2;i++) {
		printf("satu %d\n",i);
		for(j=2;j<=i/2;j++){
			if(i%j==0) printf("bukan prima\n");
			break;
		}
	}
}

void *prima2(void *args) {
       	int i,j;
	int n=*((int *)args);
        for(i=n/2+1;i<=n;i++) {
		printf("dua %d\n",i);
                for(j=2;j<=i/2;j++){
                        if(i%j==0) printf("bukan prima\n");
                        break;
                }
        }

}

void main() {
	int inp;
	pthread_t t1,t2;

	scanf("%d",&inp);

	pthread_create(&t1,NULL,&prima,&inp);
	pthread_create(&t2,NULL,&prima2,&inp);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
