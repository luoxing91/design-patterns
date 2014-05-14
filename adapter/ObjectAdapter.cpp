#include <iostream>
#include <string>

using namespace std;

class ClientInterface
{
public:
	virtual std::string method() = 0;
};

class Adaptee
{
public:
	std::string method1() { return "Adapter";  }
	std::string method2() { return " pattern"; }
};

class AdapterImplementation : public ClientInterface
{
	Adaptee adapteeInstance;

public:
	virtual std::string method() 
	{ 
	    return adapteeInstance.method1() + adapteeInstance.method2();
        }
};

int main()
{
	AdapterImplementation adapImpl;
	ClientInterface& adapter = adapImpl;
	cout << adapter.method();

	return 0;
}