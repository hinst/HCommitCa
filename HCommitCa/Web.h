#pragma once
#ifdef file_messages_enabled
#pragma message("hca.Web.h")
#endif
#include "include.h"

namespace hca {

typedef beast::http::request<beast::http::string_body> WebRequest;
typedef beast::http::response<beast::http::string_body> WebResponse;

}
