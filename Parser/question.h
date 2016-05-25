#ifndef QUESTION_H
#define QUESTION_H
#include<string>
#include<vector>

class Question {
	std::string question;
	short questionNumber;
	std::vector<std::pair<std::string, bool> > answers;
	int attempt;
	int correctAnswer;
	//answer,     , attempt, correctedAns
public:
	Question(std::string, int, std::vector<std::pair<std::string, bool> >, int,
			int);
        Question(){};
        
	void setNumerpytania(int);	//
	int getQuestionNumber(); //
	void setQuestion(std::string);	//
	std::string getQuestion();	//
	int getNumberOfAnswer();	//
	std::string getAnswer(unsigned int); //
	bool ifAnswerIsTrue(int);
	int getAttempt();	//
	int getCorrectAnswer();	//
	void setAttempt(int);	//
	void setCorrectAnswer(int);	//
        std::vector<std::pair<std::string, bool>>& getAnswerVector();
        void increaseAttempt();
        void increaseCorrectAnswer();
};

#endif // QUESTION_H
