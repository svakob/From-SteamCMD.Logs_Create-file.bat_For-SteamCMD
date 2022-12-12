#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#define endl "\n"
#define DEBUG 0
#define OLD 0
using namespace std;

void console_cp() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
class LogChecker {

	string LogFileName;
	string ParsAfter;
	string FileName;

	string GetLogFile() {
		ifstream FILE;
		FILE.open(LogFileName);
		if (FILE.is_open()) {
			string result;
			string line;
			int Characters = 0;
			while (getline(FILE, line))
			{
				result += line;
#if DEBUG == 1
				cout << line << "\t" << endl;
#endif // DEBUG == 1
			}
			FILE.close();
#if DEBUG == 1
			cout << result << endl;
#endif // DEBUG == 1
			return result;
		}
		else {
			FILE.close();
			cout << "ERROR: open file." << endl;
			return "ERROR";
		}
	}

	bool CheckIfNotInVector(vector<string> InVector, string Value) {
		for (vector<string>::iterator iterator = InVector.begin(); iterator != InVector.end(); iterator++) {
			if (*iterator == Value) {
				return false;
			}
		}
		return true;
	}

	vector<string> ParsIDFormSrring(string str) {
		vector<string> Ids;
		int ParsAfterSize = ParsAfter.size();
		string cache;
		for (int i = str.find(ParsAfter, 0), last_i = 0; i > last_i; i = str.find(ParsAfter, i + 1)) {
			for (string::iterator iterator = str.begin() + i + ParsAfterSize; *iterator != ' '; iterator++) {
				cache.push_back(*iterator);
			}
			if (CheckIfNotInVector(Ids, cache)) {
				Ids.push_back(cache);
			}
			else {
#if DEBUG == 2
				cout << "secon text finded" << endl;
#endif // DEBUG == 2
			}
			cache.clear();
			last_i = i;
		}
		return Ids;
	}

	void SaveToFile(string data) {
		ofstream FILE;
		FILE.open(FileName);
		FILE << data;
		FILE.close();
	}

public:

	LogChecker(string LogFileName, string ParsAfter, string FileName = "Script.bat") {
		this->LogFileName = LogFileName;
		this->ParsAfter = ParsAfter;
		this->FileName = FileName;
	}

	void StarScript() {
		vector<string> Ids = ParsIDFormSrring(GetLogFile());
		string data = "@ECHO OFF\nstart /wait steamcmd +login anonymous";
		for (vector<string>::iterator iterator = Ids.begin(); iterator != Ids.end(); iterator++) {
			data += " +workshop_download_item 294100 " + *iterator;
		}
		SaveToFile(data);
		cout << Ids.size() << endl;
	}
};
int main()
{
	console_cp();
	LogChecker Script("workshop_log.txt", " [AppID 294100] Download item ", "Script.bat");
	Script.StarScript();
}
