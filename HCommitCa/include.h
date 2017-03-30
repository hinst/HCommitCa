#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>
using namespace std;

#include <boost/exception/diagnostic_information.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "h_http_sync_server.hpp"
#include <beast/test/sig_wait.hpp>

#include "Log.h"
#include "HString.h"
#include "WebServerContext.h"
#include "WebServer.h"
#include "App.h"
