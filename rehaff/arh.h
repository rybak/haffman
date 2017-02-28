uc A[8]={128,64,32,16,8,4,2,1};

void FromInToOut(){
	int inc=8,uk=0,next;
	int out_c,in_c;
	KOLOUT=0;
//	fprintf(TESTF,"\narh:\n\n");
	do{
		if(inc==8){
			in_c=0;
			in_c=(uc)getc(in);
			inc=0;
		}
		if(in_c&A[inc%8])next=1;else next=0;
		//next=((in_c)&A[inc%8])?1:0;
		inc++;
		//fprintf(TESTF,"%d",next);
		if(bor[uk][2]!=-1){
			out_c=bor[uk][2];
			putc(out_c,out);
			KOLOUT++;
			uk=0;
		}
		uk=bor[uk][next];
	}while(KOLOUT<KOL2);
}
////HABIBI hifi crash remix
//if((X)&Y)next=1;else next=0;//next=((X)&Y)?1:0;