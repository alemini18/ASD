#ifndef _INPUT_
#define _INPUT_
#include <iostream>
#include <sstream>
#include <vector>

  std::ostream &operator << (std::ostream &out, const std::vector<int> &vec) {
      for (int i = 0; i < vec.size(); i++)
          out << vec[i] << " ";
      return out;
  }

  std::istream &operator >> (std::istream &in, std::vector<int> &vec) {
      // scan line of text
      std::string line;
      std::getline(in, line);

      // convert line of text into a new input stream
      std::istringstream is(line);

      // convert new input stream into array
      int value;
      while (is >> value)
          vec.push_back(value);

      return in;
  }
#endif /* _INPUT_ */
