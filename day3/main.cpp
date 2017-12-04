#include <iostream>
#include <cmath>

struct Point
{

  constexpr Point(int m_x, int m_y) : x(m_x), y(m_y)
  {
  }

  int x = 0;
  int y = 0;

};

constexpr int manhattanDistance(Point a, Point b)
{
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

constexpr Point spiral2Grid(int spiralSquare)
{

  Point pos = {0, 0};
  int level = 1;
  int num = 1;
  while (num != spiralSquare)
    {
      num++;
      pos.x++;
      if (num == spiralSquare)
	{
	      return pos;
	}
      while (pos.y < level)
	{
	  num++;
	  pos.y++;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.x > -level)
	{
	  num++;
	  pos.x--;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.y > -level)
	{
	  num++;
	  pos.y--;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.x < level)
	{
	  num++;
	  pos.x++;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      level++;
    }
  return pos;
}

int findBiggerNumberInAllocation(int spiralSquare)
{
  std::vector<int> valuesOfSquares;
  Point pos = {0, 0};
  int level = 1;
  int num = 1;
  valuesOfSquares.push_back(num);
  while (num != spiralSquare)
    {
      num++;
      pos.x++;
      if (num == spiralSquare)
	{
	      return pos;
	}
      while (pos.y < level)
	{
	  num++;
	  pos.y++;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.x > -level)
	{
	  num++;
	  pos.x--;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.y > -level)
	{
	  num++;
	  pos.y--;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      while (pos.x < level)
	{
	  num++;
	  pos.x++;
	  if (num == spiralSquare)
	    {
	      return pos;
	    }
	}

      level++;
    }
  return num;
}

int main()
{

  // Part 1
  std::cout << "Test answer: " << manhattanDistance({0, 0}, spiral2Grid(1)) << '\n';
  std::cout << "Test answer: " << manhattanDistance({0, 0}, spiral2Grid(12)) << '\n';
  std::cout << "Test answer: " << manhattanDistance({0, 0}, spiral2Grid(23)) << '\n';
  std::cout << "Test answer: " << manhattanDistance({0, 0}, spiral2Grid(1024)) << '\n';
  std::cout << "Answer: "      << manhattanDistance({0, 0}, spiral2Grid(368078)) << '\n';

  //Part 2

  std::cout << "Test answer: " << findBiggerNumberInAllocation(0) << '\n';
  std::cout << "Test answer: " << findBiggerNumberInAllocation(1) << '\n';
  std::cout << "Test answer: " << findBiggerNumberInAllocation(2) << '\n';
  std::cout << "Test answer: " << findBiggerNumberInAllocation(17) << '\n';
  std::cout << "Test answer: " << findBiggerNumberInAllocation(23) << '\n';
  std::cout << "Test answer: " << findBiggerNumberInAllocation(1024) << '\n';
  std::cout << "Answer: " << findBiggerNumberInAllocation(368078) << '\n';

  return 0;
}
