Elevator Project
=============================
Simple OO elevator with a single user to practice c++. User has the choice to create an elevator of different size and traverse floors.
The top floor can be password protected with the user entering a password which is hashed and stored in a file.
If user attempts to access the restricted floor, the file is read and compared to the hashed user input to decide whether access should be granted.
Throughout the program all actions are logged in logs/Elevator.log file.

Compile in OS X terminal with:
> g++ *.cpp easylogging++.cc -o elevatorProgram -std=c++11

**The main lessons learned for the project were:**
- Creating and a following a plan on how to develop functionality
- Implementing and understand how classes work
- Implementing basic linear physics for traversing elevator
- Organizing the project into different files without linking errors
- Interfacing with an external libary, easylogging++, getting compiling to work both in Xcode and from terminal
- Trying to adhere to the Google c++ style guide

Possible improvements would be to look into memory management. Intuitively the vector push_back when creating elevatorFloors could potentially be dangerous,
but I could not find information about push_back being dangerous when vector is expanded or examples of how to test for successful memory allocation it during initialization.

--------

MIT License

Copyright (c) 2018 feirik

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
