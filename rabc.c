#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

char *com, *output;
unsigned int seed, tempo, bl, *b, l, r, x, y;

void playbeat(int repeat){
	for(int re = 0; re < repeat; re++){
	for(int i = 0; i < bl; i++){
		char arg[53];
		sprintf(arg," synth %f sin %d fade 0 0 0.05 vol %f :",1.0f/tempo,b[i],(4200.0f-b[i])/4200);
		strcat(com,arg);
	}}
}

int note(){
	int r = rand()%(y-x+1)+x;
	return 440*pow(2,(r-49)/12);
}

int main(int argc, char *argv[]){
	srand(time(NULL));

	output = malloc(25);
	strcpy(output,"out.ogg");
	seed = rand();
	tempo = 4;
	r = 1;
	l = 0;
	x = 1;
	y = 64;

	int c;
	while((c = getopt(argc, argv, "o:l:s:t:r:x:y:")) != -1){
	switch(c){
	case 'o':
		output = optarg;
		break;
	case 'l':
		l = atoi(optarg);
		break;
	case 's':
		seed = atoi(optarg);
		break;
	case 't':
		tempo = atoi(optarg);
		break;
	case 'r':
		r = atoi(optarg);
		break;
	case 'x':
		x = atoi(optarg);
		break;
	case 'y':
		y = atoi(optarg);
		break;
	case '?':
		printf("Known options are o,l,s,t,r,x,y. All options require an argument.\n");
		return 1;
	default:
		abort();
	}
	}

	srand(seed);

	if(l == 0)
		bl = tempo*(rand()%5+4);
	else
		bl = tempo*l;
	b = malloc(bl*4);

	for(int i = 0; i < bl; i++){
		b[i] = note();
	}

	com = malloc(53*bl*r);
	strcpy(com,"sox -n ");
	strcat(com,output);
	
	playbeat(r);

	com[strlen(com)-1] = '\0';
	FILE *rabctmp = fopen("rabctmp","w");
	fputs(com,rabctmp);
	fclose(rabctmp);
	system("sh rabctmp");
	system("rm rabctmp");

	free(com);
	free(output);
	free(b);
	return 0;
}
