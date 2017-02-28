void init(){
	int i;
	for(i=0;i<256;i++)codes[i].size=0;
	memset(kol,0,256);
	buf_out_pointer=buf_out;
	K=0;
	KOL=0;
	KOLOUT=0;
	bufs=0;
	borc=0;
}

void bor_new(int i){
	int j=0,k=0;
	while(j<codes[i].size){
		if(bor[k][codes[i].code[j]]!=-1){
			k=bor[k][codes[i].code[j]];
		}else{
			bor[k][codes[i].code[j]]=borc;
			k=borc;
			borc++;		
		}		
		j++;
	}
	bor[k][2]=i;
}

void gen_bor(){
	for(int i=0;i<1000;i++)bor[i][0]=bor[i][1]=bor[i][2]=-1;
	borc=3;	
	bor[0][0]=1;
	bor[0][1]=2;
	bor[0][2]=-1;
	for(i=0;i<256;i++)
		if(codes[i].size)bor_new(i);
}
