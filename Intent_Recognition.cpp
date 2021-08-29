#include"Intent_Recognition.h"
#include<iostream>
#include<locale>

Intent_Recognition::Intent_Recognition()
{
	LoadIntents();
}

Intent_Recognition::~Intent_Recognition()
{

}

void Intent_Recognition::LoadIntents()
{
	m_mIntentsList.insert(pair<string, string>("fact","Intent: Get Fact"));
	m_mIntentsList.insert(pair<string, string>("weather local","Intent: Get Weather"));
	m_mIntentsList.insert(pair<string, string>("weather city","Intent: Get Weather City"));
}

void Intent_Recognition::ExtractWordsFromString(string userInput)
{
 	std::cout<<userInput<<std::endl;
	vector<string> words;
	size_t pos = 0;
	string space_delimiter = " ";
	m_whWord="";
	m_fillingWords.clear();
	m_topic="";
	m_city="";

   	while ((pos = userInput.find(space_delimiter)) != string::npos) 
	{
        	words.push_back(userInput.substr(0, pos));
	        userInput.erase(0, pos + space_delimiter.length());
	}
	words.push_back(userInput.substr(0,pos));

	for (const auto &str : words) 
	{
		for (const auto &strCheck : m_whWordsOfInterest)
		{	
			if (MatchStrings(str, strCheck) == true)
			{
				m_whWord = ProcessString(str);
//				cout<<"Strings Matched with word: "<<m_whWord<<endl;
				break;
			}
		}

		for (const auto &strCheck : m_fillingWordsOfInterest)
                {
                        if (MatchStrings(str, strCheck) == true)
                        {
                                m_fillingWords.push_back(ProcessString(str));
//                                cout<<"Strings Matched with word: "<<str<<endl;
                                break;
                        }
                }

		for (const auto &strCheck : m_topicWordsOfInterest)
                {
                        if (MatchStrings(str, strCheck) == true)
                        {
                                m_topic=ProcessString(str);
//                                cout<<"Strings Matched with word: "<<m_topic<<endl;
                                break;
                        }
                }

		for (const auto &strCheck : m_citiesOfInterest)
                {
                        if (MatchStrings(str, strCheck) == true)
                        {
                                m_city=ProcessString(str);
//                                cout<<"Strings Matched with word: "<<m_city<<endl;
                                break;
                        }
                }
//        	cout << str << endl;
    	}
}

string Intent_Recognition::GetIntentFromString(string userInput)
{
	ExtractWordsFromString(userInput);

	if ((m_whWord!="") && (m_topic!=""))
	{
		if(m_topic=="fact" && m_whWord=="tell")
		{
			  //std::cout << m_mIntentsList.find("fact")->second << "\n";
			  return m_mIntentsList.find("fact")->second;
		}
		else if (m_topic=="weather")
		{
			if (m_whWord=="what" || m_whWord=="how")
			{
				if (m_city!="")
				{
					//std::cout << m_mIntentsList.find("weather city")->second << "\n";
					return m_mIntentsList.find("weather city")->second;
				}
				else
				{
					//std::cout << m_mIntentsList.find("weather local")->second << "\n";
					return m_mIntentsList.find("weather local")->second;
				}
			}
		}
	}

	return "Topic is unknown";

}

bool Intent_Recognition::MatchStrings(const string& a, const string& b)
{
	//cout<<a<<b<<endl;
	bool stringsMatched = std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
	//cout<<"Strings Matched"<<stringsMatched<<endl;
	return stringsMatched;
}

string Intent_Recognition::ProcessString(string stringInput)
{
	auto lowerCaseString=stringInput;
	for(auto& it : lowerCaseString)
	{
   		it = tolower(it);
	}
	return lowerCaseString;
}
