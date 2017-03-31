#pragma once
#ifdef file_messages_enabled
#pragma message("hca.HString.h")
#endif
#include "include.h"

namespace hca {

	const string DumbFileNameChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ./0123456789";

	map<string, string> MimeTypes = {
		{".html", "text/html"},
		{".js", "text/javascript"},
		{".css", "text/css"},
		{".svg", "image/svg+xml"}
	};

	string stringReplace(const string& text, const string& subText, const string& newText) {
		auto result = text;
		if (result.length() > 0) {
			while (true) {
				auto position = result.find(subText);
				if (position == string::npos)
					break;
				result.replace(position, subText.length(), newText);
			}
		}
		return result;
	}

	bool checkStringContains(const string& text, const string& desire) {
		return text.find(desire) != string::npos;
	}

	bool checkStringEndsWith(const string& text, const string& desire) {
		return text.find(desire) == text.length() - desire.length();
	}

	string getMimeType(const string& filePath) {
		string result;
		for (auto i = MimeTypes.begin(); i != MimeTypes.end(); ++i) {
			auto ext = i->first;
			if (checkStringEndsWith(filePath, ext)) {
				result = i->second;
				break;
			}
		}
		return result;
	}

	bool checkDumbFileName(const string& text) {
		bool result = text.length() > 0 && false == checkStringContains(text, "..");
		if (result) {
			for (size_t i = 0; i < text.length(); i++) {
				auto character = text[i];
				auto valid = DumbFileNameChars.find(character) != string::npos;
				if (false == valid) {
					result = false;
					break;
				}
			}
		}
		return result;
	}

	bool checkStringVectorContains(const vector<string>& a, const string& item) {
		return find(a.begin(), a.end(), item) != a.end();
	}

	shared_ptr<string> loadFileToString(const string& filePath) {
		shared_ptr<string> result;
		ifstream file(filePath);
		if (false == file.fail())
			result = make_shared<string>(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
		return result;
	}

	string boolToStr(const bool x) {
		if (x)
			return string("true");
		else
			return string("false");
	}

	char* cloneAsPChar(const string &x) {
		auto result = new char[x.length()];
		strcpy(result, x.c_str());
		return result;
	}

}