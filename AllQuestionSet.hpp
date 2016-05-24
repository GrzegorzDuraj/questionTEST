/* 
 * File:   AllQuestionSet.hpp
 * Author: grdu
 *
 * Created on May 23, 2016, 5:07 PM
 */

#ifndef ALLQUESTIONSET_HPP
#define	ALLQUESTIONSET_HPP

#include <vector>
#include <random>


#include "Question.hpp"

class AllQuestionSet {
public:
    AllQuestionSet();
    virtual ~AllQuestionSet();
    
    Question  getNewQuestioin();
private:
    std::vector<Question> allQestion;
    std::mt19937 mt;
   // std::uniform_int_distribution<int> distQuestions;


};

#endif	/* ALLQUESTIONSET_HPP */

