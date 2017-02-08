void help();
void putopt(char chs,char *chl,char *msg);

// print help page
void help(){
	printf("Usage: hexksu\n");
	putopt('o',"out","specific output file");
	putopt('i',"in","specific input file");
	putopt('l',"max-addr-len","max length address");
	putopt('a',"no-addrs","no display address");
	putopt('2',"two","print format 2 numhex (default)");
	putopt('4',"four","print format 4 numhex");
	putopt('h',"help","print this help");
	exit(1);
}

// print format string option
void putopt(char chs,char *chl,char *msg){
	printf("  -%c,  --%s:  %s\n",chs,chl,msg);
}
