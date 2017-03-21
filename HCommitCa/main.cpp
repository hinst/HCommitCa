#include "include.h"

using namespace std;
using namespace hca::App;

int main(int argc, char *argv[])
{
	cout << "[STARTING...]\n";
	App app;
	app.dir = argv[0];
	app.run();
	cout << "[EXITING...]\n";
	return 0;
}
