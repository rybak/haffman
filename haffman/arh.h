uc A[8]={128,64,32,16,8,4,2,1};

void FromInToOut(){
	int in_c=0,out_c=0,outc=0,i,q,inc=0;
	int size;
	int P1,P2=0;
	do{
		in_c=chget();
		inc++;
		size=codes[in_c].size;
		for(i=0;i<size;i++){
			out_c = (out_c)
				| 
				((codes[in_c].code[i])
					? (A[outc%8])
					: 0
					);
			outc++;
			if(outc==8){
				outc=0;
				chput((uc)out_c);
				out_c=0;
				out_c=(uc)0;
				{
					P1=floor(((double)inc/KOL)*80);
					if(P1-P2==1) {
						printf("%c",176);
						P2=P1;
					}
				}
			}
		
		}
	}while(inc<KOL);

	q=outc/8+((outc%8)?1:0);
	if(q>0)chput((uc)out_c);//putc(out_c,out);
}
