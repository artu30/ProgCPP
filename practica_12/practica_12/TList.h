class TList {
public:
	TList(const char *list[], const int size);
	TList();

	TList(const TList& list);

	~TList();

	const char ** getList() const;

	unsigned int getSize() const;

	int size() const;

	int push(const char *psz);

	const char * first();

	const char *next();

	const char * pop();

	void reset();

private:
	unsigned int m_size;
	unsigned int m_needle;
	const char **m_list;
	void Init(const char *list[], const int size);
};
