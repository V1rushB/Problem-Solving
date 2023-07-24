# << Here's a list of problems to practice JavaScript >>  
- CPP is surely still preferable to solve problems lol
- this list is not yet complete, its main purpose is not compititve programming but more like a practise to JavaScript.
- Sources: these problems were found either on codeforces or generated on chatgpt-4. => leetcode/atcoder problems will be added in the future inshaa'allah.
- in addition to all of these problems, we can't just forget freecodecamp.org.
- here is a [direct link to its problems](https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/basic-javascript/)
  - this will change in the future but this list will include some problems on the following topics:
        - Asynchronous Programming. -> since it's really annoying.
    ### < Topics > 
        - Closure
        - Two Pointers Approach -> also will include both sliding window and dynamic sliding window.
        - DP -> Will include some very easy DP problems which also will have the goodie prefix sum approach.
        - Greedy algorithms
        - Recursion
        - Graph alrgorithms => includes BFS, DFS & DSU => not too many problems, maybe more in the future?
        - Backtracking => the known exhausting dfs (bruteforce).
        - Binary search => nothing too hard
        - Frequencey Arrays => not really a topic but it's nice to know lol
        - String manipulation
        - Bit manipulation
        - more commin' up in the future inshaa'allah.

  ## <  Asynchronous Programming >
  - Implement a function that fetches user data from an API and then fetches another set of data from another API using the data from the first API call. Handle error cases where the API call fails.
  - Create a function that can download a list of URLs, but only allows 5 downloads at a time.
  - Build a function that sends a request to an API endpoint. If the request fails, it should automatically retry sending the request until it succeeds or has attempted to send the request a certain number of times.
  - Create a function that chains multiple promises together in a sequence.
  - Create a simple event emitter system where an event can be emitted at any time, and any number of callbacks can be executed when the event is emitted.
 
  ## < Two Pointers >
  - Given a sorted array and a target sum, find all pairs in the array that add up to the target sum and return their indecies.
  - [Ternary String](https://codeforces.com/contest/1354/problem/B)
  - Given an array of n distinct elements, sort the array in ascending order.
  ### < Static/Dynamic Sliding Window >
  - Given an array of integers, find the maximum sum you can get from a subarray of length k.
  - Given a string and a set of characters, find the smallest substring that contains all the characters in the set.
  - Given a string, find the length of the longest substring without repeating characters.
  - Given a string s and a string t, find the minimum window in s which will contain all the characters in t.
  - [Maximum Subarray Sum](https://cses.fi/problemset/task/1643)
  - [Subarray Sums I](https://cses.fi/problemset/task/1660)
  - [Easter Eggs](https://codeforces.com/problemset/problem/78/B)
  - [Choosing Teams](https://codeforces.com/problemset/problem/432/A)

 
  ## < DP => (Dynamic Programming)  (Mind storming, dont start if ur not very well-prepared.)>
  three problems in the `Dynamic Programming` File.
  -  Implement a function to compute the nth Fibonacci number
  -  Given an array of integers, find the total sum of all elements between indices i and j.
  -  Given an array, find a subarray (continous sequence) with sum equal to a given target.
  -  Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
  -  Find the total number of sub-arrays that have sum equals to k.
  - Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`
  - Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path. You can only move either down or right at any point in time.
  - Without using recursion, make a Function that finds the longest increasing sequence (LIS).

    Before dealing with Dynamic Programming problems and think with them like a real dp, first do a tracing using dfs backtracking and try to imporve the solution a bit by bit.
 
  ## < Greedy Algorithms >
  - Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
  - Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the numbers in the original array except nums[i]. Solve it without division and in O(n).
 
  ## <maping problems, frequencey array problems>
  - Given an array of integers, count the frequency of each integer and return the integer with the highest frequency.
  - Given a string, count the frequency of each character in the string. Return the character with the highest frequency.
  - Given an array of integers and a target sum, find the number of subarrays that add up to the target sum.
  - Given an array of integers, find the subarray with the largest sum. Return the sum.
  - Given an array of integers and a target sum, find two integers in the array that add up to the target sum.
  - Extend the previous problem to return all pairs of integers that add up to the target sum.
  - Given an array of integers, find all elements that appear more than once in the array.
  - Extend the problem above to find the element that appears the most times in the array.
  - Given an array of integers, find the first element that appears only once in the array.
  - Extend the problem above to find all elements that appear only once in the array.
  - Given an array of integers and an integer K, find the total number of continuous subarrays whose sum equals to K.
  - Given an array of integers and a number K, find the number of pairs of integers in the array whose difference is K.
  - Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.
  - Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
  - Given a string, sort it in decreasing order based on the frequency of characters.
  - Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K. Return the number of good subarrays of A.

  ## < Closure >
  - Implement a function factory. This function should take in a number and return a function that adds that number to any other number it is given.
  - Implement a function that creates an object with a particular prototype or extends an existing object with new methods, encapsulating these methods using closures.
  - Create a Person object constructor that takes a name and age. The age property should not be directly accessible from outside the object (it should be private). Implement methods for getting and setting the age using closures to access the private age property.
  - Implement a module pattern with closures to create private state within objects. This can be a counter object, a bank account object, etc.
  - Implement a recursive function to calculate Fibonacci numbers and use a closure to cache the results of each Fibonacci number as you compute them.
  - Create a generic memoization function that takes a function as an argument and returns a memoized version of the function.
  - Implement a button click tracker, which keeps track of the number of times a button is clicked. Store the click count in a closure so it is not directly accessible from the global scope.
  - Write a function that handles clicks on multiple elements on a webpage. This function should use closures to keep track of information related to each individual element (like how many times it has been clicked).
  - Create a custom iterator over a collection of items. Use a closure to keep track of where you are in the collection.
  - Implement a simple generator function (a function that can be exited and later re-entered, with context (variable bindings) being saved across re-entrances) using closure.
  - Implement a throttle function. This function should limit the number of times a given function can be called.
  - Implement a debounce function. This function should prevent a particular function from being called until after a certain amount of time has passed since it was last called.
  - Implement a module using an Immediately Invoked Function Expression (IIFE) to provide private scoping. Use closure to maintain state between function calls.
  - Create a function that starts counting from a given number and logs the count every second in the console. The count should stop at zero. Use closure to keep track of the count.
  - Implement your own version of JavaScript's bind method using closures.


