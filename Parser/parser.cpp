// reading a text file
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;

string Parser::fileWithTest =
		"istqb.txt";
string Parser::fileWithAnswer =
		"answ.txt";

Parser::Parser() {
}

void Parser::setTestContent(string test) {
	testContent = test;
}

void Parser::setAnswerContent(string answer) {
	answerContent = answer;
}
string Parser::getTestContent() {
	return testContent;
}

string Parser::getAnswerContent() {
	return answerContent;
}

string Parser::getTextFromFile(string filename) {
	string line, text;
	ifstream file(filename);
	if (file.is_open()) {
		while (getline(file, line)) {
			text = text + line + '\n';
		}
		file.close();
	} else
		cout << "Unable to open file";
	return text;
}

vector<string> Parser::parseQuestionsToVector(string text) {
	vector < string > questions;
	size_t bg = 0;
	string pattern1 = "Q.";
	string pattern2 = "A.";
	string singleQuestion;

	while ((text.find(pattern1, bg)) != string::npos) {

		singleQuestion = text.substr(text.find(pattern1, bg),
				text.find(pattern1, bg + 1));
		singleQuestion.erase(singleQuestion.find(pattern2, bg), string::npos);
		questions.push_back(singleQuestion);
		text.erase(text.find(pattern1, bg), text.find(pattern1, bg + 1));
	}
//========================================================
//	for (auto itv : questions) {
//		cout << itv << "\n";
//	}
//	cout << questions.size() << endl;
//========================================================
	return questions;
}

vector<string> Parser::parseAnswersToVector(string text) {

	vector < string > allAnswers;
	string answers;
	string pattern1 = "Q.";
	string pattern2 = "A.";
	size_t bg = 0;

	while ((text.find(pattern1, bg)) != string::npos) {

		text.find(pattern1, bg + 1);
		answers = text.substr(text.find(pattern1, bg),
				text.find(pattern1, bg + 1));
		answers.erase(answers.find(pattern1, bg), answers.find(pattern2, bg));
		text.erase(text.find(pattern1, bg), text.find(pattern1, bg + 1));
		allAnswers.push_back(answers);
	}
//========================================================
//	for (auto itv : allAnswers) {
//
//		cout << itv << "\n";
//	}
//	cout << allAnswers.size() << endl;
//========================================================
	return allAnswers;
}

vector<string> Parser::parseCorrectAnswersToVector(string text) {
	vector < string > correctAnswers;
	string::iterator it;
	string answer;

	for (it = text.begin(); it != text.end(); ++it) {
		if (isalpha(*it)) {
			answer.assign(1, *it);
			correctAnswers.push_back(answer + ".");
		}
	}
//========================================================
//	for (auto itv : correctAnswers) {
//		cout << itv << "\n";
//	}
//	cout << correctAnswers.size();
//========================================================
	return correctAnswers;
}

vector<vector<pair<string, bool>>> Parser::mergeAnswersWithCorrectAnswers(vector<string> answers, vector<string> correctAnswers) {
	vector<vector<pair<string, bool>>> allAnswersWithBool;
	vector<pair<string, bool>> answersWithBool;

	string pattern[] = {"A.", "B.", "C.", "D.", "E."};

	for(unsigned int i=0; i<answers.size(); ++i) {
		string ans = answers.at(i);
		string ansA,ansB,ansC,ansD,ansE;
		string cAns = correctAnswers.at(i);
		size_t A = ans.find(pattern[0]);
		size_t B = ans.find(pattern[1]);
		size_t C = ans.find(pattern[2]);
		size_t D = ans.find(pattern[3]);
		size_t E = ans.find(pattern[4]);
		pair<string,bool> mypair;

		if(B!=string::npos) {
			ansA = ans.substr(A,B);
			answersWithBool.push_back(make_pair(ansA,false));
		}
		if(B!=string::npos && C==string::npos) {
			ansB = ans.substr(B, ans.size() - B);
			answersWithBool.push_back(make_pair(ansB,false));
		}
		if(C!=string::npos) {
			ansB = ans.substr(B, C - B);
			answersWithBool.push_back(make_pair(ansB,false));
		}
		if(C!=string::npos && D==string::npos) {
			ansC = ans.substr(C, ans.size() - C);
			answersWithBool.push_back(make_pair(ansC,false));
		}
		if(D!=string::npos) {
			ansC = ans.substr(C, D - C);
			answersWithBool.push_back(make_pair(ansC,false));
		}
		if(D!=string::npos && E==string::npos) {
			ansD = ans.substr(D, ans.size() - D);
			answersWithBool.push_back(make_pair(ansD,false));
		}
		if(E!=string::npos) {
			ansD = ans.substr(D, E - D);
			answersWithBool.push_back(make_pair(ansD,false));
			ansE = ans.substr(E, ans.size() - E);
			answersWithBool.push_back(make_pair(ansE,false));
		}

		for (unsigned int i = 0; i<answersWithBool.size(); ++i) {
			if(cAns==pattern[i]) {
				answersWithBool.at(i).second = true;
//				cout <<pattern[i]<<boolalpha << answersWithBool.at(i).second;
			}
		}

		allAnswersWithBool.push_back(answersWithBool);

//		cout <<"="<< allAnswersWithBool.size()<<endl;

		answersWithBool.clear();
	}

	return allAnswersWithBool;
}

