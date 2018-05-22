#include <stdio.h>
#include <string.h>

struct Words {
	char name[50];
	int counter;
};

struct Library {
	char words[500];
}

int main()
{
	struct Library lib; // Will be using this to store all the words found.
	
	FILE *myFileHandle;
	
	myFileHandle = fopen("Project3TestFiles/test1.txt", "r");
	
	if (myFileHandle != NULL)
	{
		char textLine[500];
		while(fgets((textLine), sizeof(textLine), myFileHandle) != NULL)
		{
			const char s[15] = ",-;: '.\"";
			char *temp;
			temp = strtok(textLine, s);
			while(temp != NULL)
			{
				printf("%s\n", temp);
				arraySearch(textLine
				temp = strtok(NULL, s);
			}
		}
	}
}

int arraySearch(char *str, char *word)
{
	int i=0; j=0; counter=0;
	
	while (i<strlen(str))
	{
		if (str[i] == word[j])
		{
			i++;
			j++;
			if(i == strlen(word))
			{
				j++;
				i = j;
				j = 0;
			}
		}
		else
		{
			i++;
			j++;
		}
	}
}
