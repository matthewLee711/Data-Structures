#include <iostream>
#include <sstream>
#include "Index.h"

//Functions
//Constructor to initialize all pointers to NULL
Index::Index()
{
	char* text = NULL;
	for (int i = 0; i < 10; i++) pageNumberCopier[i] = { NULL };
	for (int i = 0; i < 10; i++) wordSize[i] = { NULL };
	for (int i = 0; i < 10; i++) wordConvert[i] = { NULL };
	wordArray = new char*[80];//memory allocation for 80 different words
	//for (int i = 0; i < 10; i++) storeArray[i] = { NULL };
}

void Index::textProcessor(int storeArray)
{
	sorter = storeArray;
	//sends to pageNumberExtracter which will convert it into Page Number
	if (sorter >= 48 && sorter <= 57 || sorter == 62)
	{
		pageNumberExtractor(sorter);
	}

	//MAKE SURE OT INCLUDE '\0' to terminate
	//converts upper to lower case letter and store into 2D array
	if (sorter >= 65 && sorter <= 90 || sorter >= 97 && sorter <= 122 || sorter == 32)
	{
		//convert upper case to lowercase
		sorter = tolower(sorter);//add putchar() if need to see output
		//std::cout << "lower case: " << sorter << std::endl;

		//send to wordArrayInsert function; this will put words into 2D array
		wordArrayInsert(sorter);

	}
	
	//catches two letter words
	if(sorter == 91) {}
}

void Index::pageNumberExtractor(int sorter)
{
	if (sorter == 62)
	{
		//debug
		//for (int i = 0; i < 3; i++) std::cout << "before atoi: " << pageNumberCopier[i] << std::endl;

		pageNumber = atoi(pageNumberCopier);//convert char array into int once done
		std::cout << "pageNumber: " << pageNumber << std::endl;

		//clear array*****************************************************************
		//delete[] storeArray;

		pageNumberCounter = 0;
		//for (int i = 0; i < 10; i++) std::cout << "storeArray before null: " << storeArray[i] << std::endl;
		//set everything to zero
		for (int i = 0; i < 10; i++) pageNumberCopier[i] = { NULL };//reset pageNummberCopier to store next numbers
		//for (int i = 0; i < 10; i++) std::cout << "storeArray final: " << storeArray[i] << std::endl;

		//return pageNumber;
	}

	if (sorter >= 48 && sorter <= 57)
	{
		//convert ascii number into char, which will be put into array
		asciiConverter = sorter;
		//std::cout << "asciiConverter: " << asciiConverter << std::endl;
		//pageNumberCopier stores number from asciiConverter
		pageNumberCopier[pageNumberCounter] = asciiConverter;
		//for (int i = 0; i < 5; i++) std::cout << "pageNumberCopier: " << pageNumberCopier[i] << std::endl;
		pageNumberCounter++;//iterate to prepare for next number to be stored

		//return pageNumberCopier[pageNumberCounter];
	}
	
}

void Index::wordArrayInsert(int sorter)
{
	int delimiter = 32;
	//2D array
	//after length and found space after word, allocate 2D memory for word
	if(sorter == delimiter) 
	{
		//debug
		for (int i = 0; i < wordSizeCounter; i++)
			std::cout << "wordSize: " << wordSize[i] << std::endl;
		
		//copy word into wordSize which word array will point to *FAILED*
		//wordSize[wordSizeCounter] = wordConvert;//pointing only to address
		//std::cout << "wordSize: " << wordSize[wordSizeCounter] << std::endl;
		//wordSizeCounter++;
		
		//allocate exact memory for wordArray row
		wordArray = new char* [wordSizeCounter];
		
		//copy wordSize into wordArray
		/*for (int i = 0; i < wordSizeCounter; i++)
		{
			wordArray[i] = wordSize[i];
		}*/
		//copy wordSize into WordArray V1 *CRASHED*
		//wordArray[wordArrayCounter] = wordSize[wordArrayCounter];
		//wordArrayCounter++;//increment

		//copy wordSize into WordArray V2 *CRASHED*
		wordArray[wordArrayCounterColumn][wordArrayCounterRow] = testArray[wordArrayCounterRow]; //wordSize[wordArrayCounterRow];
		wordArrayCounterRow++;//increment

		//if wordArrayCounter reaches wordSizeCounter, move to next row in wordArray
		if (wordArrayCounterRow == wordSizeCounter)
		{
			wordArrayCounterColumn++;
		}

		//debug statement for 2d array
		//for (int i = 0; i < wordSizeCounter; i++)std::cout << "wordArray: " << wordArray[i] << std::endl;

		//reset wordSizeCounter to prepare for next word
	}
	//copy each character into wordConvert
	//wordConvert[wordConvertCounter] = sorter;

	//wordSize finds size of word and prepares storage into 2D wordArray
	wordSize[wordSizeCounter] = sorter;
	wordSizeCounter++;
	//debug
	//std::cout << "wordConvert " << wordConvertCounter << ": " << wordConvert[wordConvertCounter] << std::endl;
	//wordConvertCounter++;//increase to store words
	//find word size and temporarily store word
	/*if (sorter != ' ')
	{
		//wordSize finds size of word and temporarily stores word
		//for loop to copy
		wordSize[wordSizeCounter] = wordConvert;//pointing only to address
		//std::cout << "wordSize: " << wordSize[wordSizeCounter] << std::endl;
		wordSizeCounter++;
	}*/
	
}
/*void Index::ReadPagePublic(char* text)
{

}
void Index::ReadTwoWordsPublic(char* text)
{

}
void Index::ReadCharacterPublic(char* text)
{

}*/