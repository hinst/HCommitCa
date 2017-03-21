#include <iostream>
#include <string>
#include <memory>
std::shared_ptr<int> intptr;

using namespace std; 

class Classy {
	
public:
	Classy() {
		cout << "create\n";
	}
	
	int a, b, c;
	
	Classy(Classy& other) {
		cout << "copy\n";
	}
};

void prepare(Classy& classy) {
	
};

int main(int argc, char **argv)
{
	cout << "starting\n";
	shared_ptr<Classy> classy(new Classy());
	prepare(*classy);
	return 0;
}
