class Library {
public:
    // template method
	void run() {	
		Step1();

		if (Step2()) {
			Step3();
		}
	
		for (int i = 0; i < 4; i++) {
			Step4();
		}

		Step5();
	}
	virtual ~Library() { }
protected:
	void Step1() {
		// TODO
	}
	void Step3() {
		// TODO
	}
	void Step5() {
		// TODO
	}
protected:
	virtual bool Step2() = 0;
	virtual void Step4() = 0;
};

