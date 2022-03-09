#include <iostream>
#include <cmath>
#include "./nth_root.h"
#include "test_helpers.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        bool pass = true;
        EXPECT_THROW(nth_root(2, 1), std::domain_error);
        
		EXPECT_THROW(nth_root(0, 3), std::domain_error);
        
		EXPECT_THROW(nth_root(4, -1), std::domain_error);
        
		EXPECT_THROW(nth_root(-1, 0), std::domain_error);
        
		EXPECT_THROW(nth_root(1, 0), std::domain_error);
        
		EXPECT_THROW(nth_root(-1, -3), std::domain_error);
        
		EXPECT_THROW(nth_root(-7, -3), std::domain_error);
        
		EXPECT_THROW(nth_root(-2, 3), std::domain_error);
        
		EXPECT_THROW(nth_root(7, -3), std::domain_error);
        EXPECT_THROW(nth_root(1, 2.5), std::domain_error);

        

    }


    /*{   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
        actual = nth_root(0, 3);
        std::cout << "nth_root(0, 3) = " << actual << std::endl;
        actual = nth_root(4, -1);
        std::cout << "nth_root(4, -1) = " << actual << std::endl;
        actual = nth_root(-1, 0);
        std::cout << "nth_root(-1, 0) = " << actual << std::endl;
        actual = nth_root(1, 0);
        std::cout << "nth_root(1, 0) = " << actual << std::endl;
        actual = nth_root(-1, -3);
        std::cout << "nth_root(-1, -3) = " << actual << std::endl;
        actual = nth_root(-7, -3);
        std::cout << "nth_root(-7, -3) = " << actual << std::endl;
        actual = nth_root(-2, 3);
        std::cout << "nth_root(-2, 3) = " << actual << std::endl;
        actual = nth_root(7, -3);
        std::cout << "nth_root(7, -3) = " << actual << std::endl;
        actual = nth_root(1, 2.5);
        std::cout << "nth_root(1, 2.5) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }*/
}

