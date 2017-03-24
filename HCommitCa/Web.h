#pragma once

#include "include.h"

namespace hca { namespace Web {

using namespace std;

typedef beast::http::request<beast::http::string_body> WebRequest;
typedef beast::http::response<beast::http::string_body> WebResponse;

}}
