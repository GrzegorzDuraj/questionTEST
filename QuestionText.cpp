/* 
 * File:   QestionText.cpp
 * Author: grdu
 * 
 * Created on May 19, 2016, 2:26 PM
 */

#include "QuestionText.hpp"

QuestionText::QuestionText(QString quest, QString ans1, QString ans2, QString ans3, QString ans4, char correctAns):
            question(quest), 
            answerA(ans1),
            answerB(ans2),
            answerC(ans3),
            answerD(ans4),
            correctAnswer(correctAns)
{
}



QuestionText::~QuestionText()
{
}

