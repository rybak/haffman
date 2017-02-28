void init(){
	int i;
	for(i=0;i<256;i++){
		codes[i].size=0;
		kol[i]=0;
	}
	memset(kol,0,256);
	K=0;
	KOL=0;
	KOL2=0;
	borc=0;
	for(i=0;i<600;i++){bor[i][0]=-1;bor[i][1]=-1;bor[i][2]=-1;}
	//for()
	//for(i=0;i<600;i++){bor.c=-1;bor.n[0]=-1;bor[]}
}

void bor_new(int i){
	int j,k=0,CODEJ;
	for(j=0;j<codes[i].size;j++)
	{
		CODEJ=codes[i].code[j];
		if(bor[k][CODEJ]==-1){
			bor[k][CODEJ]=borc;
			k=borc;
			borc++;
		}else k=bor[k][CODEJ];
	}
	bor[k][2]=i;
}

void gen_bor(){
	int i;
	borc=1;
	for(i=0;i<256;i++)
		if(codes[i].size)bor_new(i);
}
