#pragma once
#pragma message("hca.WebServerContext.h")
#include "include.h"

namespace hca {

struct WebServerContext {
	shared_ptr<WebRequest> request;
	shared_ptr<WebResponse> response;
	string subURL;
};

}
