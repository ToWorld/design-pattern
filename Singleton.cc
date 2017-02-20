class Singleton {
public:
	Singleton();
	Singleton(const Singleton&);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

// threading-unsafe
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

// threading-safe lock cost is much
Singleton* Singleton::getInstance() {
	Lock lock;
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

// reorder
// double-check lock unsafe because of memory read- write reorder
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		Lock lock;
		if (m_instance == nullptr) {
			m_instance = new Singleton();
		}
	}
	return m_instance;
}

// C++11 (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;
Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);// get memory fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);// release memory fence
			m_instance.store(tmp,std::memory_order_relaxed);
		}
	}
	return tmp;
}
