#pragma once

#include "include.h"

namespace hca { namespace Web {

class WebServer {

public:
	string address = "0.0.0.0";
	unsigned short int port = 8080;
	string appURL = "/h-commit-ca";
	string filesPath = "";

	void start() {
		boost::asio::ip::tcp::endpoint endpoint{boost::asio::ip::address::from_string(address), port};
		server = make_shared<beast::http::http_sync_server>(endpoint, "");
		server->handleRequest = [this](shared_ptr<WebRequest> request, shared_ptr<WebResponse> response) {
			this->handleRequest(request, response);
		};
	}

	void stop() {
		this->server = nullptr;
	}

private:
	shared_ptr<beast::http::http_sync_server> server;

	void handleRequest(shared_ptr<WebRequest> request, shared_ptr<WebResponse> response) {
		if (request->url.find(appURL) == 0) {
			WebServerContext context;
			context.request = request;
			context.response = response;
			context.subURL = request->url;
			context.subURL.erase(0, appURL.length());
			this->handleFileRequest(context);
		}
	}

	bool handleFileRequest(WebServerContext context) {
		auto fileName = stringReplace(context.subURL, "/", "");
		if (checkDumbFileName(fileName)) {
			cout << context.subURL << endl;
			auto result = loadFile(fileName);
		} else {
			context.response->body = "Invalid file path specified: '" + fileName + "'";
		}
	}

	shared_ptr<string> loadFile(string fileName) {
		auto result = make_shared<string>();
		auto files = getFiles();
		if (checkStringVectorContains(files, fileName)) {

		}
	}

	vector<string> getFiles() {
		auto result = vector<string>();
		for (bfs::directory_iterator i(filesPath); i != bfs::directory_iterator(); ++i) {
			auto currentPath = i->path();
			if (false == is_directory(currentPath)) {
				auto fileName = currentPath.filename();
				result.push_back(fileName.string());
			}
		}
		return result;
	}

};

}}
