/********************************
 * Earl Tankard, Jr.            *
 * Comment Checker              *
 *   This program checks to see *
 *   if the inputted string has *
 *   a valid C-based comment.   *
 ********************************/
#include <iostream>
#include <string>

int main() {
    int i = 0, state = 0;
    std::string comment;

    //get user input
    std::cout << "Enter comment to check:\n";
    getline(std::cin, comment);

    //parse input
    while(i < comment.length()) {
        switch(state){
            //check for start of a comment for '/'
            case 0:
                if(comment[i] == '/') state = 1;
                break;

            //check second character for '*'
            case 1:
                if(comment[i] == '*' && comment[i-1] == '/') state = 2;
                else state = 0;
                break;

            //check for any char; if '*', advance
            case 2:
                if(comment[i] == '*') state = 3;
                else state = 2;
                break;
            
            //check for '/'
            case 3:
                if(comment[i] == '/' && comment[i-1] == '*') state = 4;
                else state = 2;
                break;

            //complete; the string has at least one comment
            case 4:
                break;

        } //end switch
        i++;
    } //end while

    //results
    if (state == 4) std::cout << "Inputted string has a comment within it\n";
    else            std::cout << "Inputted string does not contain any comments\n";
    
    return 0;
} //end main



