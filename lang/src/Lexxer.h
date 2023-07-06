#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum TokenType {
  ADD_TOKEN,
  SUB_TOKEN,
  MUL_TOKEN,
  DIV_TOKEN 
};


struct Token {
  std::string TokenValue;
  std::string TokenType;
};

struct Lexxer {
public:
  int CurrentIndex = -1;
  int CurrentLineIndex = -1;
  char CurrentCharacter = ' ';
  std::string CurrentLine = "";
  std::vector<std::string> lines;

  void AdvanceIndex();
  void AdvanceLine();
  void Tokenize();
};

std::vector<Token> LexicalAnalysis(std::vector<std::string> lines);