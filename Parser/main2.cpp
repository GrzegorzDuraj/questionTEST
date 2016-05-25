//#include "parser.h"
//#include "question.h"
//#include<iostream>
//#include<vector>
//#include<utility>
//
//using namespace std;
//int main() {
//
//	Parser parser;
//
////Pobieramy tekst z plikow i wkladamy do private member stringow parsera
//	parser.setTestContent(parser.getTextFromFile(Parser::fileWithTest));
//	parser.setAnswerContent(parser.getTextFromFile(Parser::fileWithAnswer));
//
////Wrzucamy same pytania do wektora
//	vector < string > questions = parser.parseQuestionsToVector(
//			parser.getTestContent());
//
////Wrzucamy odpowiedzi do wektora
//	vector < string > answers = parser.parseAnswersToVector(
//			parser.getTestContent());
//
////Wrzucamy prawidlowe odpowiedzi do wektora
//	vector < string > correctAnswers = parser.parseCorrectAnswersToVector(
//			parser.getAnswerContent());
//
////Mergujemy odpowiedzi z prawidlowymi odpowiedziami do wektora z wektorami par
//	vector < vector<pair<string, bool>>> mergedAnswers =
//			parser.mergeAnswersWithCorrectAnswers(answers, correctAnswers);
//
//	vector < Question > vQ;
//
//	for (unsigned int i = 0; i < questions.size(); ++i) {
//		Question question(questions.at(i), i + 1, mergedAnswers.at(i), 0, 0);
//		vQ.push_back(question);
//	}
//
//	cout << "Rozmiar wektora z obiektami Question: " << vQ.size() << endl;
//	cout << vQ.at(111).getQuestionNumber() << endl;
//	cout << vQ.at(111).getQuestion();
//	cout << vQ.at(111).getNumberOfAnswer() << endl;
//	cout << vQ.at(111).getAttempt() << endl;
//	cout << vQ.at(111).getCorrectAnswer() << endl;
//	cout << vQ.at(111).getAnswer(3);
//
//	return 0;
//}
