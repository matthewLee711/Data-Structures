class Index
{
private:
	//character dynamic allocated array
	
	


public:
	//constructor
	Index();
	//deconstructor
	//~Index();
	
	

	//this array brings in all characters from file
	int storeArray[80];//wordSize has buffer for a word of maximum 80
	int sorter;//stores number or character being passed from storeArray

	//These declarations are important for pageNumberExtracter
	char asciiConverter;//converters number being passed into pageNumberExtracter into character
	char pageNumberCopier[80];//store asciiConverted numbers
	int pageNumberCounter = 0;//this counter helps store page number into pageNumberCopier

	int pageNumber;//store page number after converted

	//These declarations are important for word extracter 
	char** wordArray;//2D array to store each word
	int wordArrayCounterRow = 0;//moves to next element in 2D wordArray
	int wordArrayCounterColumn = 0;
	char wordSize[80];//max size of 80 to find size of word
	int wordSizeCounter = 0;//counter for WordSize
	char wordConvert[80];//converts sorter into char which will be converted to char*
	int wordConvertCounter = 0;//wordConvertCOunter to copy number from sort
	
	//debug array
	char testArray[6] = { 'a', 'b','c' };
				   
	//Functions
	//All characters are passed through this function
	void textProcessor(int text);

	//Page number is extracted and temporarily stored from this function
	void pageNumberExtractor(int sorter);

	//Words are put into wordArray
	void wordArrayInsert(int sorter);

};
