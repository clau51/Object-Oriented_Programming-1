//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: September 19, 2022
//Section: NBB
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_WORD_H_
#define SDDS_WORD_H_

namespace sdds
{
	const int MAX_DEF = 8;
	const int MAX_WORD_LEN = 64;
	const int MAX_DEF_LEN = 1024;


	struct Definition
	{
		char m_type[MAX_WORD_LEN + 1];
		char m_definition[MAX_DEF_LEN + 1];
	};

	struct Word
	{
		int m_totalDef;
		char m_word[MAX_WORD_LEN + 1];
		Definition m_definitions[MAX_DEF];
	};

	//Saves the dictionary into a file
	void SaveDictionary(const char* filename);

	//Search in dictionary for the word and display all definitions found
	void DisplayWord(const char* word);

	//Add a new word to the dictionary; if it exists then update the definition instead
	void AddWord(const char* word, const char* type, const char* definition);

	//Update the definition of a word
	int UpdateDefinition(const char* word, const char* type, const char* definition);

	//Search for the index of a word
	int searchWordIndex(const char* string);

	//Copy the type and definition into the dictionary
	void copyTypeDefinition(int wordIndex, int defIndex, const char* type, const char* definition);

	//Check if the length of a string is too long
	bool checkLen(const char* string, int maxLength);

	//Print error message
	void printLenError();

	//Print the type and definition of a word at a particular index
	void printTypeDefinition(const int index);
}

#endif
