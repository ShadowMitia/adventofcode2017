#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void printVector(const std::vector<int>& t)
{
  for (auto& v : t)
    {
      std::cout << v << ' ';
    }
  std::cout << '\n';
}

int allocatorInfiniteCycleDetector(std::vector<int> memories)
{
  std::vector<int> currentMem = memories;
  int numCycles = 0;
  bool reallocating = true;
  std::vector<std::vector<int>> previousAllocations;
  previousAllocations.push_back(currentMem);
  while (reallocating)
    {
      //printVector(currentMem);
      auto iterMax = std::max_element(currentMem.begin(), currentMem.end());
      int max = *iterMax;
      *iterMax = 0;
      int offset = iterMax - currentMem.begin();

      while (max > 0)
	{
	  offset++;
	  if (offset >= currentMem.size())
	    {
	      offset = 0;
	    }
	  currentMem[offset]++;
	  max--;
	}
      numCycles++;
      //printVector(currentMem);
      int previousSize = previousAllocations.size();
      if (std::find(previousAllocations.begin(), previousAllocations.end(), currentMem) == previousAllocations.end())
	{
	  previousAllocations.push_back(currentMem);
	}
      if (previousSize == previousAllocations.size())
	{
	  reallocating = false;
	}
    }

  return numCycles;
}

int main()
{
  std::vector<int> input = {4,10,4,1,8,4,9,14,5,1,14,15,0,15,3,5};

  // Part 1
  std::vector<int> example = {0, 2, 7, 0};

  std::cout << "Test answer: " << allocatorInfiniteCycleDetector(example) << '\n';
  std::cout << "Answer: " << allocatorInfiniteCycleDetector(input) << '\n';

  // Part 2


  return 0;
}
