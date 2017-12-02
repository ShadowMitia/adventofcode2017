#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <limits>


int checksum(const std::vector<std::vector<int>>& spreadsheet)
{
  int sum = 0;
  for (auto line : spreadsheet)
    {
      auto res = std::minmax_element(line.begin(), line.end());
      int min = *(res.first);
      int max = *(res.second);
      sum += (max - min);
    }
  return sum;
}

int evenlyDivisibleValues(const std::vector<int>& values)
{
  int result = 0;

  for (std::size_t i = 0; i < values.size(); ++i)
    {
      for (std::size_t j = 0; j < values.size(); ++j)
	{
	  if (i == j) continue;
	  if (values[i] % values[j] == 0)
	    {
	      result += values[i] / values[j];
	    }
	}
    }

  return result;
}

std::vector<std::vector<int>> getSpreadsheetFromFile(const std::string& inputFile)
{
  std::ifstream file(inputFile);
  std::vector<std::vector<int>> inputSpreadsheet;
  std::string line;

  int spreadsheetLine = 0;
  while (std::getline(file, line))
    {
      std::stringstream ss(line);
      int cellNum;
      inputSpreadsheet.emplace_back();
      while (ss >> cellNum)
	{
	  inputSpreadsheet[spreadsheetLine].emplace_back(cellNum);
	}
      spreadsheetLine++;
    }
  return inputSpreadsheet;
}

int main()
{


  std::vector<std::vector<int>> inputSpreadsheet = getSpreadsheetFromFile("input.txt");

  // Part 1

  std::vector<std::vector<int>> test = {
    {5, 1, 9, 5},
    {7, 5, 3},
    {2, 4, 6, 8}
  };

  std::cout << "Test answer: " << checksum(test) << '\n';
  std::cout << "Answer: " << checksum(inputSpreadsheet) << '\n';

  // Part 2

  std::vector<std::vector<int>> test2 =
    {
      { 5, 9, 2, 8},
      { 9, 4, 7, 3},
      { 3, 8, 6, 5}
    };

  int sum = 0;
  for (auto& row : test2)
    {
      sum += evenlyDivisibleValues(row);
    }
  std::cout << "Test answer: " << sum << '\n';

  sum = 0;
  for (auto& row : inputSpreadsheet)
    {
      sum += evenlyDivisibleValues(row);
    }
  std::cout << "Answer: " << sum << '\n';

  return 0;
}
