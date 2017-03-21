namespace hca { namespace HString {
	
	const string DumbFileNameChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.";
	
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
	
	bool checkDumbFileName(const string& text) {
		bool result = text.length() > 0 && text != "..";
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
	
}}