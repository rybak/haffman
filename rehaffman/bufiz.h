const int buf_size=1000;

uc buf_in[buf_size], buf_out[buf_size];

int buf_inc, buf_outc;

void init_buf()
{
	buf_inc  = buf_size;
	buf_outc = 0;
}

inline uc chget()
{
	if (buf_inc == buf_size)
	{
		fread(buf_in, 1, buf_size, in);
		buf_inc=0;
	}
	return buf_in[buf_inc++];
}

inline void chput(int c)
{
	if (buf_outc == buf_size)
	{
		fwrite(buf_out, 1, buf_size, out);
		buf_outc=0;
	}
	buf_out[buf_outc++]=c;
}

void buf_relax(){
	if (buf_outc>0)
		fwrite(buf_out, 1, buf_outc, out);
}
