#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

#include <boost/exception/diagnostic_information.hpp> 
#include <boost/exception_ptr.hpp> 
#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>
namespace bfs { using namespace boost::filesystem; }

#include "h_http_sync_server.hpp"
#include <beast/test/sig_wait.hpp>

#include "HString.h"
using namespace hca::HString;
#include "Log.h"
using namespace hca::Log;
#include "WebServerContext.h"
#include "WebServer.h"
#include "App.h"
