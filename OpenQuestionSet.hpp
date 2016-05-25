/* 
 * File:   OpenQuestionSet.hpp
 * Author: grdu
 *
 * Created on May 20, 2016, 9:56 AM
 */

#ifndef OPENQUESTIONSET_HPP
#define	OPENQUESTIONSET_HPP

#include <vector>
//#include "Question.hpp"
#include "Parser/question.h"

#include "AllQuestionSet.hpp"
#include <random>
#include <tuple>

class OpenQuestionSet {
public:
    OpenQuestionSet();
    virtual ~OpenQuestionSet();
    Question& getQuestion();
    
    void promoteAnswer(bool );
   
private:
    std::vector< Question > openQuestion;
    std::mt19937 mt;
    int sizeOfOpenQuestion;
    std::uniform_int_distribution<int> distQuestions;
    int currentNumberQuestion;

    void mixStructureOfQuestion(Question &q);
    
    void openNewQuestion();
    
    AllQuestionSet * allQuestionSet;
};

#endif	/* OPENQUESTIONSET_HPP */

