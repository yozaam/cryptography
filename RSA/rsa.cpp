#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;

int main() {
  cout << "RSA Algorithm!\n";
//   Choose two random large prime numbers p and q app. 1024-bits length. 
     unsigned int p = 193 , q = 197;
// Compute the product: n = pq. 
     unsigned int n = p*q;
// Compute φ(n) = (p − 1)(q − 1). (φ is Euler's totient function). 
     unsigned int totient = (p-1)*(q-1);
  cout<<"totient "<<totient<<endl;
// Choose an    unsigned integer e such that 1 < e < n, and e and φ(n) share no divisors other than 1 (i.e., e and φ(n) are relatively prime.). e does not have to be prime but it must be an odd number. 
  unsigned int e;
  
  

  for(unsigned int i = 3;i<n ; i+=2){
    cout<<"gcd = "<<__gcd(i, totient)<<endl;
    if(__gcd(i, totient) == 1){
      //they are relatively prime
      e = i;
      break;
    }
  }
  cout<<"e "<<e<<endl;
// Use the Euclidian algorithm to compute the decryption key d such that 

// ed =  1 mod φ(n)  
     unsigned int k = 1;
// d =  e-1 mod φ(n)  
     unsigned int d = (1 + (k*totient))/e; 
// d and n are relatively prime.  
cout<<"k , d "<<k<<", "<<d<<endl;
// (e,n)à public keys (d,n)à private keys 
     unsigned int m = 0;//message
  cout<<"message = "<<m<<endl;
// Encryption: c = me mod n where m is the message and c is the corresponding cipher text. 
     unsigned int c = (unsigned int)(pow((double)m,(double)e)) %n;
  cout<<"ciphertext = "<<c<<endl;
// Decryption: m = cd mod n where c is the ciphertext and m is the corresponding message. 
  m = (unsigned int)(pow((double)c,(double)d))%n;
  cout<<"after decryption, "<<m<<endl;

  return 0;
}