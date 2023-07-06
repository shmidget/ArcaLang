#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "ArcaUtils.h"

enum TokenType {
  ADD_TOKEN,
  SUB_TOKEN,
  MUL_TOKEN,
  DIV_TOKEN, 

  EQU_TOKEN,

  EOL_TOKEN,
  
  LBRACE_TOKEN,
  RBRACE_TOKEN,

  LPAREN_TOKEN,
  RPAREN_TOKEN,

};

std::map<char, TokenType> DefinedCharacters = {
    { '+', TokenType::ADD_TOKEN },
    { '-', TokenType::SUB_TOKEN },
    { '*', TokenType::MUL_TOKEN },
    { '/', TokenType::DIV_TOKEN },
    
    { '=', TokenType::EQU_TOKEN },

    { ';', TokenType::EOL_TOKEN },

    { '(', TokenType::LPAREN_TOKEN },
    { ')', TokenType::RPAREN_TOKEN },

    { '{', TokenType::LBRACE_TOKEN },
    { '}', TokenType::RBRACE_TOKEN },
};

std::string DefinedSyntax[] = {
  "println",
  "var"
};

struct Token {
  std::string Token_Value;
  TokenType Token_Type;
};

struct Lexxer {
public:
  int CurrentIndex = -1;
  int CurrentLineIndex = -1;
  char CurrentCharacter;
  std::string CurrentLine;
  std::vector<std::string> lines;

  void AdvanceIndex() {
    CurrentIndex++;
    if (CurrentIndex < CurrentLine.size()){
      CurrentCharacter = CurrentLine[CurrentIndex];
    }
  }

  void AdvanceLine() {
    CurrentLineIndex++;
    if (CurrentLineIndex < lines.size()){
      CurrentIndex = -1;
      CurrentLine = lines[CurrentLineIndex];
    }
  }

  void Tokenize(){
    AdvanceLine();
    AdvanceIndex();
    while (CurrentLineIndex < lines.size()) {

      std::string ExtraCharacters = "";

      while (CurrentIndex < CurrentLine.size()) {
        
        if (CurrentCharacter == ' ') { AdvanceIndex(); }

        if (!(DefinedCharacters.find(CurrentCharacter) == DefinedCharacters.end())) {
          std::cout << CurrentCharacter << "\n";
        } else {
          ExtraCharacters += CurrentCharacter;
          bool present = std::count(begin(DefinedSyntax), end(DefinedSyntax), ExtraCharacters);
          if (present) {
            std::cout << ExtraCharacters << "\n";
          }
        }

        AdvanceIndex();
      }

      std::cout << ExtraCharacters << "\n";
      AdvanceLine();
    }
  }

};

std::vector<Token> LexicalAnalysis(std::vector<std::string> lines) {
  std::vector<Token> Tokens;
  ThrowState("starting lexical analysis.");

  Lexxer newLexxer;
  newLexxer.lines = lines;
  newLexxer.Tokenize();

  ThrowState("finished lexical analysis.");


  return Tokens;
}