void FromInToOut(){
//	fprintf(TESTF,"FromInToOut()");
	int bufsc=0,inc=buf_bitsize,outc=0,uk=0;//////bits
	unsigned char next;
	while(bufsc<bufs){
		if(inc==buf_bitsize){
			fread(buf_in,1,buf_size,in);
			inc=0;
			bufsc++;
		}
		switch((inc)%8){
		case 0:next=(buf_in[(inc/8)]&128)?1:0;break;
		case 1:next=(buf_in[(inc/8)]&64)?1:0;break;
		case 2:next=(buf_in[(inc/8)]&32)?1:0;break;
		case 3:next=(buf_in[(inc/8)]&16)?1:0;break;
		case 4:next=(buf_in[(inc/8)]&8)?1:0;break;
		case 5:next=(buf_in[(inc/8)]&4)?1:0;break;
		case 6:next=(buf_in[(inc/8)]&2)?1:0;break;
		case 7:next=(buf_in[(inc/8)]&1)?1:0;break;
		}
		if(bor[uk][2]!=-1){
			buf_out[outc]=bor[uk][2];
			outc++;
			KOLOUT++;
			uk=0;
		}
		uk=bor[uk][next];
		if(!(inc%8))fprintf(TESTF,"|");
		if(!(inc%64))fprintf(TESTF,"\n");
		fprintf(TESTF,"%d",next);
		if(outc==buf_size){
			fwrite(buf_out_pointer,1,buf_size,out);
			outc=0;
		}
		inc++;
	}
}
////HABIBI hifi crash remix
void FromInToOut2(){
//	fprintf(TESTF,"FromInToOut2()");
	int next,inc=0,outc=0,uk=0;//////bits
	
	int test=fread(buf_in,1,rest_in_bytes,in);
	while(KOLOUT<KOL2){
		switch((inc)%8){
		case 0:next=(buf_in[(inc/8)]&128)?1:0;break;
		case 1:next=(buf_in[(inc/8)]&64)?1:0;break;
		case 2:next=(buf_in[(inc/8)]&32)?1:0;break;
		case 3:next=(buf_in[(inc/8)]&16)?1:0;break;
		case 4:next=(buf_in[(inc/8)]&8)?1:0;break;
		case 5:next=(buf_in[(inc/8)]&4)?1:0;break;
		case 6:next=(buf_in[(inc/8)]&2)?1:0;break;
		case 7:next=(buf_in[(inc/8)]&1)?1:0;break;
		}
		if(bor[uk][2]!=-1){
			buf_out[outc]=bor[uk][2];
			outc++;
			KOLOUT++;
			uk=0;
		}
		uk=bor[uk][next];
		if(inc==4270){
			fprintf(TESTF,"___");
		}
		
		if(!(inc%8))fprintf(TESTF,"|");
		if(!(inc%64))fprintf(TESTF,"\n");
		fprintf(TESTF,"%d",next);
		if(outc==buf_size){
			fwrite(buf_out_pointer,1,buf_size,out);
			outc=0;
		}
		inc++;
	}
	fwrite(buf_out_pointer,1,KOLOUT%buf_size,out);
}
