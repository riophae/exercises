#include <ctime>
#include <vector>
#include <iostream>

int program1(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    ++sum;
  }

  return sum;
}

int program2(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned j = 0; j < n; ++j) {
      ++sum;
    }
  }

  return sum;
}

int program3(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned j = 0; j < n * n; ++j) {
      ++sum;
    }
  }

  return sum;
}

int program4(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      ++sum;
    }
  }

  return sum;
}

int program5(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned j = 0; j < i * i; ++j) {
      for (unsigned k = 0; k < j; ++k) {
        ++sum;
      }
    }
  }

  return sum;
}

int program6(unsigned int n) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned j = 0; j < i * i; ++j) {
      if (j % i == 0) {
        for (unsigned k = 0; k < j; ++k) {
          ++sum;
        }
      }
    }
  }

  return sum;
}

void run(int (*program)(unsigned int n), unsigned int arg) {
  const clock_t startTime = clock();
  program(arg);
  const clock_t endTime = clock();
  std::cout << arg << "\t" << endTime - startTime << std::endl;
}

int main() {
  const std::vector<int (*)(unsigned int n)> programs = {
    program1,
    program2,
    program3,
    program4,
    program5,
    program6,
  };

  for (const auto program: programs) {
    for (int arg = 2 << 4; arg < (1 << 20); arg <<= 1) {
      run(program, arg);
    }
    std::cout << std::endl;
  }

  return 0;
}
