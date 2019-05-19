/**
 * The MIT License (MIT)
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef UTest_h
#define UTest_h

#define __UTest_VERSION "1.0.0"
#define EXTENSION ".html"
#define TABLE_OF_CONTENT  "<table style=\"width:100%\" border=1px><tr><th>Test Name</th><th>Outcome</th></tr>"
#define TABLE_STYLE "<style>table {font-family: arial, sans-serif;border-collapse: collapse;width: 100%;}td, th {border: 1px solid #dddddd;text-align: left;padding: 8px;tr:nth-child(even) {background-color: #dddddd;}</style>}"

#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include "ctml.h"

static constexpr const char * _passString = "Pass";
static constexpr const char * _failedString = "Fail";

class Test {
public:
    std::string _title;
    const int _passed;
    Test(std::string title, const int passed) : _title(title) , _passed(passed) {}
};


class UTest {
    
    std::vector<Test> _testList;
    std::string _tstr;
    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;
    
    UTest(){};                      // No default Constructor
    UTest(UTest &);                 // No copy constructor
    UTest operator = (UTest &);     //No assignment operator

public:
   
    UTest(std::string);
    void init(std::string);
    bool summary (bool flag) {return _summary_flag = flag;}
    bool summary() {return _summary_flag;}
    unsigned long int pass_count() const {return _pass_count;}
    unsigned long int fail_count() const {return _fail_count;}
    static const char * version() {return __UTest_VERSION;}
    void test ( const char * description, const int flag);
    void report();
};



#endif /* UTest_h */
