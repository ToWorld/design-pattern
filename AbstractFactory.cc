// DB access base class
class IDBConnection {
public:
	virtual void connect()=0;
};
class IDBCommand {
public:
	virtual void command()=0;
};
class IDataReader {
public:
	virtual void dataReader()=0;
};

class IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection()=0;
	virtual IDBCommand* CreateDBCommand()=0;
	virtual IDataReader* CreateDataReader()=0;
};

// support SQL Server
class sqlConnection : public IDBConnection {
public:
	virtual void connect() {
		// TODO
	}
};
class sqlCommand : public IDBCommand {
public:
	virtual void command() {
		// TODO
	}
};
class sqlDataReader : public IDataReader {
public:
	virtual void dataReader() {
		// TODO
	}
};

class sqlDBFactory : public IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection() {
		return new sqlConnection();
	}
	virtual IDBCommand* CreateDBCommand() {
		return new sqlCommand();
	}
	virtual IDBDataReader* CreateDataReader() {
		return new sqlDataReader();
	}
};

// support Oracle
class OracleConnection : public IDBConnection {};
class OracleCommand : public IDBCommand {};
class OracleDataReader : public IDataReader {};

class OracleFactory : public IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection() {
		return new OracleConnection();
	}
	virtual IDBCommand* CreateDBCommand() {
		return new OracleCommand();
	}
	virtual IDBDataReader* CreateDataReader() {
		return new OracleDataReader();
	}
};

class EmployeeDAO {
private:
	IDBFactory* dbFactory;
public:
	vector<EmployeeDO> GetEmployees() {
		IDBConnection* connection = dbFactory->CreateDBConnection();
		connection->ConnectionString("...");

		IDBCommand* command = dbFactory->CreateDBCommand();
		command->command->CommandText("..");
		command->SetConnection(connection);
		// TODO
	}
};
