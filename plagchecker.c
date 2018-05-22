#include <stdio.h>
#include <string.h>

struct Library {
	char words[5000];
	int wordCounter[2000];
};

/* This function searches the provided char array for the word, and
 * returns the number of times it finds the word in the array.*/

int arraySearch(char *str, char *word)
{
	
	int i=0, j=0, counter=0;
	
	while (i<strlen(str))
	{
		if (str[i] == word[j] || str[i] == (word[i] + 32))
		{
			i++;
			j++;
			if(i == strlen(word))
			{
				j++;
				// i = j;
				j = 0;
				counter++;
			}
			;
		}
		else
		{
			i++;
			j++;
		}
	}
	return counter;
}
int uniqueWord(char *str, char *word)
{
	if (arraySearch(str, word) == 0)
		return 1;
	else
		return 0;
}
/* By counting the number of spaces, I can count the number of words in the Library, since each word has been separated
 * by a space character. This lets me easily refer to the counter of each word.*/

int spaceRetriev(char *str, char *word)
{
	int spaces = 0, j = 0;
	
	for (int i = 0; i < sizeof(word); i++)
	{
		if (str[i] == word[j] || (str[1]+32) == word[j])
		{
			i++;
			j++;
		}
		else if (str[i] == 32)
		{
			spaces++;
			j = 0;
		}
	}
		
	return spaces;
}

int main()
{
	struct Library lib; // Will be using this to store all the words found.
	char *tempNames; // This is where I will store the names gathered from the textLine, so that I can name the structure after them.
	
	FILE *myFileHandle;
	
	myFileHandle = fopen("Project3TestFiles/test2.txt", "r");
	
	if (myFileHandle != NULL)
	{
		char textLine[500];
		while(fgets((textLine), sizeof(textLine), myFileHandle) != NULL)
		{
			const char s[15] = ",-;: '.\""; // This checks for punctuation.
			int pos = 1; // I will use this to tally the number of words that have been placed in the library.
			
			// This block deals with chopping up the textLine into tokens, which I use to store the words.
			char *temp; 
			temp = strtok(textLine, s);
			while(temp != NULL)
			{
				printf("%s\n", temp);
				if (uniqueWord(lib.words, temp) != 0) // Is the word unique? If so, store it in the library.
				{
					strcat(lib.words, temp);
					strcat(lib.words, " ");
				}
				else
				{
					lib.wordCounter[spaceRetriev(lib.words, temp)]++; // Refer to the function.
				}
				temp = strtok(NULL, s);
			}
		}
	}
	fclose(myFileHandle);
	
	
	printf("%d", lib.wordCounter[2]);

}
