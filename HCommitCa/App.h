#pragma once
#pragma message("hca.App.h")
#include "include.h"

namespace hca {

using namespace std;

class App {

public:
	string dir;
	shared_ptr<WebServer> server;
	string configFilePath;
	string repoDirPath;

	void run() {
		GlobalLog->Write("App.run: dir='" + dir + "'");
		loadConfig();
		server = make_shared<WebServer>();
		server->filesPath = this->getWebDir();
		server->start();
		beast::test::sig_wait();
		server->stop();
	}

	string getWebDir() {
		return dir + "\\h-commit-ca\\build";
	}

	void loadConfig() {
		if (configFilePath.length() > 0) {
			boost::property_tree::ptree propertyTree;
			boost::property_tree::read_json(configFilePath, propertyTree);
			repoDirPath = propertyTree.get_child("repo").get_value<string>();
			GlobalLog->Write("Repo dir: " + repoDirPath);
		}
	}

};

}