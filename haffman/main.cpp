#include <iostream>
#include <stdio.h>

#include "variables.h"
#include "arh.h"
#include "codes.h"
#include "treex.h"

using namespace std;
//////julik2009   18169

int main(){
	int test=0;
	TESTF=fopen("testfile.txt","w");
	init();
	char filename[256],outfilename[256];unsigned char wc;
	int i,j;

	printf("Input name of file\n\n");	scanf("%s",filename);
	in=fopen(filename,"r");	strcpy(outfilename,filename);	strcat(outfilename,".ch");	out=fopen(outfilename,"w");
	if(in==NULL){cerr<<("Error opening file!\n");getchar();return 0;}
	
	while(!feof(in)){
		wc=fgetc(in);
		kol[wc]++;
	}
	kol[wc]--;
	
	KOL=ftell(in);
	fseek(in,0,SEEK_SET);bufs=KOL/buf_size;rest_in_bytes=(long int)(KOL-bufs*buf_size);
	gen();
	
	fwrite(&KOL,8,1,out);fprintf(TESTF,"\nKOL=%I64d\n",KOL);
	fwrite(&K,2,1,out);fprintf(TESTF,"\nK=%d\n",K);
	test=(8+2);
	fprintf(TESTF,"\ncodes:\n");
	for(i=0;i<256;i++)if(kol[i]){
		unsigned char TT=i;
		fwrite(&TT,1,1,out);fprintf(TESTF,"d%d",i);
		short int SIZE;
		SIZE=codes[i].size;	fwrite(&SIZE,2,1,out);	fprintf(TESTF," %d ",SIZE);
		j=0;
		test=test+SIZE+3;
		for(j=0;j<SIZE;j++){
			unsigned char CODEJ=codes[i].code[j];
			fwrite(&CODEJ,1,1,out);fprintf(TESTF,"%d",CODEJ);
		}
		fprintf(TESTF,"\n");
	}
	fprintf(TESTF,"\nbeg=%d\narchive:\n",test);
	for(i=0;i<bufs;i++){
		fread(buf_in,1,buf_size,in);
		FromInToOut();
	}

	for(i=0;i<rest_in_bytes;i++){
		wc=fgetc(in);
		buf_in[i]=wc;
	}
	FromInToOut2();

	fclose(in);
	fclose(out);
	fclose(TESTF);
	getchar();
	return 0;
}
