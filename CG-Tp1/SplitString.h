#pragma once
#include <string>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;

class SplitString : public string {

private:
	vector<string> flds;

public:
	SplitString(string s) : string(s) {
	}

	vector<string>& SplitString::split(char delim, int rep) {
		if (!flds.empty()) flds.clear(); // empty vector if necessary
		string work = data();
		string buf = "";
		unsigned int i = 0;
		while (i < work.length()) {
			if (work[i] != delim) {
				buf += work[i];
			}
			else if (rep == 1) {
				flds.push_back(buf);
				buf = "";
			}
			else if (buf.length() > 0) {
				flds.push_back(buf);
				buf = "";
			}
			i++;
		}
		if (!buf.empty())
			flds.push_back(buf);
		return flds;
	}

	~SplitString()
	{
		flds.clear();
//		delete &flds;
	}
};

