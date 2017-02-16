// Business operation
class Stream {
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

// Subject class
class FileStream : public Stream {
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;
};
class NetworkStream : public Stream {
public:
	virtual char Read(int number) {}
	virtual void Seek(int position) {}
	virtual void Write(char data) {}
};
class MemoryStream : public Stream {
public:
	virtual char Read(int number) {}
	virtual void Seek(int position) {}
	virtual void Write(char data) {}
};

//Extended operation
DecoratorStream : public Stream {
protected:
	Stream* stream;
	DecoratorStream(Stream* stm) : stream(stm) {}
};
class CryptoStream : public DecoratorStream {
public:
	// TODO
	CryptoStream(Stream* stm) : DecoratorStream(stm) {}
};
class BufferedStream : public DecoratorStream {
public:
	// TODO
	BufferedStream(Stream* stm) : DecoratorStream(stm) {}
};
