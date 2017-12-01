#include <iostream>
#include <fstream>
#include <algorithm>

int captchaSum(const std::string& input, int stepsLookahead = 1)
{
  int sum = 0;
  for (std::size_t i = 0; i < input.size(); ++i)
    {
      if (input[i] == input[(i+stepsLookahead) % input.size()])
	{
	  //std::cout << "toto: " << input[i] << '\n';
	  sum += input[i] - '0';
	}
    }
  return sum;
}

int main()
{
  std::fstream inputFile("input.txt");
  std::string input;
  std::getline(inputFile, input);

  // First part

  std::string test = "1122";
  std::string test2 = "1111";
  std::string test3 = "1234";
  std::string test4 = "91212129";

  std::cout << "Test answer: " << captchaSum(test) << '\n';
  std::cout << "Test answer: " << captchaSum(test2) << '\n';
  std::cout << "Test answer: " << captchaSum(test3) << '\n';
  std::cout << "Test answer: " << captchaSum(test4) << '\n';
  std::cout << "Answer: " << captchaSum(input) << '\n';

  // Second Part

  std::string testLookahead = "1212";
  std::string test2Lookahead = "1221";
  std::string test3Lookahead = "12345";
  std::string test4Lookahead = "123123";
  std::string test5Lookahead = "12131415";

  std::cout << "Test answer: " << captchaSum(testLookahead, testLookahead.size() / 2) << '\n';
  std::cout << "Test answer: " << captchaSum(test2Lookahead, test2Lookahead.size() / 2) << '\n';
  std::cout << "Test answer: " << captchaSum(test3Lookahead, test3Lookahead.size() / 2) << '\n';
  std::cout << "Test answer: " << captchaSum(test4Lookahead, test4Lookahead.size() / 2) << '\n';
  std::cout << "Test answer: " << captchaSum(test5Lookahead, test5Lookahead.size() / 2) << '\n';
  std::cout << "Answer: " << captchaSum(input, input.size() / 2) << '\n';



  return 0;
}
