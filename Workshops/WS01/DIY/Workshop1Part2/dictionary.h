//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 19, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_

#include "word.h"

namespace sdds
{
	extern struct Dictionary dictRecs;
	extern int noDefRecs;
	extern int noWordRecs;
	const int MAX_WORDS = 100;

	struct Dictionary
	{
		int m_totalWord;
		Word m_words[MAX_WORDS];
	};

	//Open file for read and check if NULL
	bool openFileForRead(const char* const file);
	
	//Write in file and check if NULL
	bool freadDefinition(Definition* definition);
	
	//Reads formatted input into stream for word
	bool freadWord(Word* word);

	//Close file
	void closeFile();

	//Load dictionary
	int LoadDictionary(const char* const file);

	//Write in file and check if NULL
	bool openFileForWrite(const char* const file);

	//Discard previously existing dictionary
	void clearList();

	//Sends formatted output to stream for dictionary
	void fwriteDictionary();

	//Get user input integer (should be in Utils.cpp module but matrix isn't accepting)
	int getInt(int min, int max);
}

#endif
