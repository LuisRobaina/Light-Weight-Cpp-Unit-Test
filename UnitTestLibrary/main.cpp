//
//  main.cpp
//  UnitTestLibrary
//
//  Created by Luis Fabian on 5/17/19.
//  Copyright © 2019 Luis Fabian. All rights reserved.
//

#include "UTest.h"

int fib(int n, int sum = 0) {
    if(n<0) return -1;
    if(n <= 2) {return 1;}
    else {return fib(n-1) + fib(n-2);}
}

int main(int argc, const char * argv[]) {
    

    UTest unit("Fibonacci Test");
    unit.test("Fib Test",fib(5) == 5);
    unit.test("Fib Test Negative",fib(-1) == -1);
    unit.test("Fib Test Negative 2", fib(-2) == -1);
    unit.test("Fib Test 7", fib(7) == 13);
    unit.test("Fib Test 8", fib(8) == 21);
    
    // Generates an HTML report of all performed tests.
    unit.report();
    return 0;
}
