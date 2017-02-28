void init(){
	int i;
	for(i=0;i<256;i++){
		kol[i]=0;
		codes[i].size=0;
	}
	
	memset(kol,0,256);
	K=0;t=0;t2=0;KOL=0;bufs=0;
	//for(i=0;i<buf_size;i++)buf_out[i]=0;
}
