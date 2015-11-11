#include<stdio.h>
#include<signal.h>
#include<string.h>

typedef struct nama
{
	char nama1[30],nama2[30],nama3[30];
}	nfile;


void *thread1(void *args) {
	FILE *inp,*out;
	char cobi[100];
	nfile coba = *((nfile *)args);

	inp = fopen(coba.nama1,"r");
	out = fopen(coba.nama2,"rw");
	while(fgets(cobi,100,inp)){
            fprintf(out,"%s",cobi);
	}
}

void *thread2(void *args) {
	FILE *inp2,*out2;
        char cobi[100];
        nfile coba2 = *((nfile *)args);

        inp2 = fopen(coba2.nama2,"rw");
        out2 = fopen(coba2.nama3,"w");
        while(fgets(cobi,100,inp2)){
            fprintf(out2,"%s",cobi);
        }
}

void main() {
	nfile inm;
	FILE *file1;
	while(1) {
		printf("nama file1 : ");
		scanf("%s",inm.nama1);
		file1 = fopen(inm.nama1, "r");
		if(file1==NULL)
			printf("file tidak ditemukan !!\n");
		else {
			printf("nama file2 : ");
			scanf("%s",inm.nama2);
			printf("nama file3 : ");
                        scanf("%s",inm.nama3);
			break;
		}
	}

	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread1,&inm);
//	pthread_join(t1,NULL);

	pthread_create(&t2,NULL,thread2,&inm);
//	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
