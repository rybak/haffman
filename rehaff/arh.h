void FromInToOut(){
	int inc=0,j,i,q;//////bits
	char c,size;
	while(inc<buf_size){
		c=buf_in[inc];
		size=codes[c].size;
		j=0;
		while(j<size){
			switch((outc)%8){
			case 0:buf_out[(outc/8)].q.b1=codes[c].code[j];break;
			case 1:buf_out[(outc/8)].q.b2=codes[c].code[j];break;
			case 2:buf_out[(outc/8)].q.b3=codes[c].code[j];break;
			case 3:buf_out[(outc/8)].q.b4=codes[c].code[j];break;
			case 4:buf_out[(outc/8)].q.b5=codes[c].code[j];break;
			case 5:buf_out[(outc/8)].q.b6=codes[c].code[j];break;
			case 6:buf_out[(outc/8)].q.b7=codes[c].code[j];break;
			case 7:buf_out[(outc/8)].q.b8=codes[c].code[j];break;
			}
			fprintf(TESTF,"%d",codes[c].code[j]);
			j++;
			outc++;
		}
		inc++;
		if(outc>=buf_bitsize){
			outc%=buf_bitsize;
			fwrite(buf_out_pointer,1,buf_size,out);
			q=outc/8+((outc%8)?1:0);
			for(i=0;i<q;i++)buf_out[i].c=buf_out[buf_size+i].c;
		}

	}
}

void FromInToOut2(){
	int inc=0,j,i,q;//////bits
	char c,size;
	while(inc<rest_in_bytes){
		c=buf_in[inc];
		size=codes[c].size;
		j=0;
		while(j<size){
			switch((outc)%8){
			case 0:buf_out[(outc/8)].q.b1=codes[c].code[j];break;
			case 1:buf_out[(outc/8)].q.b2=codes[c].code[j];break;
			case 2:buf_out[(outc/8)].q.b3=codes[c].code[j];break;
			case 3:buf_out[(outc/8)].q.b4=codes[c].code[j];break;
			case 4:buf_out[(outc/8)].q.b5=codes[c].code[j];break;
			case 5:buf_out[(outc/8)].q.b6=codes[c].code[j];break;
			case 6:buf_out[(outc/8)].q.b7=codes[c].code[j];break;
			case 7:buf_out[(outc/8)].q.b8=codes[c].code[j];break;
			}
			fprintf(TESTF,"%d",codes[c].code[j]);
			j++;
			outc++;
		}	
		inc++;
		if(outc>=buf_bitsize){
			outc%=buf_bitsize;
			fwrite(buf_out_pointer,1,buf_size,out);
			q=outc/8+((outc%8)?1:0);
			for(i=0;i<q;i++)buf_out[i].c=buf_out[buf_size+i].c;
		}
	}
	fwrite(buf_out_pointer,1,(outc/8)+((outc%8)?1:0),out);
	fprintf(TESTF,"\noutfile get  %d  bytes\n",(outc/8)+((outc%8)?1:0));
	fprintf(TESTF,"\noutfile chars:\n\n");	
	for(i=0;i<(outc/8)+((outc%8)?1:0);i++)fprintf(TESTF,"%c\n",buf_out[i]);
}
