#include "pch.h"
#include "../Priority Queue/priorityqueue.h"
#include <gtest/gtest.h>

/*
Test cases for program using Google Testing
*/



TEST(priorityqueue, Size) {
  
	priorityqueue <int> s;
	EXPECT_EQ(s.Size(), 0);
}

TEST(priorityqueue, enqueue_string) {
	priorityqueue <string> s;

	s.enqueue("Haley", 2);
	s.enqueue("Sarah", 1);


	EXPECT_EQ(s.Size(), 2);
}

TEST(priorityqueue, enqueue_int) {
	priorityqueue <int> s;

	s.enqueue(10, 2);
	s.enqueue(11, 1);


	EXPECT_EQ(s.Size(), 2);
}

TEST(priorityqueue, enqueue_multipleString) {
	priorityqueue <string> s;

	s.enqueue("Haley", 2);
	s.enqueue("Sarah", 1);
	s.enqueue("Mary", 3);
	s.enqueue("Joe", 5);
	s.enqueue("Tom", 6);


	EXPECT_EQ(s.Size(), 5);
}


