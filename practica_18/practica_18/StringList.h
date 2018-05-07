class StringList : public IAlmacenable {
public:
	const char *str;

	StringList(const char* text);
	~StringList();
	void printVar() const;
};