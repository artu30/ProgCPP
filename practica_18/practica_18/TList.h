class TList {
public:
	TList(const TList &copy);
	TList();

	~TList();

	int size();

	int push(IAlmacenable *psz);

	IAlmacenable * first();

	IAlmacenable *next();

	IAlmacenable * pop();

	void reset();

private:
	int m_needle;
	void* m_list;
};
