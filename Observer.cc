class MainForm : public Form, public IProgress {
private:
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;
public:
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		FileSplitter splitter(filePath, number, progressBar);
		splitter.split(); 
	}
	virtual void DoProgress(float value) {
		progressBar->setValue(value);
	}
};

class IProgress {
public:
	virtual void DoProgress();
	virtual ~IProgress();
};

class FileSplitter {
private:
	string m_filePath;
	int m_fileNumber;
//	ProgressBar* m_progressBar;
	vector<IProgress*> m_iprogressVector;	// 抽象通知机制
public:
	FileSplitter(const string& filePath, int fileNumber) :
				m_filePath(filePath),
				m_fileNumber(fileNumber) {}
	void add_IProgress(IProgress* iprogress) {
		m_iprogressVector.push_back(iprogress);
	}
	void remove_IProgress(IProgress* iprogress) {
		delete ...;	
	}
	void split() {
		// 1. read file
		// 2. write to small files separately
		for (int i = 0; i < m_fileNumber; i++) {
			// ...
			float progressValue = m_fileNumber;
			progressValue = (i+1)/progressValue;
			onProgress(progressValue);
		}
	}
protected:
	[virtual] void onProgress(float value) {
		if (m_iprogress != nullptr) {
			m_iprogress->DoProgress(value);
		}
	}
};
