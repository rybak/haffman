void gen_init()
{
	int i;

	for (i = 0; i < K; i++)
	{
		tree[i].l = -1;
		tree[i].r = -1;
		tree[i].p = -1;
		forest[i].w = alph[i].w;
		forest[i].r = i;
	}
	t  = K;
	t2 = t;
}

void gencode(int P, uc code[], int &size)
{
	int next;
	if (tree[P].p == -1)
		return;
	int w=tree[P].p;     
	if (tree[w].l == P)
		next = 0;
	else
		next = 1;
	code[size] = next;
	size++;
	gencode(w, code, size);
}

void gen_find(int &x1, int &x2)
{
	int i, p1, p2;
	p1 = 0;
	p2 = 1;
	if (forest[p1].w > forest[p2].w)
	{
		// p1 ^= p2 ^= p1 ^= p2;
		int w = p1;
		p1 = p2;
		p2 = w;
	}
	if (t > 1)
		for (i = 2; i < t; i++)
			if (forest[i].w < forest[p2].w)
			{
				if (forest[i].w > forest[p1].w)
					p2 = i;
				else
				{
					p2 = p1;
					p1 = i;
				}
			}
	x1 = p1;
	x2 = p2;
}

void gencreate(int i, int j)
{
	tree[t2].l = forest[i].r;///v konec dobavlyaem novyi uzel u kotorogo list'a = minimums
	tree[t2].r = forest[j].r;
	tree[t2].p = -1;
	tree[forest[i].r].p = t2;///govorim 4to novyi uzel parent dlya minimums	
	tree[forest[j].r].p = t2;
	forest[i].w = forest[i].w + forest[j].w;///zapisyvaem uzel v les vmesto pervogo minimuma
	forest[i].r = t2;
	forest[j].w = forest[t-1].w;///ubiraem vtoroi minimum
	forest[j].r = forest[t-1].r;
	t2++;
	t --;
}

unsigned char S[256];

void gen_codes()
{
	int size = 0, i, j;

	memset(S,0,256);

	for(i = 0; i < K; i++){
		size = 0;
		gencode(i, S, size);
		for(j = 0; j < size; j++)
			codes[alph[i].c].code[j] = S[size-j-1];
		codes[alph[i].c].size = size;
	}
}

void gen()
{
	int i, j;
	gen_init();
	while(t > 1)
	{
		gen_find (i, j);
		gencreate(i, j);
	}
	gen_codes();
}
