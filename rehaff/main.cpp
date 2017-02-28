#define uc unsigned char

#include <iostream>
#include <stdio.h>

#include "variables.h"
#include "arh.h"
#include "other.h"
#include "tree.h"

#define FOR256 for(i=0;i<256;i++)

using namespace std;
//////julik2009   18169

int main(){
	//var
//	TESTF=fopen("testfile.txt","wb");
	char filename[256],outfilename[256];
	uc wc;
	unsigned int in_kol;
	int i,j;
	init();
	//files	
	printf("Input name of archive\n\n");scanf("%s",filename);
	printf("Input name of file\n\n");scanf("%s",outfilename);

//	fprintf(TESTF,"in:\t%s\nout:\t%s\n",filename,outfilename);

	//in=fopen("1.ch"/*filename*/,"rb");out=fopen("1"/*outfilename*/,"wb");
	in=fopen(filename,"rb");out=fopen(outfilename,"wb");
	if(in==NULL){cerr<<("Error opening file!\n");return 0;}
	//meta
	fread(&KOL2,4,1,in);	
	fread(&K,2,1,in);		
	for(i=0;i<K;i++){
		j=getc(in);
		in_kol=0;
		fread(&in_kol,4,1,in);
		kol[j]=in_kol;
		alph[i].c=j;
		alph[i].w=in_kol;
		alph[i].i=i;	
	}
	if(K==1){
		for(i=0;i<KOL2;i++)
			putc(alph[0].c,out);
		fclose(in);
		fclose(out);
	//	fclose(TESTF);
		return 0;
	}
	//process
	gen();
	gen_bor();

/*	fprintf(TESTF,"\nd\tkol\tsize\tcode\n");
	FOR256 if(kol[i]){
		fprintf(TESTF,"\n%d\t%d\t%d\t",i,kol[i],codes[i].size);
		for(j=0;j<codes[i].size;j++)fprintf(TESTF,"%d",codes[i].code[j]);
	}
	fprintf(TESTF,"\n");
	fprintf(TESTF,"\nKOL==%d",KOL2);
	fprintf(TESTF,"\nK==%d\n",K);
	fprintf(TESTF,"\nbor:\n");
	FOR256 if(bor[i]!=-1)fprintf(TESTF,"%d %d\n",i,bor[i]);
*/
	FromInToOut();
	//close
	fclose(in);
	fclose(out);
	//fclose(TESTF);
	//getchar();
	return 0;
}
