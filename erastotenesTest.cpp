
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

#include "erastotenes.h"
#include "gtest/gtest.h"

namespace{
	class ErastotenesTest : public ::testing::Test{
	protected:
		Erastotenes *erast;

		ErastotenesTest(){}

		virtual void SetUp(){
			erast = new Erastotenes(30);
		}
	};

	TEST_F(ErastotenesTest, FirstNumberIsTwo){
		int first = erast->getFirstElementOfList();
		ASSERT_EQ(2,first);
	}

	TEST_F(ErastotenesTest, LasNumberisN){
		int last = erast->getLastElementOfList();
		ASSERT_EQ(30, last);
	}

	TEST_F(ErastotenesTest, MaxNumberIsGreaterThanTwo){
		try{
			Erastotenes *erastbad = new Erastotenes(1);
			FAIL() << "Exception is not being throw when the maximum is less than two";

		}catch(std::range_error &err){}

	}

	TEST_F(ErastotenesTest, TheListGeneratedIsOrderedAndComplete){

		vector<int>::iterator vectorIterator;
		int number = 2;
		for(vectorIterator= erast->getInternalList().begin();
			vectorIterator != erast->getInternalList().end(); ++vectorIterator){
			ASSERT_EQ(number,*vectorIterator);
			number++;
		}
	}

	TEST_F(ErastotenesTest, EvenNumbersCanNotBeStudied){
		list<int> listOfPrimes = erast->findPrimes();
		list<int>::iterator ListIterator;
		ListIterator=listOfPrimes.begin();
		ListIterator++;
		for(; ListIterator != listOfPrimes.end(); ++ListIterator){
			ASSERT_FALSE((*ListIterator % 2)==0);
		}

	}

	TEST_F(ErastotenesTest, CorrectListOfPrimesAfterProcessing){
		list<int> listOfPrimes = erast->findPrimes();
		list<int> idealListOfPrimes;
		idealListOfPrimes.push_back(2);
		idealListOfPrimes.push_back(3);
		idealListOfPrimes.push_back(5);
		idealListOfPrimes.push_back(7);
		idealListOfPrimes.push_back(11);
		idealListOfPrimes.push_back(13);
		idealListOfPrimes.push_back(17);
		idealListOfPrimes.push_back(19);
		idealListOfPrimes.push_back(23);
		idealListOfPrimes.push_back(29);

		ASSERT_TRUE(idealListOfPrimes == listOfPrimes);


	}
}
