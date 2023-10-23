#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void loseFile(string filename) {
  string line;
  ifstream file(filename);

  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  } else
    cout << "unable to open file!";
}

void appendToFile(std::string filename) {
  ofstream file;
  file.open(filename, std::ios_base::app);
  std::string input = "";
  if (file.is_open()) {
    cout << "[" + filename + "]" << endl;
    cout << "$";
    getline(cin, input);
    while (input != ".") {
      file << input + "\n";
      cout << "$";
      getline(cin, input);
    }
    file.close();
  } else
    cout << "unable to open file";
}

int maakKeuze(string filename) {
  char keuze;
  cout << "<COMMAND> ";
  cin >> keuze;

  while (keuze != 'q' || keuze != 'Q') {
    switch (keuze) {
    case 'A':
      appendToFile(filename);
      break;
    case 'L':
      loseFile(filename);
      break;
    case 'Q':
      cout << "quitting..." << endl;
      return 0;

    default:
      cout << "NOT A COMMAND" << endl;
      break;
    }
    cout << "<COMMAND> ";
    cin >> keuze;
  }
  return 0;
}

void start(string filename) {
  cout << "[CEDIT in " << filename << "]"
       << "\n"
       << endl;
}

int main(int argc, char *argv[]) {

  try {
    std::string input(argv[1]);
    start(input);
    maakKeuze(input);
  } catch (...) {
    cout << "no file given" << endl;
  }

  return 0;
}
