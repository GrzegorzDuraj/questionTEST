/* 
 * File:   Question.hpp
 * Author: grdu
 *
 * Created on May 20, 2016, 3:37 PM
 */

#ifndef QUESTION_HPP
#define	QUESTION_HPP

#include <string>
#include <vector>

class Question {
public:
    Question();
    //Question(const Question& orig);
    virtual ~Question();

public:
        std::string question;
	int numerpytania;
	std::vector<std::pair<std::string, bool> > vec;
	int attempt;
	int correctAns;
        
public:
	void setNumerpytania(int);
	void setQuestion(std::string);
	std::string getQuestion();
	int getNumberOfAnswer();
	std::string getAnswer(int);
	void setNewAnser(std::string, bool);
	bool ifAnswerIsTrue(int);
	int getAttempt();
	int getCorrectAns();
};

#endif	/* QUESTION_HPP */

