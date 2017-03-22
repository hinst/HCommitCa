#pragma once

#include "include.h"

namespace hca { namespace App {

using namespace std;

class App {

public: 
	string dir = "";
	shared_ptr<WebServer> server;

	void run() {
		cout << "App.run: dir='" + dir + "'\n";
		server = make_shared<WebServer>();
		server->filesPath = this->getWebDir();
		server->start();
		beast::test::sig_wait();
		server->stop();
	}

	string getWebDir() {
		return dir + "\\h-commit-ca\\build";
	}

};

}}