// Abstract class
class ISplitter {
public:
	virtual void split()=0;
	virtual ISplitter* clone()=0;	// construct self by cloning self

	virtual ~ISplitter() {}
};

// Concrete class
class BinarySplitter : public ISplitter {
public:
	virtual ISplitter* clone() {
		return new BinarySplitter(*this);
	}
};
class TxtSplitter : public ISplitter {
public:
	virtual ISplitter* clone() {
		return new TxtSplitter(*this);
	}
};
class VideoSplitter : public ISplitter {
public:
	virtual ISplitter* clone() {
		return new VideoSplitter(*this);
	}
};

class MainForm : public Form {
private:
	ISplitter* prototype;	// prototype object
public:
	MainForm(ISplitter* prototype) {
		this->prototype = prototype;
	}
	void Button1_Click() {
		ISplitter* splitter = prototype->clone();	// clone prototype
		splitter->split();
	}
};
