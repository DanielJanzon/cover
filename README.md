cover
=====

Computes a set (a union of closed intervals) covering the roots of a mathematical function

Basic idea
==========

 - Write an expression parser for interval expressions
 - Transform the expression to an LLVM JIT-compiled function
 - Search for roots using the interval version of Newton's method
 - Support multicore
 - Support functions with several variables

Design goals
============

 - Be really fast
 - Be really easy to use
