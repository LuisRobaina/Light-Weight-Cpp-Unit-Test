//
//  UTest.cpp
//  UnitTestLibrary
//
//  Created by Luis Fabian on 5/17/19.
//  Copyright © 2019 Luis Robaina. All rights reserved.
//

#include <stdio.h>
#include "UTest.h"
#include <iostream>

void UTest::report() {
    
    printf("Generating UTest HTML Report\n");
    
    CTML::Document document;
    
    CTML::Node node("div");
    node.AppendText("<h2>"+ _tstr + "<h2>");
    node.AppendText("<h3> Passed: "+std::to_string(_pass_count) + "     Fail: "+std::to_string(_fail_count)+"<h3>");
    node.AppendText(TABLE_OF_CONTENT);
    
    
    // Include unit tests information
    for(Test t : _testList){
        const std:: string result = t._passed ? "OK" : "F";
        const std::string info = "<tr><th>"+t._title+"</th><th>" + result +"</th></tr>";
        node.AppendText(info);
    }
    document.AppendNodeToBody(node);
    
    std::ofstream HTMLreport;
    HTMLreport.open(_tstr+EXTENSION);
   
    if (!HTMLreport.is_open() ) {
        std::cerr << "Cannot create ..., error was: " << strerror( errno);
    }
    
    HTMLreport << document.ToString() << std::endl;
    HTMLreport.close();
    
}

UTest::UTest(const std::string & tstr) {
    init(tstr);
}

void UTest::init(const std::string & tstr ){
    _tstr = tstr;
    _pass_count = _fail_count = 0;
}

void UTest::test( const char * description, const int flag) {
    const char * pf = nullptr;
    
    if(flag){
        ++_pass_count;
    }
    else {
        ++_fail_count;
    }
    // Provide details about test
    if(!_summary_flag) {
         Test test(description,flag);
         //printf("%s: %s --> %s\n", _tstr, description, pf);
        _testList.push_back(test);
    }
}


