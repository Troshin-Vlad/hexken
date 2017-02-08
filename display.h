void display_line(int *ln,FILE *out);
void line_null(int *chs,int *ls,FILE *out);

// display address line
void display_line(int *ln,FILE *out){
	fprintf(out,fmtaddr,*ln);
	*ln = *ln + 0x10;
}

// print char->(new line) and numer line
void line_null(int *chs,int *ls,FILE *out){
	fputc('\n',out);
	if(display.addrs) 
	    display_line(ls,out);

	*chs = 0;
}


