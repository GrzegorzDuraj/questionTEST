/* 
 * File:   OpenQuestionSet.cpp
 * Author: grdu
 * 
 * Created on May 20, 2016, 9:56 AM
 */

#include "OpenQuestionSet.hpp"
#include <utility>
#include <QDebug>

OpenQuestionSet::OpenQuestionSet() :
        mt(time(0)), // 1931 - deterministic 32-bit seed for 
        sizeOfOpenQuestion(7),
        distQuestions(0, sizeOfOpenQuestion - 1),// distribution for Random Questions
        allQuestionSet(new AllQuestionSet)
{
    for (int i = 0 ; i < sizeOfOpenQuestion; ++i)
    {
        openNewQuestion();
    }
}

OpenQuestionSet::~OpenQuestionSet()
{
}

Question& OpenQuestionSet::getQuestion()
{

    currentNumberQuestion = distQuestions(mt);
    qDebug() << openQuestion.size();
    qDebug() << "numer pytania " <<  openQuestion.at(currentNumberQuestion).getQuestionNumber();
    qDebug() << "liczba odpowiedzi " << openQuestion.at(currentNumberQuestion).getAnswerVector().size();
    qDebug() << "Current qustion " << currentNumberQuestion;
    //qDebug() << "Current  " <<  openQuestion.at(currentNumberQuestion).;

    Question &questionToMix = openQuestion.at(currentNumberQuestion);
    
    mixStructureOfQuestion(questionToMix);
    return questionToMix;
}

void OpenQuestionSet::mixStructureOfQuestion(Question &questionToMix)
{

    int sizeOf = questionToMix.getAnswerVector().size();
    std::uniform_int_distribution<int> distAns (0, sizeOf-1 );
   
    for (int i = 10 ; i >= 0 ; --i )
    {
        int random1 = distAns(mt);
        int random2 = distAns(mt);
        swap(questionToMix.getAnswerVector().at(random1), questionToMix.getAnswerVector().at(random2))  ;
    }
}

void OpenQuestionSet::promoteAnswer(bool ifCorrect)
{
    Question &q = openQuestion.at(currentNumberQuestion);
    q.increaseAttempt();
    if (ifCorrect)
        q.increaseCorrectAnswer();
    
    if (q.getCorrectAnswer() > 3 ){
       // openQuestion.erase(std::remove (openQuestion.begin(), openQuestion.end(), currentNumberQuestion),  openQuestion.end()  );
        qDebug() << "Remove Question " << currentNumberQuestion;
        openQuestion.erase(openQuestion.begin() + currentNumberQuestion);
        openNewQuestion();

    }
        
}

void OpenQuestionSet::openNewQuestion()
{
    Question q = allQuestionSet->getNewQuestioin();
    if (q.getQuestion().empty())
    {
        sizeOfOpenQuestion--;
    }
    else
    {
        openQuestion.push_back(q);
    }

}