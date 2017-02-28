void init(){
	for(int i=0;i<256;i++)kol[i]=0;
	memset(kol,0,256);
	buf_out_pointer=buf_out;
	K=0;
	KOL=0;
	bufs=0;
}

int test_writecode(char c){
	fprintf(TESTF,"\t%d\t",codes[c].size);
	for(int i=0;i<codes[c].size;i++)
		fprintf(TESTF,"%d",codes[c].code[i]);
	fprintf(TESTF,"\n");
	return 0;
}
