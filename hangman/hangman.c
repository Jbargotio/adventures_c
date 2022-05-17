#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	char words[][16]= {
		"Red",
		"Yellow",
		"Orange",
		"Green",
		"Blue",
		"Indigo",
		"Violet"
	};
	int randomIndex = rand() % 7;
	int chances = 5;
	int correct = 0;
	int oldCorrect = 0;
	int len = strlen(words[randomIndex]);
	int letterGuessed[7] = {0,0,0,0,0,0,0};
	int quit = 0;
	char guess[16];
	char letterEntered;
	printf("words:%s randomIndex:%d len:%d", words[randomIndex],randomIndex,len);
	printf("\n");
	int loopIndex = 0;
	while(correct < len)
	{
		for(loopIndex = 0;loopIndex < len;loopIndex++)
		{
			if(letterGuessed[loopIndex] == 1)
				printf("%c", words[randomIndex][loopIndex]);
			else
				printf("-");
		}
		printf("\n");
		printf("Number correct so far:%d\n", correct);
		printf("Enter a guess letter:");
		fgets(guess,16,stdin);

		if(strncmp(guess, "quit",4) == 0){
			quit = 1;
			break;
		}
		letterEntered = guess[0];
		printf("%c\n", letterEntered);
		oldCorrect = correct;
		for(loopIndex = 0;loopIndex < len;loopIndex++)
		{
			if(letterGuessed[loopIndex] == 1)
				continue;
			if(letterEntered == words[randomIndex][loopIndex])
			{
				letterGuessed[loopIndex] = 1;
				correct++;
			}
		}
		if(oldCorrect == correct)
		{
			chances--;
			printf("Sorry,wrong guess!\n");
			if(chances == 0)
				break;
		}
		else
			printf("Correct Guess!\n");

	}
	if(quit == 1)
	{
		printf("The user quit\n");
	}
	else if(chances == 0)
	{
		printf("Sorry,You lose. The word was <%s>\n", words[randomIndex]);
	}
	else
		printf("YOU WIN!!\n");
	
}	
