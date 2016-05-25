#ifndef PARSER_H
#define PARSER_H
#include<string>
#include<vector>

class Parser {

	std::string testContent;
	std::string answerContent;

public:
	static std::string fileWithTest;
	static std::string fileWithAnswer;

	Parser();
	void setTestContent(std::string test);
	void setAnswerContent(std::string answer);
	std::string getTestContent();
	std::string getAnswerContent();
	std::string getTextFromFile(std::string text);
	std::vector<std::string> parseQuestionsToVector(std::string text);
	std::vector<std::string> parseAnswersToVector(std::string answer);
	std::vector<std::string> parseCorrectAnswersToVector(std::string answer);
	std::vector<std::vector<std::pair<std::string, bool>>>mergeAnswersWithCorrectAnswers(std::vector<std::string>, std::vector<std::string>);
};
#endif // PARSER_H
