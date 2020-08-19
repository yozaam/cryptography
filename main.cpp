#include <iostream>
#include<algorithm>

using namespace std;

int main() {
  cout << "RSA Algorithm!\n";
//   Choose two random large prime numbers p and q app. 1024-bits length. 
  int p = 193 , q = 197;
// Compute the product: n = pq. 
  int n = p*q;
// Compute φ(n) = (p − 1)(q − 1). (φ is Euler's totient function). 
  int totient = (p-1)*(q-1);
// Choose an integer e such that 1 < e < n, and e and φ(n) share no divisors other than 1 (i.e., e and φ(n) are relatively prime.). e does not have to be prime but it must be an odd number. 
  int e = n-1;
  for( ; e>=0 ; e-=2){
    if(__gcd(e, totient) == 1){
      //they are relatively prime
      break;
    }
  }

// Use the Euclidian algorithm to compute the decryption key d such that 

// ed =  1 mod φ(n)  
  int k = 1;
// d =  e-1 mod φ(n)  
  int d = (1 + (k*totient))/e; 
// d and n are relatively prime.  

// (e,n)à public keys (d,n)à private keys 
  int m = 10;//message
  cout<<"message "<<m<<endl;
// Encryption: c = me mod n where m is the message and c is the corresponding cipher text. 
  int c = (m*e)%n;
  cout<<"ciphertext "<<c<<endl;
// Decryption: m = cd mod n where c is the ciphertext and m is the corresponding message. 
  m = (c*d)%n;
  cout<<"after decryption, "<<m<<endl;

  return 0;
}