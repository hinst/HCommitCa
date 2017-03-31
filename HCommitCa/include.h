#pragma once
#pragma message("hca.include.h")

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <memory>
#include <cstdio>
#include <utility>
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
#include "HProcess.h"
#include "WebServerContext.h"
#include "WebServer.h"
#include "App.h"
