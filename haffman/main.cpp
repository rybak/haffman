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
	//TESTF=fopen("testfile.txt","wb");
	char filename[256],outfilename[256];
	unsigned char wc;
	unsigned int out_kol;
	int i;
	init();
	//files
	printf("Input name of file\n\n");scanf("%s",filename);
	strcpy(outfilename,filename);strcat(outfilename,".ch");
//	fprintf(TESTF,"in:\t%s\nout:\t%s\n",filename,outfilename);
	//in=fopen("1"/*filename*/,"rb");
	//out=fopen("1.ch"/*outfilename*/,"wb");
	in=fopen(filename,"rb");
	out=fopen(outfilename,"wb");
	if(in==NULL){cerr<<("Error opening file!\n");getchar();return 0;}
	//kol
	KOL=0;
	do{
		wc=getc(in);
		kol[wc]++;
		KOL++;
	}while(!feof(in));
	kol[wc]--;
	KOL--;
	//generation
	gen();

	/*fprintf(TESTF,"\nd\tkol\tsize\tcode\n");
	FOR256 if(kol[i]){
		fprintf(TESTF,"\n%d\t%d\t%d\t",i,kol[i],codes[i].size);
		for(j=0;j<codes[i].size;j++)fprintf(TESTF,"%d",codes[i].code[j]);
	}
	*/
	//meta info
	//fprintf(TESTF,"\n");
	fwrite(&KOL,4,1,out);		//fprintf(TESTF,"\nKOL==%d",KOL);
	fwrite(&K,2,1,out);			//fprintf(TESTF,"\nK==%d\n",K);
	FOR256
		if(codes[i].size!=0){
			wc=(unsigned char)(i);
			putc(wc,out);
			out_kol=kol[i];
			fwrite(&out_kol,4,1,out);
		}
	//process
	fseek(in,0,SEEK_SET);
	FromInToOut();
	//close
	fclose(in);
	fclose(out);
//	fclose(TESTF);
	//getchar();
	return 0;
}
