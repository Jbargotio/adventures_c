#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _hangman(char arr[5]);
int main()
{
	char arr [][100] = {"You",
		"Us",
		"All",
		"Them",
	       	"Me"};
	srand(time(NULL));
	int randomIndex = rand() % 3;
	printf("%s\n", arr[randomIndex]);
	_hangman(arr[randomIndex]);
	return 0;
}
void _hangman(char arr[5])
{
	char c;
	int n = strlen(arr);
	int correct = 0;
	printf("%d\n", n);
	while(correct < n)
	{
		printf("Enter a random letter:");
		scanf("%c", &c);
		for(int i = 0;i <n;i++)
		{
			if(arr[i] == c)
			{
				correct++;
				printf("%d\n", correct);
			}
			else
				continue;
		}
	}
}
