void init(){
	for(int i=0;i<256;i++){kol[i]=0;codes[i].size=0;}
	memset(kol,0,256);
	buf_out_pointer=buf_out;
	K=0;
	KOL=0;
	bufs=0;
}
