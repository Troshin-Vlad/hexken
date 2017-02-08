#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include "info.h"
#include "dbg.h"
#include "vars.h"
#include "display.h"
#include "options.h"


int main(int argc, char *argv[]){

	FILE *fout = stdout;
	FILE *fin = stdin;

	char ch,opt;
	int optid;
	int line_cnt = 0, char_cnt = 0;

	fmt.ch = '2';
	display.addrs = 1;


	while( (opt = getopt_long(argc,argv,"o:i:l:24ah",long_opt,&optid)) ){
		if(opt == -1)
			break;

		switch(opt){
			case 'o':
				if(!(fout = fopen(optarg,"w"))) error("open output file");
				break;
			case 'i':
				if(!(fin = fopen(optarg,"r"))) error("open input file");
				break;
			case 'l':
				addr_len = atoi(optarg);
				if( (addr_len <= 2) || (addr_len >= 100) ) error("length address is out range");
				break;
			case '2':
				fmt.ch = '2';
				break;
			case '4':
				fmt.ch = '4';
				break;
			case 'a':
			    display.addrs = 0;
			    break;
			case 'h':
				help();
		}
	}

	
	snprintf(fmtaddr,10,"[%%%c%ix]: ",'.',addr_len);

	char fmthex[7];
	snprintf(fmthex,6,"%%%c%cX ",'.',fmt.ch);

    if(display.addrs)
        display_line(&line_cnt,fout);
        
	while( (ch = fgetc(fin)) != EOF ){
		char_cnt++;

		fprintf(fout,fmthex,ch);

		if(char_cnt >= 0x10)
			line_null(&char_cnt,&line_cnt,fout);
		
	}


	fputc('\n',fout);

	fclose(fout);
	fclose(fin);
	
	return 0;
}
