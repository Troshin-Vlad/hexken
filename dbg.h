#define CLR_ERR "\033[31m"
#define CLR_DEF "\033[0m"

void error(char *msg);
void debug(char *msg);

// print error message  and exit
void error(char *msg){
	fprintf(stderr,"[%serror%s]: %s\n",CLR_ERR,CLR_DEF,msg);
	exit(1);
}

void debug(char *msg){
	fprintf(stderr,"[debug]: %s\n",msg);
}
