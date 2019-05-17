//
//  UTest.cpp
//  UnitTestLibrary
//
//  Created by Luis Fabian on 5/17/19.
//  Copyright © 2019 Luis Fabian. All rights reserved.
//

#include <stdio.h>
#include "UTest.h"


UTest::UTest(const char * tstr) {
    init(tstr);
}

void UTest::init(const char * tstr ){
    _tstr = tstr;
    _pass_count = _fail_count = 0;
}

void UTest::test(const char * description, const int flag) {
    const char * pf = nullptr;
    
    if(flag){
        pf = _passString;
        ++_pass_count;
    }
    else {
        pf = _failedString;
        ++_fail_count;
    }
    // Provide details about test
    if(!_summary_flag) printf("%s: %s --> %s\n", _tstr, description, pf);
}

void UTest::report() const {
    printf("%s: pass: %ld, fail: %ld\n", _tstr, pass_count(), fail_count());
    fflush(stdout);
}


