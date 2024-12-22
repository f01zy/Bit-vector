#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

const int cols = 16;
const int rows = 8;

typedef bitset<cols> BYTE;

vector<int> numbers(rows);

int getC(int index) { return index % cols; }

int getR(int index) { return (int)floor(index >> 4); }

vector<int> getPosition(int index) {
  int x = getC(index);
  int y = getR(index);

  vector<int> position = {x, y};

  return position;
}

bool isSetBit(int number, int index) { return (number & (1 << index)) != 0; }

void setBit(vector<int> pos) { numbers[pos[1]] |= (1 << pos[0]); }

void inverseBit(vector<int> pos) { numbers[pos[1]] ^= (1 << pos[0]); }

void resetBit(vector<int> pos) { numbers[pos[1]] &= ~(1 << pos[0]); }

int getIndex() {
  string value;
  cout << "index: ";
  getline(cin, value);

  int index;

  try {
    index = stoi(value);
  } catch (const invalid_argument &e) {
    throw invalid_argument("Введите число");
  }

  if (index > rows * cols) {
    throw invalid_argument("Индекс не может превышать 64");
  }

  return index;
}

int main() {
  do {
    system("clear");

    cout << "type `h` to get commands list" << endl;
    cout << "" << endl;

    for (int i = 0; i < numbers.size(); i++) {
      cout << i << " " << (BYTE)(numbers[i]) << endl;
    }

    string cmd;
    cout << "" << endl;
    cout << "command: ";
    getline(cin, cmd);

    if (cmd == "h") {
      cout << "h: show all command" << endl;
      cout << "s: set bit" << endl;
      cout << "r: reset bit" << endl;
      cout << "i: inverse bit" << endl;
      getchar();
      continue;
    }

    else if (cmd == "s") {
      int index = getIndex();
      vector<int> pos = getPosition(index);
      setBit(pos);
    }

    else if (cmd == "r") {
      int index = getIndex();
      vector<int> pos = getPosition(index);
      resetBit(pos);
    }

    else if (cmd == "i") {
      int index = getIndex();
      vector<int> pos = getPosition(index);
      inverseBit(pos);
    }

    else {
      cout << "error: unknown command" << endl;
      getchar();
    }
  } while (1);

  return 0;
}
