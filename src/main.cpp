#include "../h/libs.h"
#include "./tobase.cpp"

bool isNumeric(char* s);
void printBases(const long num);
void printHelp();

static char sep=' ';

int main(int argc, char **argv){
	
	// no args provided
	if(argc<=1){
		printHelp();
		return 0;
	}

	// processing flags
	bool printHeaders=true;
	for(int i=1; i<argc; i++){
		if(strcmp("-h",argv[i])==0 || strcmp("--h",argv[i])==0){
			printHelp();
			return 0;
		}
		else if(strcmp("-s",argv[i])==0|| strcmp("--separator",argv[i])==0){
			++i;
			sep=argv[i][0];
		}
		else if(strcmp("-nh",argv[i])==0|| strcmp("--no-headers",argv[i])==0){	
			printHeaders=false;
		}
	}
	
	// taking care of headers
	if(printHeaders){
		std::cout<<"base10"<<sep
		<<"bin"<<sep
		<<"oct"<<sep
		<<"hex"<<std::endl;
	}

	// processing number args
	int nNumericArgs=0;
	for(int i=1;i<argc;i++){
		if(isNumeric(argv[i])){
			nNumericArgs++;
			printBases(atol(argv[i]));
		}
	}

	// no numeric args provided
	if(nNumericArgs==0){
		printHelp();
		return 1;
	}
	
	return 0;
}

bool isNumeric(char *s){
	for(;*s;++s)
		if(!isdigit(*s)) return false;
	return true;
}

void printBases(const long num){
	int bases[]={2,8,16};
	std::cout<<num;
	for(int j=0;j<3;j++)
		std::cout<<sep<<tobase::getBaseStr(num,bases[j]);
	std::cout<<std::endl;
}

void printHelp(){
	std::cout<<"usage: tobase VALUES+ [-s | --separator SEPARATOR] [-nh || --no-headers] [-h | --help]"<<std::endl;
	std::cout<<"made by @AmirHBahrami95"<<std::endl;
}
