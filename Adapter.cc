// object interface (new interface)
class IAdaptee {
public:
	virtual void foo(int data)=0;
	virtual int bar()=0;
};

class OldClass : public IAdaptee {
	// ...
};

class Adapter : public ITarget {
protected:
	IAdapee* pAdaptee;
public:
	Adapter(IAdaptee* pAdaptee) {
		this->pAdaptee = pAdaptee;
	}
	virtual void process() {
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};

int main() {
	IAdaptee* pAdaptee = new OldClass();
	Itarget* pTarget = new Adapter(pAdaptee);
	pTarget->process();
}
