uc A[8]={128,64,32,16,8,4,2,1};

void FromInToOut(){
	int in_c=0,out_c=0,outc=0,i,q,inc=0;
	int size;
//	fprintf(TESTF,"\narh:\n\n");
	do{
		in_c=getc(in);
		inc++;
		size=codes[in_c].size;
		for(i=0;i<size;i++){
			out_c=(out_c)|((codes[in_c].code[i])?(A[outc%8]):0);
			outc++;
			if(outc==8){
				outc=0;
				putc(out_c,out);
				out_c=0;
				out_c=(uc)0;
			}
		//	fprintf(TESTF,"%d",(codes[in_c].code[i]));		
		}
	}while(!feof(in)/*inc<KOL*/);

	q=outc/8+((outc%8)?1:0);
	if(q>0)putc(out_c,out);
}
