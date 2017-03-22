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
		auto result = false;
		auto fileName = context.subURL;
		if (checkDumbFileName(fileName)) {
			auto filePath = filesPath + fileName;
			cout << filePath << endl;
			auto content = loadFileToString(filePath);
			cout << (filePath + " " + boolToStr(content != nullptr) + "\n");
			if (content != nullptr) {
				context.request->body = content;
			}
		} else {
			cout << "Invalid file path specified: '" + fileName + "'\n";
			result = false;
		}
		return result;
	}

};

}}
