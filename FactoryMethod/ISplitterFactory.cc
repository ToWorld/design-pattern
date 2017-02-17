// Abstraction class
class ISplitter {
public:
	virtual void split()=0;
	virtual ~ISplitter() {}
};

// Factory Base class
class SplitterFactory {
public:
	virtual ISplitter* CreateSplitter()=0;
	virtual ~SplitterFactory() {}
};
