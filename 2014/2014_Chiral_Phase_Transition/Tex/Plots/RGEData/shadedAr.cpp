//Created: 11-05-2013
//Modified: lø. 11. mai 2013 kl. 14.43 +0200
//Author: Aleksandra R. Glesaaen
#include<cstdio>
using namespace std;

int main(int argc, char** argv){

	if(argc < 3){
		return 1;
	}

	FILE *input, *output;

	input = fopen(argv[1],"r");
	output  = fopen(argv[2],"w");

	float temp[100], val[100], err[100];

	int n = 0;

	while(fscanf(input,"%f %f %f",(temp+n),(val+n),(err+n)) != EOF){
		n++;
	}

	fclose(input);

	for(int i=0; i<n; i++){
		fprintf(output,"%f %f %f %f\n",temp[i],val[i],val[i]-err[i],val[i]+err[i]);
	}

	fclose(output);

	
}
