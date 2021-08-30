#include<string>
#include<vector>
#include <map>

using namespace std;

class Intent_Recognition
{
	private: 
	string m_inputString="";
	
	string m_whWordsOfInterest[3]={"How", "What", "Tell"};
	string m_topicWordsOfInterest[2]={"fact", "weather"};
	string m_fillingWordsOfInterest[5]={"the", "like", "is", "me", "an"};
	string m_citiesOfInterest[7]={"Paris", "Berlin", "Copenhagen", "Islamabad", "Karachi", "Delhi", "Mumbai"};
	map<string, string> m_mIntentsList;
	
	string m_whWord="";
	string m_topic=""; 
	vector<string> m_fillingWords;
	string m_city="";

	public: 
	Intent_Recognition();
	~Intent_Recognition();
	void ExtractWordsFromString(string userInput);
	bool MatchStrings(const string& a, const string& b);
	string GetIntentFromString(string userInput);
	void LoadIntents();
	string ProcessString(string stringInput);
	string cleanupString(string input);
};
