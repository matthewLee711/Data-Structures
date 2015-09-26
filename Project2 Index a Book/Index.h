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
	char* wordArray[80];//2D array to store each word
	int wordArrayCounterRow = 0;//moves to next element in 2D wordArray
	int wordArrayCounterColumn = 0;//Column for storing rows
	char wordSize[80];//max size of 80 to find size of word
	int wordSizeCounter = 0;//counter for WordSize
	char wordConvert[80];//converts sorter into char which will be converted to char*
	int wordConvertCounter = 0;//wordConvertCOunter to copy number from sort
	
	int createRowForArray = 0;//counter for creating row for 2Darray
	int rowCreatorAccessor = 0;//Access to create row for 2D array
	//debug array
	char testArray[6] = { 'a', 'b','c' };

	int debugCounter = 0;
				   
	//Functions
	//All characters are passed through this function
	void textProcessor(int text);

	//Page number is extracted and temporarily stored from this function
	void pageNumberExtractor(int sorter);

	//Non bracketed words are put into wordArray through this function
	void wordArrayInsert(int sorter);

	//bracketed wordds are inserted into wordArray through this function
	void wordArrayBracketedInsert(int sorter);

	void wordArrayInsert2(int sorter);//not needed

};
