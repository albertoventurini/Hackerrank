#include <iostream>
#include <vector>

using namespace std;

vector<char> build_alphabet()
{
  vector<char> result;
  for(char c = 'a'; c <= 'z'; c++)
  {
    result.push_back(c);
  }
  return result;
}

void process_char(char c, vector<char>& alphabet)
{
  if(c >= 'A' && c <= 'Z')
    c = tolower(c);
  if(c >= 'a' && c <= 'z')
  {
    for(vector<char>::iterator i = alphabet.begin(); i < alphabet.end(); i++)
    {
      if(*i == c)
      {
        alphabet.erase(i);
        break;
      }
    }
  }
}

int main()
{
  vector<char> alphabet = build_alphabet();
  char c;
  while(cin.get(c))
  {
    process_char(c, alphabet);
    if(alphabet.size() == 0)
    {
      cout << "pangram" << endl;
      return 0;
    }
  }
  cout << "not pangram" << endl;
}
