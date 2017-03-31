#include "include.h"

namespace hca {

class Process {

tuple<HANDLE, HANDLE> prepareStructs(STARTUPINFO& startupInfo, PROCESS_INFORMATION& processInfo) {
	ZeroMemory(&processInfo, sizeof(processInfo));
	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);
	SECURITY_ATTRIBUTES securityAttributes; 
	securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
	securityAttributes.bInheritHandle = true;
	securityAttributes.lpSecurityDescriptor = nullptr;
	HANDLE child_input_read;
	HANDLE child_input_write;
	CreatePipe(&child_input_read, &child_input_write, &securityAttributes, 0);  
	HANDLE child_output_read;
	HANDLE child_output_write;
	CreatePipe(&child_output_read, &child_output_write, &securityAttributes, 0);
	startupInfo.hStdInput = child_input_read;
	startupInfo.hStdOutput = child_output_write;
	startupInfo.hStdError = child_output_write;
	startupInfo.dwFlags |= STARTF_USESTDHANDLES;
	return make_tuple(child_output_read, child_input_write);
}

void closeProcessInfo(PROCESS_INFORMATION& processInfo) {
	CloseHandle(processInfo.hProcess);
	processInfo.hProcess = 0;
	CloseHandle(processInfo.hThread);
	processInfo.hThread = 0;
}

shared_ptr<string> loadOutput(HANDLE handle) {
	stringstream stream;
	char buffer[100];
	DWORD receivedLength;
	while (true) {
		auto readResult = ReadFile(handle, buffer, sizeof(buffer), &receivedLength, nullptr);
		if (readResult)
		if (readResult == false)
			break;
		if (receivedLength > 0)
			stream.write(&buffer[0], receivedLength);
	}
	return make_shared<string>(stream.str());
}

shared_ptr<string> run(string command) {
	shared_ptr<string> result;
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo; 
	auto rw = prepareStructs(startupInfo, processInfo);

	auto commandStr = strdup(command.c_str());
	auto createProcessResult = CreateProcess(nullptr, commandStr, nullptr, nullptr, true, 0, nullptr, nullptr, &startupInfo, &processInfo);
	free(commandStr);
	commandStr = nullptr;

	if (createProcessResult)
		result = loadOutput(get<0>(rw));

	closeProcessInfo(processInfo);
	return result;
}

};

}