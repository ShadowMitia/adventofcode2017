#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

bool uniqueWords(const std::string& passphrase)
{
  std::stringstream ss(passphrase);
  std::vector<std::string> usedWords;
  std::string word;
  while (ss >> word)
    {
      if (std::find(usedWords.begin(), usedWords.end(), word) == usedWords.end())
	{
	  usedWords.push_back(word);
	}
      else
	{
	  return false;
	}
    }

  return true;
}

bool uniqueWordsNoAnagrams(const std::string& passphrase)
{
  std::stringstream ss(passphrase);
  std::vector<std::string> usedWords;
  std::string word;
  while (ss >> word)
    {
      std::sort(word.begin(), word.end());
      if (std::find(usedWords.begin(), usedWords.end(), word) == usedWords.end())
	{
	  usedWords.push_back(word);
	}
      else
	{
	  return false;
	}
    }

  return true;
}

int main()
{

  std::vector<std::string> inputPassphrases;
  std::ifstream inputFile("input.txt");
  std::string line;
  while (std::getline(inputFile, line))
    {
      inputPassphrases.push_back(line);
    }

  // Part 1

  std::cout << std::boolalpha << uniqueWords("aa bb cc dd ee") << '\n';
  std::cout << std::boolalpha << uniqueWords("aa bb cc dd aa") << '\n';
  std::cout << std::boolalpha << uniqueWords("aa bb cc dd aaa") << '\n';

  int numValidPassphrases = 0;
  for (auto& passphrase : inputPassphrases)
    {
      if (passphrase.empty()) continue;
      if (uniqueWords(passphrase))
	{
	  numValidPassphrases++;
	}
    }
  std::cout << "Answer: " << numValidPassphrases << '\n';

  // Part 2

  std::cout << std::boolalpha << uniqueWordsNoAnagrams("abcde fghij") << '\n';
  std::cout << std::boolalpha << uniqueWordsNoAnagrams("abcde xyz ecdab") << '\n';
  std::cout << std::boolalpha << uniqueWordsNoAnagrams("a ab abc abd abf abj") << '\n';
  std::cout << std::boolalpha << uniqueWordsNoAnagrams("iiii oiii ooii oooi oooo") << '\n';
  std::cout << std::boolalpha << uniqueWordsNoAnagrams("oiii ioii iioi iiio") << '\n';

  int numValidPassphrasesWithoutAnagrams = 0;
  for (auto& passphrase : inputPassphrases)
    {
      if (passphrase.empty()) continue;
      if (uniqueWordsNoAnagrams(passphrase))
	{
	  numValidPassphrasesWithoutAnagrams++;
	}
    }
  std::cout << "Answer: " << numValidPassphrasesWithoutAnagrams << '\n';


  return 0;
}
