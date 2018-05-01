#include <stdio.h>
#include <string.h>

int main()
{
	FILE *myFileHandle;
	
	myFileHandle = fopen("Project3TestFiles/test1.txt", "r");
	
	int theCounter; // Counts the number of times the appears within the file.
	char the[4] = "the";
	
	
	
	if (myFileHandle != NULL)
	{
		char textLine[200]; // This is where I will temporarily store the lines that I get from the text.
		
		while (fgets(textLine, 200, myFileHandle) != NULL)
		{
			printf("Line read is: %s\n", textLine);
			for (int i=0; i<strlen(textLine); i++)
			{
				if (textLine[i] == 116 || textLine[i] == 84)
				{
					if (textLine[i+1] == 104)
					{
						if (textLine[i+2] == 101)
						{
							if(textLine[i+3] == 32)
							{
								theCounter++;
								// printf("(%c %c %c) ", textLine[i+4], textLine[i+5], textLine[i+6]);
							}
						}
					}
				}
			}
		}
		fclose(myFileHandle);
	}
	printf("the number of 'the's inside of this file is %d.\n", theCounter);
}
