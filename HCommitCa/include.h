#pragma once

#include <iostream>
#include <string>
#include <memory>

#include <boost/exception/diagnostic_information.hpp> 
#include <boost/exception_ptr.hpp> 
#include <boost/filesystem.hpp>

#include "h_http_sync_server.hpp"
#include <beast/test/sig_wait.hpp>

#include "HString.h"
using namespace hca::HString;
#include "WebServerContext.h"
#include "WebServer.h"
#include "App.h"