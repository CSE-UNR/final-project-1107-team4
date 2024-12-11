//Branden Hough & Adam Santos & Harold Kim
//12-10-2024
//Madlibs program that prompts user to input a verb, noun, or adjective. 
//The program then puts the users inputs into a madlib.

#include <stdio.h>
#define MADLIB1 "madlib1.txt"
#define MADLIB2 "madlib2.txt"
#define CAP 100

void plainMadlib(FILE* fin, char* letter);

void promptCounter(FILE* fin, char* letter, int* verbNum, int* nounNum, int* adjNum);

void promptSaver(FILE* fin, char* letter, char verbs[CAP], char nouns[CAP], char adj[CAP], char promptArray[][CAP]);

void promptsInArray(char prompts[][CAP], int vNum, int nNum, int aNum);

void madlibReader(FILE* fin, char* letter, char prompts[][CAP]);





int main()
{
	char ch;
	int verbNum = 0, nounNum = 0, adjNum = 0;

	FILE* fptrREAD;
	
	
	fptrREAD = fopen(MADLIB2, "r");
	
	if(fptrREAD == NULL)
	{
		printf("failed to open file\n");
	
		return 0;	
	}
	
	//plainMadlib(fptrREAD, &ch);
	
	fclose(fptrREAD);


	//Count to create size of 2d array to store prompts

	fptrREAD = fopen(MADLIB2, "r");
	
	promptCounter(fptrREAD, &ch, &verbNum, &nounNum, &adjNum);
	
	fclose(fptrREAD);
	
	
	
	
	//Storing 1d array user prompts into 2d array
	
	fptrREAD = fopen(MADLIB2, "r");
	
	
	char promptArray[verbNum + nounNum + adjNum][CAP];
	
	char vPhrase[CAP], nPhrase[CAP], adjPhrase[CAP];
	
	
	promptSaver(fptrREAD, &ch, vPhrase, nPhrase, adjPhrase, promptArray);
	
	

	fclose(fptrREAD);
	
	
	//Prints madlib to terminal with user prompts included
	
	fptrREAD = fopen(MADLIB2, "r");
	
	//promptsInArray(promptArray, verbNum, nounNum, adjNum);
	
	madlibReader(fptrREAD, &ch, promptArray);
	
	
	
	
	fclose(fptrREAD);
	
	
return 0;
	
}

void plainMadlib(FILE* fin, char* letter)
{
	printf("\n");
	while(fscanf(fin, "%c", letter) == 1)
	{
		printf("%c", *letter);
	}
}

void promptSaver(FILE* fin, char* letter, char verbs[CAP], char nouns[CAP], char adj[CAP], char promptArray[][CAP])
{
	int row = 0;
	
	while(fscanf(fin, "%c", letter) == 1)
	{
		if(*letter == 'V')
		{
			printf("Enter an verb: ");
			scanf("%s", verbs);
			int index = 0;
			
			
			while(verbs[index] != '\0' && index < CAP - 1)
			{
				promptArray[row][index] = verbs[index];
				index++;
			}
			promptArray[row][index] = '\0';
			row++;
			
		}
		
		if(*letter == 'A')
		{
			printf("Enter an adjective: ");
			scanf("%s", adj);
			int index = 0;
			
			
			while(adj[index] != '\0' && index < CAP - 1)
			{
				promptArray[row][index] = adj[index];
				index++;
			}
			promptArray[row][index] = '\0';
			row++;
			
		}
		
		if(*letter == 'N')
		{
			printf("Enter a noun: ");
			scanf("%s", nouns);
			int index = 0;
			
			
			
			while(nouns[index] != '\0' && index < CAP - 1)
			{
				promptArray[row][index] = nouns[index];
				index++;
			}
			promptArray[row][index] = '\0';
			row++;
			
		}
			
	}
}




void promptCounter(FILE* fin, char* letter, int* verbNum, int* nounNum, int* adjNum)
{
	while(fscanf(fin, "%c", letter) == 1)
	{
		if(*letter == 'V')
		{
			(*verbNum)++;
		}
		
		if(*letter == 'A')
		{
			(*adjNum)++;
		}
		
		if(*letter == 'N')
		{
			(*nounNum)++;
		}	
	}
}


void promptsInArray(char prompts[][CAP], int vNum, int nNum, int aNum)
{
		printf("\nThe Users Prompts:\n");
		for(int i = 0; i < (vNum + nNum + aNum); i++)
		{
			printf("%s\n", prompts[i]);
		}
		printf("\n");
	
}



void madlibReader(FILE* fin, char* letter, char prompts[][CAP])
{
	int row = 0;
	
	while(fscanf(fin, "%c", letter) == 1)
	{
		if(*letter == 'A' || *letter == 'V' || *letter == 'N')
		{
			printf("%s", prompts[row]);
			row++;
		}
		else if(*letter == '\n')
		{
			printf(" ");
		}
		else
		{
			printf("%c", *letter);
		}
	
	}
	printf("\n");

}






