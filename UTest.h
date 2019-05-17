//
//  UTest.h
//  UnitTestLibrary
//
//  Created by Luis Fabian on 5/17/19.
//  Copyright © 2019 Luis Fabian. All rights reserved.
//

#ifndef UTest_h
#define UTest_h

#include <cstdio>

#define __UTest_VERSION "1.0.0"

static constexpr const char * _passString = "Pass";
static constexpr const char * _failedString = "Fail";

class UTest {
    const char * _tstr = nullptr;
    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;
    
    UTest(){};                      // No default Constructor
    UTest(UTest &);                 // No copy constructor
    UTest operator = (UTest &);     //No assignment operator

public:
   
    UTest(const char * );
    void init(const char * );
    bool summary (bool flag) {return _summary_flag = flag;}
    bool summary() {return _summary_flag;}
    unsigned long int pass_count() const {return _pass_count;}
    unsigned long int fail_count() const {return _fail_count;}
    static const char * version() {return __UTest_VERSION;}
    void test (const char * description, const int flag);
    void report() const;
    
};



#endif /* UTest_h */
