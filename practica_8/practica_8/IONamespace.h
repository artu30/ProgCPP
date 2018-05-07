using fileID = FILE *;

namespace IONamespace {
	fileID openFile(const char *file, const char *mode);

	void closeFile(fileID fileId);

	const int readFile(fileID fileId, unsigned int numCharacters, char *readBuffer);

	const int writeFile(fileID fileId, const char writeBuffer[]);

	int getStringSize(const char myStr[]);
}