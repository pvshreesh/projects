#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int nSub;
	scanf("%d", &nSub);

	int subArr[nSub];

	for(int i=0; i < nSub; i++)
		scanf("%d", &subArr[i]);

	int nInput;
	scanf("%d", &nInput);

	//Taking inputs of requirement Array.
	int reqArr[nInput][2];

	for(int i = 0; i< nInput; i++)
		scanf("%d%d", &reqArr[i][0], &reqArr[i][1]);

	//Copying contents of subject Array into a temporary array
	int tempArr1[nSub];
	for(int i = 0; i<nSub; i++)
		tempArr1[i] = subArr[i];
	

	//All subjects which have atleast one prerequisite will be removed(changed to -1)
	for(int i = 0; i<nSub; i++)
	{
		for(int j = 0; j<nSub; j++)
		{
			if(reqArr[i][1] == tempArr1[j])
			{
				tempArr1[j] = -1;
			}
		}
	}

	int finalArr[nSub];
	int finalCount = 0; //To keep track of index while adding elements 
	//Adding all elements with no prerequisites into final array
	for(int i=0; i<nSub; i++)
	{
		if(tempArr1[i]!= -1)
		{
			finalArr[finalCount] = tempArr1[i];
			finalCount++;
		}

	}

	/***************************MISTAKE********************************/
	//Used to add elements into final array wihout changing value of loop count
	int finalCountCopy = finalCount;
	//Now adding all the elements in order
	while(finalCount < nSub)
	{
		for(int i = 0; i<nInput; i++)
		{
			for(int j = 0; j<finalCount; j++)
			{
				if(finalCountCopy >= nSub) break;

				if(reqArr[i][0] == finalArr[j])
				{
					finalArr[finalCountCopy] = reqArr[i][1];
					reqArr[i][0] = -2;
					finalCountCopy++;
				}
			}
			if(finalCountCopy >= nSub) break;
		}

		finalCount = finalCountCopy;
	}
	/*************************MISTAKE***********************************/


	//Printing final answer
	printf("\n\n");
	for(int i=0; i<nSub; i++)
	{
		printf("%d ", finalArr[i]);
	}	
	printf("\n");
	
	return 0;
}