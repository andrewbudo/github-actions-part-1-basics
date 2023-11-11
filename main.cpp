// Copyright © 2023 by Andrew Budo

#include <iostream>

int main() {
  std::string input;
  std::cin >> input;
  int max_seq = 0;
  int seq = 1;
  for (size_t i = 1; i < input.size(); ++i) {
    if (input[i] == input[i - 1] && input[i] == '0') {
      ++seq;
      max_seq = (seq > max_seq) ? seq : max_seq;
    } else {
      seq = 1;
    }
  }
  std::cout << max_seq << std::endl;
}
