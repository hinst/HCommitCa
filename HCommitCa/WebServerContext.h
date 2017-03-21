#include "include.h"

namespace hca { namespace Web {

struct WebServerContext {
	shared_ptr<WebRequest> request;
	shared_ptr<WebResponse> response;
	string subURL;
};

}}