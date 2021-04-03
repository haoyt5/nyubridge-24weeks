# Week 12

## Agenda

This week we will be studying object oriented programming including the design of classes, constructors, destructors, copy constructors, operator overloading (including the assignment operator), inheritance and polymorphism. 

Object orientation came about in the mid-1980s as a concept to keep data and the functions to work on the data together.  Since then, a lot of development has been done and today object orientation is expected in a lot of situations.  Java, for example, is a purely object-oriented language; everything is an object!

For this week, please do the following:

- Read “Problem solving with C++” by Walter Savitch, chapters 10 and 11
- Be able to answer all of the self-test exercises in the chapters
- Attend the weekly webinar (Thursday 8:00 pm). This week we will be discussing solving problems with pointers and dynamic storage as well as debugging problems with pointers.
- Review the sample code and lecture notes for the CS2124 website listed below. (http://cis.poly.edu/jsterling/cs2124/)

## Objectives
By the end of this week, you should:

- Be able to define classes and use them properly
- Understand “encapsulation”
- Understand Public, Private and Protected
- Be able to overload the following operators: +,-,++,--,*,*=,<<,>>,<,=,[]
- Understand the Big 3 and when they are needed
- Understand when to implement as a member, non-member friend and non-member non-friend

## Assignment


```
CH12 #7: Write a checkbook balancing program. The program will read in, from the console, the following for all checks that were not cashed as of the last time you balanced your checkbook: the number of each check (int), the amount of the check (double), and whether or not it has been cashed (1 or 0, boolean in the array). Use an array with the class as the type. The class should be a class for a check. There should be three member variables to record the check number, the check amount, and whether or not the check was cashed. The class for a check will have a member variable of type Money (as defined on page 662 in the book; Display 11.9) to record the check amount. So, you will have a class used within a class. The class for a check should have accessor and mutator functions as 
well as constructors and functions for both input and output of a check.  In addition to the checks, the program also reads all the deposits (from the console; cin), the old and the new account balance (read this in from the user at the console; cin). You may want another array to hold the deposits. The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.

The program outputs the total of the checks cashed, the total of the deposits, what the new balance should be, and how much this figure differs from what the bank says the new balance is. It also outputs two lists of checks: the checks cashed since the last time you balanced your checkbook and the checks still not cashed. [ edit: if you can, Display both lists of checks in sorted order from lowest to highest check number.]
```