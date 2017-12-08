#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int numStepsToEscapeMaze(std::vector<int> maze)
{
  unsigned int numSteps = 0;
  bool escaped = false;
  int currentPosition = 0;

  while (!escaped)
    {
      int offset = maze.at(currentPosition);
      maze[currentPosition]++;
      currentPosition += offset;
      numSteps++;
      if (currentPosition >= maze.size())
	{
	  return numSteps;
	}

    }

}

int numStepsToEscapeMaze2(std::vector<int> maze)
{
  unsigned int numSteps = 0;
  bool escaped = false;
  int currentPosition = 0;

  while (!escaped)
    {
      int offset = maze.at(currentPosition);
      if (offset >= 3)
	{
	  maze[currentPosition]--;
	}
      else
	{
	  maze[currentPosition]++;
	}
      currentPosition += offset;
      numSteps++;
      if (currentPosition >= maze.size())
	{
	  return numSteps;
	}

    }

}

int main()
{

  std::ifstream inputFile("input.txt");
  std::vector<int> input;
  std::string line;
  while (std::getline(inputFile, line))
    {
      input.push_back(std::atoi(line.c_str()));
    }

  // Part 1

  std::vector<int> example = {0, 3, 0, 1, -3};
  std::cout << "Example: " << numStepsToEscapeMaze(example) << '\n';

  std::cout << "Answer: " << numStepsToEscapeMaze(input) << '\n';

  // Part 2

  std::cout << "Example: " << numStepsToEscapeMaze2(example) << '\n';
  std::cout << "Answer: " << numStepsToEscapeMaze2(input) << '\n';

  return 0;
}
