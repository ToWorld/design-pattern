class Messager {
protected:
	MessagerImp* messagerImp;
public:
	virtual void Login(string username, string password)=0;
	virtual void SendMessage(string message)=0;
	virtual void SendPicture(Image image)=0;
	
	virtual ~Messager() {}
};

class MessagerImp {
public:
	virtual void PlaySound()=0;
	virtual void DrawShape()=0;
	virtual void Connect()=0;
	
	virtual MessagerImp() {}
};

// Platform implementation
class PCMessagerImp : public MessagerImp {
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void Connect() {}
};
class MobileMessagerImp : public MessagerImp {
public:
	virtual void PlaySound() {}
	virtual void DrawShape() {}
	virtual void Connect() {}
};

// Business abstraction
class MessagerLite : public Messager {
public:
	virtual void Login(string username, string password) {
		messagerImp->Connect();
	}
	virtual void SendMessage(string message) {
		messagerImp->WriteText();
	}
	virtual void SendPicture(Image image) {
		messagerImp->DrawShape();
	}
};
class MessagerPerfect : public Messager {
public:
	virtual void Login(string username, string password) {
		messagerImp->PlaySound();
		// ..
		messagerImp->Connect();
	}
	virtual void SendMessage(string message) {
		messagerImp->PlaySound();
		// ...
		messagerImp->WriteText();
	}
	virtual void SendPicture(Image image) {
		messagerImp->PlaySound();
		// ...
		messagerImp->DrawShape();
	}
};
