# BankersAlgorithm
Thomas Denvir - April 28th 2023

This Readme file is used as a description of what this file should've been, and why it isn't that.

This file is supposed to describe the Bankers Algorithm, an algorithm based around managing resources to processes 
while attempting to prevent deadlock. This can be done by creating a set of 2D vectors for Allocating, the Max amount of
use for a resource, and a vector of what is still needed to complete the task. 

There are comments in the code saying why I did certain things in certain locations which could give a nice idea as to how this
is supposed to function.

Due to what I can only presume is issues with my code I cannot see why this file won't compile. I am not the best when it comes
to C++, as I don't program with it often. I rewrote this code 3 times, each time taking away areas that would most likely cause 
this. I removed the input file and replaced it with 2D vectors in the file, I removed the automatic requesting/releasing function
and replaced it with much simpler hard coded values. Nothing seems to have worked.

Everytime I would attempt to compile, it would crash the terminal I was using. I wasn't able to find a bash file
with what the errors were, only long random strings of text. I would say it is an issue with my device, but compiling 
previous files works fine. 

If I were to guess what was wrong, it is most likely how I wrote my 2D vectors, and how I wrote my need + generateNeed functions.
As for specifics, I am unsure. It could be as simple as an unsigned integer issue.

If anyone is able to see what exactly is wrong with this file, it would be greatly appreciated if you would let me know.
Thank you.
