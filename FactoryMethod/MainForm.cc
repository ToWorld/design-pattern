class MainForm : public Form {
private:
	SplitterFactory* factory;	// factory
public:
	MainForm(SplitterFactory* factory) {
		this->factory = factory;
	}
	void Button1_Click() {
		ISplitter* splitter = factory->CreateSplitter();
		splitter->split();
	}
};
