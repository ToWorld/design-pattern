// Concrete class
class BinarySplitter : public ISplitter {

};
class TxtSplitter : public ISplitter {

};
class PictureSplitter : public ISplitter {

};
class VideoSplitter : public ISplitter {

};

// Concrete factory
class BinarySplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* CreateSplitter() {
		return new BinarySplitter();
	}
};
class TxtSplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* CreateSplitter() {
		return new TxtSplitter();
	}
};
class PictureSplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* CreateSplitter() {
		return new PictureSplitter();
	}
};
class VideoSplitterFactory : public SPlitterFactory {
public:
	virtual ISplitter* CreateSplitter() {
		return new VideoSplitter();
	}
};
