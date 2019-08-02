#include <iostream>
#include <string>
#include <percent_encoding.hpp>

void usage(const char *argv0) {
	std::cerr << "[Usage]" << std::endl;
  std::cerr << "  " << argv0 << " [message]   : encoding [message]" << std::endl;
  std::cerr << "  " << argv0 << " -s          : input line from stdin" << std::endl;
}

int main(int argc, char **argv) {
	if (argc <= 1) {
    usage(argv[0]);
    return 0;
  }

  std::string src = "";
  if (std::string(argv[1]) == "-s") {
    std::cin >> src;
  } else {
    src = std::string(argv[1]);
  }
  std::cout << PercentEncoding::encode(src) << std::endl;

	return 0;
}
