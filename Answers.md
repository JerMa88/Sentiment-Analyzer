# Assignment 2: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Jerry Ma

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## UML Diagram

Add your UML class diagram here.

Replace the following image with your diagram. You can draw it by hand and take a photo.
![UML Class Diagram](UML_class.png)

## Answers

1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.

   > The training of the model involves cleaning special characters, lowering capitalized characters and finally stemming each word in a tweet. The sentiment of each word is stored as a private integer value in DSString; the train() function reads the training tweet file, process through each word separated by ' ' in each tweet, then increment the sentiment value of a word each time the word appears in a positive tweet. each processed and trained DSString is stored into a std::vector, accessible for the test() function. 

2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Remember that training includes reading the tweets, breaking it into words, counting, ... Explain why you get this complexity (e.g., what does `N` stand for and how do your data structures/algorithms affect the complexity).

   > Training takes about 5 seconds. The time complexity of my training implementation is O(n^2), while "n" stands for the total number of words in the train file. In training, the reading and processing each word takes linear time (n), and the search of each word from the existing trained words in the std::vector to increment the sentiment of the found word or to add a new word, which is at most n words. So the exact time complexity of the training algorithm is O(0.5 * n(n+1)). Adding time complexity for remove special char, to lower case, stemming, O(0.5 * n(n+1) + 3n), which is still the classic quadratic O(n^2) time complexity.

3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.

   > Testing (classification) takes about 9 seconds. The time complexity of my testing implementation is O(n * m), while "n" stands for the total number of words in the trained data, and "m" stands for the total amount of words in the test tweet file. In testing, the reading and processing each word takes linear time (m), and the search of each word from the existing trained words in the std::vector to search if a word in test file exist in the trained data, which has n words. So the exact time complexity of the training algorithm is O(0.5 * m(n+1)). Adding time complexity for remove special char, to lower case, stemming, O(0.5 * m(n+1) + 3n), which is still the classic quadratic O(n * m) time complexity.

4. How do you know that you use proper memory management? I.e., how do you know that you do not have
   a memory leak?

   > By running valgrind, the code does not have a memory leak. (The 1st pasted block is valgrind result of ./test_DSString; the 2nd is ./sentiment)
   ==45051== 
==45051== HEAP SUMMARY:
==45051==     in use at exit: 0 bytes in 0 blocks
==45051==   total heap usage: 35 allocs, 35 frees, 72,980 bytes allocated
==45051== 
==45051== All heap blocks were freed -- no leaks are possible
==45051== 
==45051== For lists of detected and suppressed errors, rerun with: -s
==45051== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

   ../build/sentiment ../data/train_dataset_20k.csv ../data/test_dataset_10k.csv ../data/tested_output.csv ../data/tested_output.csv ../data/test_dataset_sentiment_10k.csv==44869== 
==44869== HEAP SUMMARY:
==44869==     in use at exit: 0 bytes in 0 blocks
==44869==   total heap usage: 1 allocs, 1 frees, 72,704 bytes allocated
==44869== 
==44869== All heap blocks were freed -- no leaks are possible
==44869== 
==44869== For lists of detected and suppressed errors, rerun with: -s
==44869== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



5. What was the most challenging part of the assignment?

   > Your answer