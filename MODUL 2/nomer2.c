#include<stdio.h>
#include<pthread.h>

void *prima(void *args) {
	int i,j,n=*((int *) args),count=(n-1)/2;
	for(i=3;i<=n;i+=2)
		for(j=2;j<=i/2;j++) {
			if(i%j==0){
		                count--;
        	                break;
        	        }
		}
	printf("%d\n",count+1);
}

void main() {
	int inp,i;
	pthread_t tid;
	scanf("%d",&inp);

	pthread_create(&tid,NULL,&prima,&inp);
	pthread_join(tid,NULL);
}
