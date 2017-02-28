#include <iostream>
#include <stdio.h>
#include "variables.h"
#include "arh.h"
#include "codes.h"
#include "treex.h"

using namespace std;
//////julik2009   18169
int main(){
	TESTF=fopen("testfile.txt","w");
	init();
	char filename[256],outfilename[256];
	unsigned char wc;
	int i,j;
	printf("Input name of archive\n\n");scanf("%s",filename);
	printf("Input name of file\n\n");	scanf("%s",outfilename);
	in=fopen(filename,"r");
	out=fopen(outfilename,"w");
	
	if(in==NULL){cerr<<("Error opening file!\n");getchar();getchar();getchar();return 0;}

	fread(&KOL2,1,8,in);fprintf(TESTF,"\nKOL=%I64d\n",KOL2);
	fread(&K,1,2,in);fprintf(TESTF,"\nK=%d\n",K);
	beg=(8+2);
	fprintf(TESTF,"\ncodes:\n");
	for(i=0;i<K;i++){
		fread(&wc,1,1,in);	fprintf(TESTF,"d%d",wc);
		short int SIZE=0;
		fread(&SIZE,2,1,in);codes[wc].size=SIZE;fprintf(TESTF," %d ",SIZE);
		beg=beg+SIZE+3;
		for(j=0;j<SIZE;j++){
			unsigned char CODEJ;
			fread(&CODEJ,1,1,in);
			codes[wc].code[j]=CODEJ;
			fprintf(TESTF,"%d",CODEJ);
		}
			fprintf(TESTF,"\n");
	}
	fprintf(TESTF,"\nbeg=%d\narchive:\n",beg);
	fseek(in, 0, SEEK_END);
	KOL=ftell(in);
	KOL--;
	beg=beg+4;
	KOL=KOL-beg;
	fseek(in,beg,SEEK_SET);
	bufs=(int)(KOL/buf_size);
	rest_in_bytes=(long int)(KOL-bufs*buf_size);
	gen_bor();
	FromInToOut();
	FromInToOut2();
	fprintf(TESTF,"\nbufs=%d rest=%d KOL=%I64d",bufs,rest_in_bytes,KOL);
	fclose(in);
	fclose(out);
	fclose(TESTF);
	getchar();
	return 0;
}
