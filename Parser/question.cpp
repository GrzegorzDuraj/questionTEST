#include "question.h"

using namespace std;

Question::Question(string q, int qNo, vector<pair<string, bool> > ans, int atm,
		int cAns) {
	question = q;
	questionNumber = qNo;
	answers = ans;
	attempt = atm;
	correctAnswer = cAns;
}

void Question::setNumerpytania(int number) {
	questionNumber = number;
}
int Question::getQuestionNumber() {
	return questionNumber;
}
void Question::setQuestion(string q) {
	question = q;
}

string Question::getQuestion() {
	return question;
}
string Question::getAnswer(unsigned ansNo) {
	if (ansNo <= answers.size()) {
		return answers.at(ansNo).first;

	} else {
		return "No question with this number";
	}
}

int Question::getNumberOfAnswer() {
	return answers.size();
}

int Question::getAttempt() {
	return attempt;
}
int Question::getCorrectAnswer() {
	return correctAnswer;
}
void Question::setAttempt(int value) {
	attempt = value;
}
void Question::setCorrectAnswer(int value) {
	correctAnswer = value;
}

vector<pair<string, bool>> & Question::getAnswerVector()
{
    return answers;
}

void Question::increaseAttempt()
{
    ++attempt;
}
void Question::increaseCorrectAnswer()
{
    ++correctAnswer;
}