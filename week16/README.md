## Agenda

This week we will be concentrating on data structures and in doing so, switching books to the Mark Allen Weiss “Data Structures And Algorithm Analysis in C++” book.  If you feel you need some more practice with C++ or algorithm analysis, the first two chapters of this book are a good review.  For the readings, chapter 3 contains a lot of other information which we’ve already covered, but would be a good review if you need it.  I’ll assign sections 3.6, 3.7

For this week:

- View the videos on Stacks and Queues
- Read sections 3.6, 3.7
- Join the Thursday 8:00 Pm webinar, or view it on Thursday after the event. 

## Objective
The data structures we’re discussing this week is Stacks and Queues.  Ultimately, we’d like you to be able to understand who these fundamental data types work and are used in Computer Science.

At the end of the week, you should be able to:

- Understand how a stack is designed
- Understand how a queue is designed
- Be able to choose an appropriate data structure for a task.

## Assignment
1. Implement a symbol balance checker function for the Pascal programming language.  Pascal allows for the following pairs: {}, (), [], begin end .  All programs will begin with the word "begin" and end  with the word "end".  Your function should receive an ifstream object which is already open and will return true, all of the symbols match, or false, they do not.  You do not have to worry about comments in the program but you do have to avoid other parts of the program's code such as assignment statements (x=y) and other expressions.  

2. Although a queue is "best" implemented with a list, it can be implemented with a vector if you take into account the starting position of the queue.  For example, if five elements are pushed onto the queue, the start of the queue is at position zero and the end is at position 4.  If we, then, pop two elements, the start would be at position 2 and the end at position 4.  The two "popped" elements are not really removed from the vector, and that avoids the O(N) time problem for the pop function.
Implement a class which uses a vector to store the queue.  Be mindful of performance, such that if the queue is empty, the size of the underlying vector is "reset."