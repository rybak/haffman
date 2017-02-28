#define uc unsigned char

#include <iostream>
#include <stdio.h>
#include <cmath>

#include "variables.h"
#include "bufiz.h"
#include "arh.h"
#include "tree.h"
#include "other.h"

#define FOR256 for(i=0;i<256;i++)

using namespace std;

int main(int argc, char *argv[]) {
	//var
	char filename[256],outfilename[256];
	unsigned char wc;
	unsigned int out_kol;
	int i;
	init();
	if (argc != 1 && argc != 2) {
		printf("Must be either zero or one argument.\n");
		return -1;
	}
	if (argc <= 1) {
		//files
		printf("Input name of file\n\n");
		scanf("%s",filename);
	} else {
		strcpy(filename, argv[1]);
	}
	strcpy(outfilename,filename);
	strcat(outfilename,".ch");
	//in=fopen("1"/*filename*/,"rb");
	//out=fopen("1.ch"/*outfilename*/,"wb");
	in = fopen(filename,"rb");
	out = fopen(outfilename,"wb");
	if (in == NULL) {
		cerr << "Error opening file!" << endl;
		getchar();
		return -1;
	}
	//kol
	KOL = 0;
	do {
		wc=getc(in);
		kol[wc]++;
		KOL++;
	} while (!feof(in));
	kol[wc]--;
	KOL--;
	//generation
	gen();

	//meta info
	fwrite(&KOL,4,1,out);
	fwrite(&K,2,1,out);
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
	buf_relax();
	//close
	fclose(in);
	fclose(out);
	//getchar();
	return 0;
}
