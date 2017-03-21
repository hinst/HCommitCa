#include "include.h"

using namespace std;
using namespace hca::App;

int main(int argc, char *argv[])
{
	cout << string("[STARTING]");
	App app;
	app.dir = bfs::system_complete(argv[0]).parent_path().string();
	app.run();
	cout << "[EXITING...]\n";
	return 0;
}
