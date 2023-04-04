#include <iostream>
#include <regex>


int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int minimumChange(std::string s) {
    const std::regex patternRepeat("(.)\\1{2,}"); // regex for matching repetitive groups of the same character
    const std::regex patternLowercase("(.*[a-z].*)"); // regex that matches any string that contains at least one lowercase letter
    const std::regex patternUppercase("(.*[A-Z].*)"); // regex that matches any string that contains at least one uppercase letter
    const std::regex patternDigits("(.*[0-9].*)"); // regex that matches any string that contains at least one digit 

    int idCharGroups = 0;  // the number of groups of substrings of three or more 3 identical characters
    int threeCharGroups = 0; //the number of groups of exactly 3 identical characters in the code
    int changes = 0; // the minimum number of changes


    //here I compute the number of groups of exactly 3 identical characters in the code
    //and the number of groups of three or more identical characters.

    std::smatch m;
    std::string stringCopy;
    stringCopy = s;


    while (regex_search(stringCopy, m, patternRepeat)) {
       
        if(m[0].length()%3 == 0) 
            idCharGroups++;
        threeCharGroups += m[0].length()/3;
        stringCopy = m.suffix().str( );
    }
    
    // Here I count the number of changes that must be done in order to have at least one uppercase letter, one lowercase letter
    // and one digit.

    if (!regex_match(s, patternLowercase))
        changes++;
       
    if (!regex_match(s, patternUppercase)) 
        changes++;

    if (!regex_match(s, patternDigits))
        changes++;


    if (s.size() <= 20) {
        return max3(6 - s.size(), changes, threeCharGroups);
    }

    else {
        int repetitions = threeCharGroups - idCharGroups;
        int minChange = max(changes, repetitions);
        return minChange + (s.size() - 20);
    }


    /*   If the size of the password is less than 20, the minimum number of changes would be
    the maximum between the number of characters that need to be added for the string to be
    of a size of at least 16, thw number of characters that need to be inserted or replaced to
    have at leas one lowercase, one uppercase and one digit character, and the number of changes
    that need to be done in order to not have three repeating characters one after another
    */

    /* If the size of the password is greater that 20, we need to count the number of changes
    that need to be done to not have repetitive characters, considering that we will also have
    to do delete operations, by substracting from the numbers of groups of identical chars of
    three from the number of groups of identical characters with length greater than 3. Then
    the minimum change is the minimum between the number of uppercases, lowercases and digits,
    and the number computed above, to which we add the number of characters that must be
    deleted in order to get the length at most 20
    */
      
}

int main()
{

    //test 1
    std::string s1 ("eee"); 
    std::cout << "test1 \n" << s1 << ' ' << minimumChange(s1) << '\n';

    //test2
    std::string s2("Aeee"); 
    std::cout << "\ntest2  " << '\n' << s2 << ' ' << minimumChange(s2) << '\n';

    //test3
    std::string s3("Ae1de");
    std::cout << "\ntest3" << '\n' << s3 << ' ' << minimumChange(s3) << '\n';

    //test 4
    std::string s4("Aqwer1");
    std::cout << "\ntest4" << '\n' << s4 << ' ' << minimumChange(s4) << '\n';

    //test 5
    std::string s5("12333a");
    std::cout << "\ntest5" << '\n' << s5 << ' ' << minimumChange(s5) << '\n';

    //test 6
    std::string s6("Aqeee1");
    std::cout << "\ntest6" << '\n' << s6 << ' ' << minimumChange(s6) << '\n';

    //test 7
    std::string s7("A1eiuyiuyiuyqwertyiuu");
    std::cout << "\ntest7" << '\n' << s7 << ' ' << minimumChange(s7) << '\n';

    //test 8
    std::string s8("A1eiuyiuyiuyqweruuuuu");
    std::cout << "\ntest8" << '\n' << s8 << ' ' << minimumChange(s8) << '\n';


    //test 9
    std::string s9("asuhd87auA");
    std::cout << "\ntest9" << '\n' << s9 << ' ' << minimumChange(s9) << '\n';

    //test 10
    std::string s10("8gsdA98hasd");
    std::cout << "\ntest10" << '\n' << s10 << ' ' << minimumChange(s10) << '\n';

    


}

