#include <iostream>
#include <string>
#include "Intent_Recognition.h"

using namespace std;
int main(int argc, char *argv[])
{
	cout<<"Program is starting"<<endl;
	string userInput;
	Intent_Recognition intentRecognition;

	while (true) 
	{
		cout<<"Enter Input: ";
                getline(cin, userInput);
		//cout<<"The user entered: "<<userInput<<endl;
		if( userInput=="q" || userInput=="Q" || userInput=="exit" || userInput=="Exit")
		{
			cout<<"Program is exiting"<<endl;
			break;
		}
		else
		{
			auto intent=intentRecognition.GetIntentFromString(userInput);	
			cout<<intent<<"\n"<<endl;
		}
	}

	return 0;
}
