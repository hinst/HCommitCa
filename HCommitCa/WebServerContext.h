#pragma once
#ifdef file_messages_enabled
#pragma message("hca.WebServerContext.h")
#endif
#include "include.h"

namespace hca {

struct WebServerContext {
	shared_ptr<WebRequest> request;
	shared_ptr<WebResponse> response;
	string subURL;
};

}
