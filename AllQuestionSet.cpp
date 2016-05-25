/* 
 * File:   AllQuestionSet.cpp
 * Author: grdu
 * 
 * Created on May 23, 2016, 5:07 PM
 */

#include "AllQuestionSet.hpp"
#include <QDebug>
#include "Parser/parser.h"

AllQuestionSet::AllQuestionSet():
        mt(time(0)) //deterministic 32-bit seed for 


{
   
	Parser parser;

//Pobieramy tekst z plikow i wkladamy do private member stringow parsera
	parser.setTestContent(parser.getTextFromFile(Parser::fileWithTest));
	parser.setAnswerContent(parser.getTextFromFile(Parser::fileWithAnswer));

//Wrzucamy same pytania do wektora
	std::vector < std::string > questions = parser.parseQuestionsToVector(
			parser.getTestContent());

//Wrzucamy odpowiedzi do wektora
	std::vector < std::string > answers = parser.parseAnswersToVector(
			parser.getTestContent());

//Wrzucamy prawidlowe odpowiedzi do wektora
	std::vector < std::string > correctAnswers = parser.parseCorrectAnswersToVector(
			parser.getAnswerContent());

//Mergujemy odpowiedzi z prawidlowymi odpowiedziami do wektora z wektorami par
	std::vector < std::vector<std::pair<std::string, bool>>> mergedAnswers =
			parser.mergeAnswersWithCorrectAnswers(answers, correctAnswers);

        int a = questions.size();
	for (unsigned int i = 0; i < questions.size(); ++i) {
		//Question question(questions.at(i), i + 1, mergedAnswers.at(i), 0, 0);
		allQestion.push_back(Question (questions.at(i), i + 1, mergedAnswers.at(i), 0, 0));
        

	}
        for (auto a : mergedAnswers){
            
       
            for( auto b: a){
                  qDebug () << b.first.c_str() << " " << b.second;; 

//                 qDebug () <<  
            }

     }
}


AllQuestionSet::~AllQuestionSet()
{
}

Question AllQuestionSet::getNewQuestioin()
{
    
    int sizeOf = allQestion.size();
    if ( sizeOf > 0 ){

        std::uniform_int_distribution<int> distQuestions(0, sizeOf - 1);// distribution for Random Questions
        int random1 = distQuestions(mt);
        qDebug() << "nowe pytanie numer " <<  random1;
           
        Question q  = allQestion.at(random1);
         
        allQestion.erase(allQestion.begin() + random1);
          
        return q;
      
    }
    else 
        // throw ("done");
        return Question() ;

}
