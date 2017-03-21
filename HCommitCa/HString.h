#pragma once

#include "include.h"

namespace hca { namespace HString {
	
	const string DumbFileNameChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ./";
	
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
		bfs::ifstream t(filePath);
		result = make_shared<string>(istreambuf_iterator<char>(t), istreambuf_iterator<char>());
		return result;
	}

}}