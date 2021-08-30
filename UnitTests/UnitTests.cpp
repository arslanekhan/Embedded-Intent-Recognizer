// UnitTests.cpp
#include "Intent_Recognition.cpp"
#include <gtest/gtest.h>
#include <string>

TEST(GetIntent, FromStrings) { 
    	Intent_Recognition intentRecognition;
	ASSERT_EQ("Intent: Get Fact", intentRecognition.GetIntentFromString("Tell me an interesting fact"));
	ASSERT_EQ("Intent: Get Fact", intentRecognition.GetIntentFromString("Tell me a fact"));
	ASSERT_EQ("Intent: Get Weather", intentRecognition.GetIntentFromString("What is the weather like today?"));
	ASSERT_EQ("Intent: Get Weather", intentRecognition.GetIntentFromString("How is the weather?"));
	ASSERT_EQ("Intent: Get Weather City", intentRecognition.GetIntentFromString("How is the weather in Paris today?"));
	ASSERT_EQ("Intent: Get Weather City", intentRecognition.GetIntentFromString("What is the weather like in Paris today?"));
	ASSERT_EQ("Intent: Get Weather City", intentRecognition.GetIntentFromString("how is the weather in Berlin?"));
}

TEST(MatchStrings, FromStrings) {
	Intent_Recognition intentRecognition;
        ASSERT_EQ(true, intentRecognition.MatchStrings("Fact","fact"));
	ASSERT_EQ(true, intentRecognition.MatchStrings("weather","Weather"));
	ASSERT_EQ(false, intentRecognition.MatchStrings("weather","fact"));
}

TEST(ProcessStrings, FromStrings) {
        Intent_Recognition intentRecognition;
        ASSERT_EQ("fact", intentRecognition.ProcessString("FACT"));
        ASSERT_EQ("weather", intentRecognition.ProcessString("Weather"));
        ASSERT_EQ("paris", intentRecognition.ProcessString("PArIs"));
}

TEST(CleanupStrings, FromStrings) {
        Intent_Recognition intentRecognition;
        ASSERT_EQ("fact", intentRecognition.cleanupString("f?%$&%$act"));
        ASSERT_EQ("weather", intentRecognition.cleanupString("weather?1254575488785"));
        ASSERT_EQ("paris", intentRecognition.cleanupString("pa$$$§!ris"));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
