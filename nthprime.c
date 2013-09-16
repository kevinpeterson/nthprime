/*
* Copyright (c) 2012, Kevin Peterson
* Released under the MIT License <http://opensource.org/licenses/mit-license.php>
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int divide_check(int nth_prime) {
    int primes = 0;
    int current_prime;

    int i;

    if(nth_prime==1) {
        // Special case - first prime is the only even one
	return 2;
    }

    for(i=1;primes<nth_prime;i+=2){
        char prime = 1;
        
        //I've found here that j*j<=i is about 4x faster
        //than j<=sqrt(i). YMMV.
        int j;
        for(j=2;j*j<=i;j++){
            if(i % j == 0 && i != j){
                prime = 0;
                break;
            }
        }
        if(prime){
            current_prime = i;
            primes++;
        }
    }

    return current_prime;
}

int sieve(int nth_prime) {
    //approximate the prime number given n. This is guarenteed
    //to be > the actual nth prime. This is used to determine
    //how big our sieve must be.
    int nth_prime_approx_max = ( log(nth_prime) + log(log(nth_prime)) ) * nth_prime;

    int i,j;
    char *sieve = calloc(nth_prime_approx_max, 1);
    for (i=2;i*i<=nth_prime_approx_max; i++) {
        if (!sieve[i]) {
            for(j=i+i;j<nth_prime_approx_max;j+=i) { 
                sieve[j] = 1; 
            }
        }
    }

    int prime_to_return;

    int primes = 0;
    for (i=2;i<nth_prime_approx_max && !prime_to_return; i++) {
        if (!sieve[i]) { 
            primes++;
            if(primes == nth_prime){
               prime_to_return = i;
            }
        }
    }

    free(sieve);
    return prime_to_return;
}

int main(int argc, char* argv[]) {
    if(argc != 2 || argv[1] == NULL){
        printf("Usage: nthprime <nth>\n");
        return 1;
    }

    int nth = atoi(argv[1]);

    int prime;

    //the sieve approx only works with n >= 6. Otherwise,
    //revert to divide check
    if(nth >= 6){
        prime = sieve(nth);
    } else {
        prime = divide_check(nth);
    }
    
    printf("%i\n", prime);

    return 0;
}

