#include "../h/libs.h"

namespace tobase{

	// opposite of toPower! - iknow it's a shitty name but fuck you
	int getPower(long num,int base){
		int pow=-1;
		while(num>0){
			num/=base;
			if(pow==-1)pow++; // clear the state
			pow++;
		}
		return pow;
	}

	// return a string representation of a number in any given base
	std::string getBaseStr(long num,long base){

		// how many characters you need
		int pow=getPower(num,base)-1;
		char res[pow];

		// making the result string
		int i=0;
		long temp;
		for(;num>0;i++){
			temp=num%base;
			if(temp>=10)// handling base>=10+ 
				res[pow-i]='a'+temp-10;
			else res[pow-i]='0'+temp;
			num/=base;
		}
		res[i]='\0';

		// return in string form
		std::string jack(res);
		return jack;
	}

	std::string getBinaryStr(long num){
		return getBaseStr(num,2);
	}

	std::string getOctetStr(long num){
		return getBaseStr(num,8);
	}

	std::string getHexStr(long num){
		return getBaseStr(num,16);
	}

}
