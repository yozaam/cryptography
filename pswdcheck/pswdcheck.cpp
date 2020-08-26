#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<char> specials(
  {'!','@','#','$','%','^','&',
  '*','(',')','-','+'});
//store all the specials in a set


string strength(string pswd){
  bool hasLower=0, 
   hasUpper=0, 
   hasSpecial=0,
   hasLength=0, 
   hasDigit=0;

   //all set to false in the begining

   for(char c : pswd){

     if(isdigit(c))

       hasDigit = 1;

     else if(islower(c))

       hasLower = 1;

     else if(isupper(c))

       hasUpper = 1;

     else if(specials.count(c))
       //if this element exists in the specials set
       hasSpecial = 1;
     

   }

  if(pswd.length()>=8)

    hasLength = 1;
  

  int score = hasDigit+hasLower
    +hasUpper+hasSpecial+hasLength;

  if(score==5)

    return "strong";

  else if(hasSpecial and hasLower 
    and hasUpper 
    and (pswd.length()>=6))

    return "moderate";

  else
    return "weak";
  
  
}

int main() {

  while(1){

    string pswd;

    cout<<"\nEnter your password:";

    cin>>pswd;

    cout<<"\n"<<strength(pswd)<<"\n";

  }

  return 0;
}