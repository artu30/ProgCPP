using fileID = FILE *;

struct TFile {
private:
	fileID m_file;
public:
	TFile();

	~TFile();

	const int openFile(const char *file, const char *mode);

	void closeFile();

	const int readFile(unsigned const int numCharacters, char *readBuffer);

	const int writeFile(const char writeBuffer[], int bufferSize = 0);

	const int getStringSize(const char myStr[]);
};
