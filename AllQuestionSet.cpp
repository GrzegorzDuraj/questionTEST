/* 
 * File:   AllQuestionSet.cpp
 * Author: grdu
 * 
 * Created on May 23, 2016, 5:07 PM
 */

#include "AllQuestionSet.hpp"
#include <QDebug>

AllQuestionSet::AllQuestionSet():
        mt(time(0)) //deterministic 32-bit seed for 


{
    Question q1;
    q1.question = "pytanko ... PP";
    q1.vec.push_back(std::make_pair("zla", false));
    q1.vec.push_back(std::make_pair("dobra", true));
    q1.vec.push_back(std::make_pair("bardzo zla ", false));
    q1.vec.push_back(std::make_pair("tez dobra", true));
    q1.numerpytania = 1; 
    q1.attempt = 0; 
    q1.correctAns = 0 ; 
 
    Question q2;
    q2.question = "pytanko ... @3423 ";
    q2.vec.push_back(std::make_pair("dobra", true));
    q2.vec.push_back(std::make_pair("zla", false));
    q2.vec.push_back(std::make_pair("bardzo nie dobra", false));
    q2.vec.push_back(std::make_pair("bardzo zla ", false));
    q2.vec.push_back(std::make_pair("super zla", false));
    q2.numerpytania = 2; 
    q2.attempt = 2; 
    q2.correctAns = 2; 
    
    for (int i = 0 ; i < 350 ; i = i+2){
        q1.numerpytania = i; 
        q2.numerpytania = i+1; 

        allQestion.push_back(q1);
        allQestion.push_back(q2);
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
