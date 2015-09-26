#include <iostream>
#include <fstream> 
#include "Index.h"

using namespace std;

int main()
{
	//create processing object
	Index processer;

	int array_size = 1024; // define the size of character array
	//char** twoDarray = new char*[array_size];// array to store words
	//char** pageArray = new char*[array_size];// array to store pages
	//char storeArray[80];//wordSize has buffer for a word of maximum 80
	//char pageNumberCopier[80];//page number copier with buffer

	//int pageNumberCounter = 0;//counter for collecting page number
	//char asciiConverter;


	//int pageNumber = 0;//store page number temporarily

	//Code to open file in ascii
	int store = 0;
	FILE* openFile;
	openFile = fopen("Text.txt", "r");

	//debug for opening file
	/*for (int i = 0; i < 10; i++)
	{
	store = fgetc(openFile);
	cout << "test: " << store << endl;
	}*/

	//debug to output file
	//for (int wordCounter = 0; wordCounter < !feof(openFile); wordCounter++) store = fgetc(openFile);
	//std::cout << feof(openFile);

	int wordCounterTest = 0;
	

	//while(fgets(storeArray, 80, openFile)){ }
	//while (fgetc(openFile)) { storeArray[wordCounterTest] = fgetc(openFile); wordCounterTest++; cout << "start: " << wordCounterTest << storeArray[wordCounterTest] << std::endl; }

	//Read through array and convert words and page numbers and convert them into right place
	for (int wordCounter = 0; !feof(openFile); wordCounter++)
	{
		//copy words from file into array
		processer.storeArray[wordCounter] = fgetc(openFile);//dont forget to clear it
		//std::cout << "storeArrayOutput" << wordCounter << ": " << processer.storeArray[wordCounter] << std::endl;
		
		//pass array to function which will process
		processer.textProcessor(processer.storeArray[wordCounter]);

		//make sure to account for number infront of word. separate for 2 words

	}//end of for loop



	 //create size array which will count size, this size array will be put into twoDarray
	 //twoDarray[i] = new char[i size of word];//row is allocated size based on word
	return 0;
}