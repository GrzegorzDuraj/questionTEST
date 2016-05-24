/* 
 * File:   QestionText.hpp
 * Author: grdu
 *
 * Created on May 19, 2016, 2:26 PM
 */

#ifndef QESTIONTEXT_HPP
#define	QESTIONTEXT_HPP

#include <QString>

struct QuestionText {
public:
    QuestionText(QString quest, QString ans1, QString ans2, QString ans3, QString ans4, char correctAns);
    QuestionText():question(""), 
            answerA(""),
            answerB(""),
            answerC(""),
            answerD(""),
            correctAnswer(0){}
    
    virtual ~QuestionText();
    
    QString question;
    QString answerA;
    QString answerB;
    QString answerC;
    QString answerD;
    
    char correctAnswer;

};

#endif	/* QESTIONTEXT_HPP */

