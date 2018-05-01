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
		char textLine[90]; // This is where I will temporarily store the lines that I get from the text.
		
		while (fgets(textLine, 90, myFileHandle) != NULL)
		{
			if(strstr(textLine, the) != NULL)
			{
				theCounter++;
			}
		}
		fclose(myFileHandle);
	}
	printf("the number of 'the's inside of this file is %d.\n", theCounter);
}
