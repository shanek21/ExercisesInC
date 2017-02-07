# Reflection 1

## Written Reflection

### Learning Goals

I began sprint 1 with a few goals, mostly centered around the nitty gritty of embedded programming. I specifically wanted to learn about low-level C and how to push code to an Arduino without the Arduino IDE. This past sprint, my team and I have worked towards creating a sound out of an arduino-powered speaker, which hit all of my learning goals quite well. I was able to do a great balance of both research about how programming an Arduino works at the lowest level and implementation of programming an Arduino without the Arduino IDE.

### Teaming and Scrum

My team and I have been making great use of scrum as a workflow management strategy. We haven't made any adaptations to the teaching team's suggested eduScrum methods. Everything has been kept up to date and our Trello has made sure that we always know what we finished doing, what we are doing, and what we are about to do. Though I always did the readings before the lectures, I got behind on the exercises and reading questions, which I regret and will make sure to stay on track with those next sprint - especially for the sprint review. I only retroactively realized how much thinking about the reading questions would have helped with the sprint review. Our team morale is doing well, though a team member just recently decided to drop the class. We should be able to stay mostly on track with hopefully no adjustments or some minor re-scoping.

### Our Project: Arduino Synthesizer

With lots of research to keep us busy, I have felt like our project has moved along at a decent pace thus far. We now have a very minimal MVP working on an Arduino and understand the compiling and upload process without an IDE. I am slightly concerned that we have not yet been able to break this project into digestable pieces yet, but hopefully we will make some progress on that planning soon.

## Head First C Exercises

For sprint 1, my team read through and completed the exercises for chapters 1, 2, and 2.5.

[Exercise 1](https://github.com/shanek21/ExercisesInC/tree/master/exercises/ex01)

[Exercise 2](https://github.com/shanek21/ExercisesInC/tree/master/exercises/ex02)

[Exercise 2.5](https://github.com/shanek21/ExercisesInC/tree/master/exercises/ex02.5)

## ThinkOS Reading Questions

For sprint 1, my team read through and completed the reading questions for chapters 1, 2, and 3.

[Reading Questions for Chapters 1, 2, and 3](https://github.com/shanek21/ExercisesInC/blob/master/reading_questions/thinkos.md)

## Exam Question

### Question

When initializing a character array  that will store a three letter word, why might the initialization look like `char word[4];` instead of `char word[3];`? What is the purpose of this?

### Solution

Even though the array only needs three spaces for the characters of the word, there needs to be room to store a sentinel character (sometimes called a NULL pointer) as the last element to signify the end of the array.
