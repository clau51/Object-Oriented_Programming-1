#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_

namespace sdds
{
	extern struct Dictionary dictRecs;
	extern int noDefRecs;
	extern int noWordRecs;
	const int MAX_WORD_LEN = 64;
	const int MAX_DEF_LEN = 1024;
	const int MAX_WORDS = 100;
	const int MAX_DEF = 8;

	struct Definition
	{
		char type[MAX_WORD_LEN + 1];
		char definition[MAX_DEF_LEN + 1];
	};

	struct Word
	{
		int totalDef;
		char word[MAX_WORD_LEN + 1];
		Definition definitions[MAX_DEF];
	};

	struct Dictionary
	{
		int totalWord;
		Word words[MAX_WORDS];
	};


	bool openFileForRead(const char* const file);
	bool freadDefinition(Definition* definition);
	bool freadWord(Word* word);
	void closeFile();
	int LoadDictionary(const char* const file);
	int searchWordIndex(const char* string);
	void printTypeDefinition(const int index);
	bool openFileForWrite(const char* const file);
	int getInt(int min, int max);
	void clearList();
	void fwriteDictionary();
	int getInt(int min, int max);
	void copyTypeDefinition(int wordIndex, int defIndex, const char* type, const char* definition);
	bool checkLen(const char* string, int maxLength);
	void printLenError();
}


#endif
