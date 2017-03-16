class Memento {
	string state;
public:
	Memento(const string& s) : state(s) {}
	string getState() const { return state; }
	void setState(const string& s) { state = s;}
};

class Originator {
	string state;
	// ...
public:
	Originator() {}
	Memento createMemento() {
		Memento m(state);
		return m;
	}
	void setMemento(const Memento& m) {
		state = m.getState();
	}
};

int main() {
	Originator originator;
	
	// catch object state, store it to the memento
	Memento mem = originator.createMemento();
	
	// change originator state 
	
	// restore from memento
	originator.setMemento(memento);
}
