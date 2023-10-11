# count-and-rewrite
A text file contains only alphabetic characters, numeric characters, punctuation characters (. , ; : ! ? ’),
spaces and ‘\n’ characters.
Write a C program that generates a second file containing the same text of the input one, modified as
follows:
• Replace all the numerical characters with ‘*’.
• Add a space after each punctuation character (unless it is already followed by a space or a ‘\n’ or
another punctuation character).
• Make sure that the first alphabetic character after either a ‘.’, a ‘!’ or a ‘?’ character is uppercase (even
if there are spaces or ‘\n’ characters in between). If it is a lowercase character, transform it to
uppercase.
• Each line should be of 25 characters maximum, without considering the ‘\n’. If a line is longer than
25, it needs to be truncated after exactly 25 characters (it does not matter if this splits a word into
two).
• To align the text, add spaces at the end of each line that is shorter than 25 (as many they are needed
to reach the fixed 25 characters length)
• Each line should end with a printout of the number of characters of the corresponding line in the
original file, in the format: “ | c:%d \n” (see example below).
The names of the files are constant (“input.txt” and “output.txt”) defined with #define.
