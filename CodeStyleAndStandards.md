# Code Style and Standards
## Introduction
This file serves to give a very brief rundown of the style and conventions that were used in this project.
It is not intended to be exhaustive.

**Note**: This document is not intended to in any way convey that one style is more correct than another, this
is just documentation that applies to this project. I've worked under many different styles, and
they all have their merits. If you have further questions about why I chose some
of these rules, I'd be happy to answer. 

## Comments
1. Write comments for anything that is tricky
   - Writing clean code should be self documenting.
1. Comments shall not be written for something a competent C++ programmer with knowledge of the language would find obvious
1. All files shall have at least the following
   - A @file header with the file name.
   - A @author describing the author(s)
   - A brief description of the purpose of the file and what is contained within.
1. Functions must have the following items documented if they apply
   - A brief summary of the functions purpose
   - all parameters
   - return value(s)
   - exceptions

## Use of std namespace
In this project I have avoided using things like `using namespace std;` or even 
 `using std::string;`. The reason
for this is simply that I wasn't using namespaces for anything else, and didn't want to pollute the
current namespace further.

However, this is in some cases, a bit hard to read. I debated back and forth with myself, and just
stuck to the way it started. I could go either way on this rule.

## Indentation
1. I really don't want to start a flame war over this, but this project uses spaces.
1. Any visual indentation that helps readability, is good indentation.
1. All blocks should be indented by 4 spaces.

## Line length
1. Lines should be capped at 120 characters.

## Use of braces
1. All statements should have braces, even an if statement with only one internal statement.
1. All braces should be on their own line.


## Exceptions
1. Use of exceptions are preferred over return codes.

## Preprocessor directives
This section applies to things such as #ifdef / #ifndef

1. All headers should be protected with the proper `#ifndef` / `#define` / `#endif` paradigm not `#pragma once`.
1. The use of #define is very powerful and should be very judiciously used.
1. Ifdefs used to change logic should never be used inside a fuction, instead swap out the whole function.

## Variables
1. Variables and properties shall be lower_case.
1. Variables shall be named a descriptive name.
   - Exceptions may include indexing variables in for loops.
   - However, when in doubt making it clear what that variable does
1. Abbreviations should be avoided, just spell it out whenever possible.
1. Private properties shall begin with an '_', public properties shall not.
1. Pointers shall place the `*` near the type (e.g. `char* name = nullptr;`)
   - After all, the * is part of the type, not the name.
1. Variables shall not be declared on the same line (e.g. `int a, b, c;`)
1. Variables passed by reference will be defined with the `&` closest to the type 
(e.g. `int foo(const int& bar)`);

## Pointers
1. Use `unique_ptr` and `shared_ptr` whenever possible.

## Functions / Methods
1. Functions should be no longer than 100 lines
   - Even then, consider refactoring
1. Functions should attempt to perform one action
1. Functions should take no more than six parameters
   - If more are needed, consider refactoring.
1. Functions should not have more than one nested loop.
1. Functions should be lower_case.
1. Object methods should follow camelCase naming convention.
1. `const` should be used whenever possible

## Classes
1. Class definitions should follow CapitalCase naming convention
1. All functions should be declared in the .hpp file, and defined in the .cpp file.
1. Use of a namespace is optional but should be used judiciously. 
1. `override` should be used whenever an abstract method is overridden to annotate.


## Switch Statements
1. Each case statement should be kept to a few lines of code.
1. Case statements should never create a block.
1. Never put a for loop or any other kind of control statement in a switch statement

## Tests
1. Tests should cover all public interfaces of objects.
1. Tests should cover as much code as possible.
1. All tests will be written before the code it tests
1. Tests do not need the traditional doxygen comments, but will need SOME documentation
describing what they are testing for.

## Enumerations
1. When possible use `class enum` as opposed to old style `enum` to provide type safety.
1. Avoid providing specific values or types to enumerations
1. If it's necessary to provide specific values to types, provide them to all of them, not just some.  
   Example:  
   ```c++
   // OK  
   class enum {  
    ICE_MAN,  
    GOOSE, 
    MAVERICK
   };
   
   // OK
   class enum {    
     ICE_MAN  = 0,
     GOOSE    = 1, 
     MAVERICK = 2
   };
   
   // NOT OK
   class enum {    
     ICE_MAN  = 0,
     GOOSE, 
     MAVERICK 
   };
   
   // WORSE
   class enum {    
     ICE_MAN  = 0,
     GOOSE, 
     MAVERICK = 5, 
   };
   ```

