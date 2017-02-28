uc A[8] = {128, 64, 32, 16, 8, 4, 2, 1};

void FromInToOut()
{
	int inc = 8, uk = 0, next;
	int out_c, in_c;
	KOLOUT = 0;

	int P1, P2 = 0;
	do
	{
		if (inc == 8)
		{
			in_c = 0;
			in_c = chget();
			inc = 0;
		}
		//if(in_c&A[inc%8])next=1;else next=0;
		next = ((in_c) & A[inc%8]) ? 1 : 0;
		inc++;
		if (bor[uk][2] != -1)
		{
			out_c = bor[uk][2];
			chput(out_c);
			KOLOUT++;
			uk=0;
			{
				P1=floor(((double)KOLOUT/KOL2)*80);
				if(P1-P2==1)
				{
					printf("%c",176);
					P2 = P1;
				}
			}
		}
		uk = bor[uk][next];
		
	} while (KOLOUT < KOL2);
}
////HABIBI hifi crash remix
