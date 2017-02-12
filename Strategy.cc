class Strategy {
public:	
	virtual void algorithmInterface() = 0;
	virtual ~Strategy() { }
};

class ConcreteStrategy1 : public Strategy {
public:
	virtual void algorithmInterface() {
		// TODO
	}
};

class ConcreteStrategy2 : public Strategy {
public:
	virtual void algorithmInterface() {
		// TODO
	}
};

class ConcreteStrategy3 : public Strategy {
public:
	virtual void algorithmInterface() {
		// TODO
	}
};

class Context {
public:
	Context(StrategyFactory* strategyFactory) {
		this->strategy = strategyFactory->NewStrategy();
	}
	~Context() {
		delete this->strategy;
	}
	void contextInterface() {
		// TODO
		strategy->algorithmInterface();
		// TODO
	}
private:
	Strategy* strategy;
};
