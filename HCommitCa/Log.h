#pragma once

#include "include.h"

namespace hca { namespace Log {

class Log {

private:
	boost::mutex locker;

public:

	void Write(const string& message) {
		boost::mutex::scoped_lock lock(mutex);
		cout << message << endl;
	}

};

auto GlobalLog = make_shared<Log>();

}}
