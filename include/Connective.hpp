#ifndef CONNECTIVE_HPP
#define CONNECTIVE_HPP

enum class Connective {
  NEGATION = '~',
  CONJUNCTION = '&',
  DISJUNCTION = '|',
  IMPLICATION = '>',
  CONVERSE = '<',
  BICONDITIONAL = '#',
  EXCLUSIVE_DISJUNCTION = '^'
};

// Parse Operand

// [[nodiscard]] static Connective parseOperand(char c);

#endif
