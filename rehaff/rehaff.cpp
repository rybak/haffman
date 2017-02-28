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

int main()
{
	//var
	char filename[256], outfilename[256];
	uc wc;
	unsigned int in_kol;
	int i, j;
	init();

	//files	
	printf("Input name of archive\n\n");
	scanf("%s", filename);
	printf("Input name of file\n\n");
	scanf("%s", outfilename);
	in  = fopen(filename,"rb"); 
	out = fopen(outfilename,"wb");
	if (in == NULL)
	{
		cerr << "Error opening file!\n";
		return 0;
	}
   //meta
	fread(&KOL2, 4, 1, in);	
	fread(&K, 2, 1, in);
	for (i = 0; i < K; i++){
		j = getc(in);
		in_kol = 0;
		fread(&in_kol, 4, 1, in);
		kol[j] = in_kol;
		alph[i].c = j;
		alph[i].w = in_kol;
		alph[i].i = i;	
	}

	if (K == 1)
	{
		for (i = 0; i < KOL2; i++)
			putc(alph[0].c, out);
		fclose(in);
		fclose(out);
		return 0;
	}

	//process
	gen();
	gen_bor();
	FromInToOut();
	buf_relax();

	//close
	fclose(in);
	fclose(out);
	return 0;
}
