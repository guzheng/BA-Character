#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define h 90
#define w 120
#define fps 24
#define frame 5256

//static char *map[]={"██","▒▒","░░","  "};
char *map[]={"＠","！","．","　"};

int main(int argc, char *argv[])
{
	//setlocale(LC_ALL, "UTF-8");
	char framestr[h*w*9];
	FILE *datafile=fopen("img.data","r");
	int i,j,k,z;
	unsigned char oneframe[h][w/4];
	for (i=0;i<frame;i++)
	{
		fread(oneframe,sizeof(oneframe),1,datafile);
		memset(framestr,0,sizeof(framestr));
		for (j=0;j<h;j++)
		{
			for (k=0;k<w/4;k++)
			  for (z=3;z>-1;z--)
				strcat(framestr,map[(oneframe[j][k]>>(z*2))&3]);
			strcat(framestr,"\n");
		}
		printf("%s",framestr);
		//usleep(3000);
		//printf("%s",   "\033[1H\033[2J");
		//system("clear");
	}
	return 0;
}
