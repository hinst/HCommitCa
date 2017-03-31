#ifdef file_messages_enabled
#pragma message("hca.main.cpp")
#endif
#include "include.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "[STARTING]\n";
	App app;
	app.dir = boost::filesystem::system_complete(argv[0]).parent_path().string();
	if (argc > 1)
		app.configFilePath = argv[1];
	app.run();
	cout << "[EXITING...]\n";
	return 0;
}
