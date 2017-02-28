void FromInToOut(){
	int inc=0,j,i,q;//////bits
	unsigned char c,size;
	while(inc<buf_size){
		c=buf_in[inc];
		size=codes[c].size;
		j=0;
		while(j<size){
			buf_out[(outc/8)]=0;
			switch((outc)%8){
			case 0:buf_out[(outc/8)]|=((codes[c].code[j])?128:0);break;
			case 1:buf_out[(outc/8)]|=((codes[c].code[j])?64:0);break;
			case 2:buf_out[(outc/8)]|=((codes[c].code[j])?32:0);break;
			case 3:buf_out[(outc/8)]|=((codes[c].code[j])?16:0);break;
			case 4:buf_out[(outc/8)]|=((codes[c].code[j])?8:0);break;
			case 5:buf_out[(outc/8)]|=((codes[c].code[j])?4:0);break;
			case 6:buf_out[(outc/8)]|=((codes[c].code[j])?2:0);break;
			case 7:buf_out[(outc/8)]|=((codes[c].code[j])?1:0);break;
			}
			if(!(outc%8))fprintf(TESTF,"|");
			if(!(outc%64))fprintf(TESTF,"\n");
			fprintf(TESTF,"%d",codes[c].code[j]);		
			j++;
			outc++;
		}
		inc++;
		if(outc>=buf_bitsize){
			outc%=buf_bitsize;
			fwrite(buf_out_pointer,1,buf_size,out);
			q=outc/8+((outc%8)?1:0);
			for(i=0;i<q;i++)buf_out[i]=buf_out[buf_size+i];
		}
	}

}

void FromInToOut2(){
	int inc=0,j,i,q;//////bits
	unsigned int c,size;
	while(inc<rest_in_bytes){
		c=buf_in[inc];
		size=codes[c].size;
		j=0;
		while(j<size){
			switch((outc)%8){
			case 0:buf_out[(outc/8)]|=((codes[c].code[j])?128:0);break;
			case 1:buf_out[(outc/8)]|=((codes[c].code[j])?64:0);break;
			case 2:buf_out[(outc/8)]|=((codes[c].code[j])?32:0);break;
			case 3:buf_out[(outc/8)]|=((codes[c].code[j])?16:0);break;
			case 4:buf_out[(outc/8)]|=((codes[c].code[j])?8:0);break;
			case 5:buf_out[(outc/8)]|=((codes[c].code[j])?4:0);break;
			case 6:buf_out[(outc/8)]|=((codes[c].code[j])?2:0);break;
			case 7:buf_out[(outc/8)]|=((codes[c].code[j])?1:0);break;
			}
			if(!(outc%8))fprintf(TESTF,"|");
			if(!(outc%64))fprintf(TESTF,"\n");
			fprintf(TESTF,"%d",codes[c].code[j]);			
			j++;
			outc++;
		}	
		inc++;
		if(outc>=buf_bitsize){
			outc%=buf_bitsize;
			fwrite(buf_out_pointer,1,buf_size,out);
			q=outc/8+((outc%8)?1:0);
			for(i=0;i<q;i++)buf_out[i]=buf_out[buf_size+i];
		}
	}
	int test=fwrite(buf_out_pointer,1,(outc/8)+((outc%8)?1:0),out);
//	for(i=0;i<(outc/8)+((outc%8)?1:0);i++)fprintf(TESTF,"%d",buf_out[i]);
}
