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
	char filename[256],outfilename[256],wc;
	int i,j;
	printf("Input name of archive\n\n");	scanf("%s",filename);
	printf("Input name of file\n\n");	scanf("%s",outfilename);
	in=fopen(filename,"r");
	out=fopen(outfilename,"w");
		

	if(in==NULL){cerr<<("Error opening file!\n");getchar();return 0;}

//	while(!feof(in)){wc=fgetc(in);kol[wc]++;KOL++;}	KOL--;kol[wc]--;
//	fseek(in,0,SEEK_SET);bufs=KOL/buf_size;rest_in_bytes=(long int)(KOL-bufs*buf_size);
//	gen();//gen codes for chars
/*
	fprintf(TESTF,"\nchar counter: %I64d\n",KOL);
	fprintf(TESTF,"\ncodes:\n");
	for(i=0;i<256;i++)if(codes[i].size){
		fprintf(TESTF,"%c",i);
		for(j=0;j<codes[i].size;j++)
			fprintf(TESTF,"%d",codes[i].code[j]);
	fprintf(TESTF,"\n");
	}
	fprintf(TESTF,"\narchive:\n");
	///
	*/
	fread(&K,1,2,in);beg=2;
	for(i=0;i<K;i++){
		fread(&wc,1,1,in);
beg++;
		fread(&(codes[wc].size),2,1,in);
beg+=2;
		for(j=0;j<codes[wc].size;j++){
			fread(&(codes[wc].code[j]),1,1,in);
beg++;
		}
	}
	

	fseek(in, 0, SEEK_END);
	KOL=ftell(in)-beg;
	fseek(in,beg,SEEK_SET);
	
	bufs=KOL/buf_size;
	rest_in_bytes=(int)(KOL-bufs*buf_size);

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
