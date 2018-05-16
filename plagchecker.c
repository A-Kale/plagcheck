#include <stdio.h>
#include <string.h>

struct Word {
	char name[4];
	int counter;
};

int main()
{
	FILE *myFileHandle;
	
	myFileHandle = fopen("Project3TestFiles/test1.txt", "r");
	
	int theCounter; // Counts the number of times the appears within the file.
	
	struct Word The; // Delcares The of the type Word.
	strcpy(The.name, "the");
	The.counter = 0;
	
	if (myFileHandle != NULL)
	{
		char textLine[270]; // This is where I will temporarily store the lines that I get from the text.
		
		while (fgets(textLine, 270, myFileHandle) != NULL)
		{
			printf("Line read is: %s\n", textLine);
			for (int i=0; i<strlen(textLine); i++)
			{
				if (textLine[i] != EOF)
				{
					if (textLine[i] == 116 || textLine[i] == 84)
					{
						if (textLine[i+1] == 104)
						{
							if (textLine[i+2] == 101)
							{
								if(textLine[i+3] == 32)
								{
									The.counter++;
									printf("(%c %c %c) ", textLine[i+4], textLine[i+5], textLine[i+6]);
								}
							}
						}
					}
				}
			}
			memset(textLine, '0', strlen(textLine));
		}
		fclose(myFileHandle);
	}
	printf("the number of 'the's inside of this file is %d.\n", The.counter);
}
