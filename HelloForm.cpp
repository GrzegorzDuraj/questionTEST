/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "HelloForm.h"
#include <QString>
#include <qt5/QtCore/qdebug.h>
#include "OpenQuestionSet.hpp"
#include <QDebug>


HelloForm::HelloForm():
        openQuestionSet(new OpenQuestionSet())
{
    widget.setupUi(this);

    defaultPalatte = widget.question->palette();
    paletteBlue = widget.answer_1->palette();
    paletteBlue.setColor(QPalette::Window, QColor(Qt::yellow));

    paletteRed = widget.answer_1->palette();
    paletteRed.setColor(QPalette::Window, QColor(Qt::red));
   

    vecAnsLayout.push_back(widget.answer_1);
    vecAnsLayout.push_back(widget.answer_2);
    vecAnsLayout.push_back(widget.answer_3);
    vecAnsLayout.push_back(widget.answer_4);
    vecAnsLayout.push_back(widget.answer_5);
    resetViewTextLabel();
    
    vecAnsCheckBox.push_back(widget.checkBox_1);
    vecAnsCheckBox.push_back(widget.checkBox_2);
    vecAnsCheckBox.push_back(widget.checkBox_3);
    vecAnsCheckBox.push_back(widget.checkBox_4);
    vecAnsCheckBox.push_back(widget.checkBox_5);
    resetViewCheckBox();
 
    connect(widget.closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(widget.check, SIGNAL(clicked()), this, SLOT(checkMethod()));
    connect(widget.next, SIGNAL(clicked()), this, SLOT(nextQuestion()));
    
    currentQuestion = openQuestionSet->getQuestion();
    fullFillTextWidget();
}

HelloForm::~HelloForm()
{
}

void HelloForm::checkMethod()
{

    setColorOnTextLabel();
    bool check = checkAnswer();
    
    openQuestionSet->promoteAnswer(check);
    
    if(check)
        widget.labelCorrect->setText("hip hip hurra !!" );
    else 
        widget.labelCorrect->setText("bad luck...");
    
    fullFillTextWidget();
}

void HelloForm::nextQuestion()
{
    for (auto & radioButton : vecAnsLayout)
    {
        radioButton->setPalette(defaultPalatte);
    }
    
    currentQuestion = openQuestionSet->getQuestion();

    resetViewCheckBoxSetChecked();
    fullFillTextWidget();
}

void HelloForm::setColorOnTextLabel()
{

    for (auto & textLayout : vecAnsLayout)
    {
        textLayout->setPalette(paletteRed);
    }
    
    int i = 0; 
    for (auto & blueForegrand : currentQuestion.getAnswerVector() )
    {
        qDebug () << blueForegrand.first.c_str() << "  ";
        qDebug() << blueForegrand.second << "\n";
        if (blueForegrand.second == true ) 
        {
            vecAnsLayout.at(i)->setPalette(paletteBlue);
        }
        ++i;
    }
    
}

void HelloForm::fullFillTextWidget()
{
    resetViewTextLabel();
    resetViewCheckBox();

    int i = 0 ; 
    for (auto  currQ : currentQuestion.getAnswerVector())
    { 
        vecAnsCheckBox.at(i)->setVisible(true);
        vecAnsLayout.at(i)->setVisible(true);
        vecAnsLayout.at(i)->setText( currQ.first.c_str() );
        ++i;
    }
    
    widget.question->setText( QString (currentQuestion.getQuestion().c_str()) );
    
    widget.correctAns->setText(QString ("Given correct answer ") +
            std::to_string (currentQuestion.getCorrectAnswer()).c_str()  );
    widget.attemptLabel->setText(QString ("Attempt number ") +
            std::to_string (currentQuestion.getAttempt()).c_str() );
    widget.numerPyt->setText(QString ("NUmer Pytania ") +
            std::to_string (currentQuestion.getQuestionNumber()).c_str() );

}

bool HelloForm::checkAnswer()
{

    bool correct = false;
    size_t i = 0;
    int counterForTrueAnwser = 0;
    int counterForTrueAnswered = 0; 

    for (; i<currentQuestion.getAnswerVector().size(); ++i)
    {
        if (vecAnsCheckBox.at(i)->isChecked() ) 
        {
           ++counterForTrueAnwser;
           if (currentQuestion.getAnswerVector().at(i).second==true)
           {
               correct = true;
           }
           else 
           {
               correct = false; 
               break;
           }
        }
        
    }
    for (auto a: currentQuestion.getAnswerVector())
    {
        if (a.second) ++counterForTrueAnswered;
    }
    if (counterForTrueAnwser != counterForTrueAnswered) correct = false;
    
    return correct;
}
void HelloForm::resetViewCheckBox()
{
    for (auto & checkBox : vecAnsCheckBox)
    {
        checkBox->setAutoFillBackground(true);
        checkBox->setVisible(false);
    }
    
}


void HelloForm::resetViewCheckBoxSetChecked()
{
    for (auto & checkBox : vecAnsCheckBox)
    {

        checkBox->setChecked(false);
    }
    
}

void HelloForm::resetViewTextLabel()
{
    for (auto & textLabel : vecAnsLayout)
    {
        textLabel->setAutoFillBackground(true);
        textLabel->setVisible(false);
    }
    
}