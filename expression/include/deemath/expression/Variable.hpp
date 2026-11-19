#pragma once

#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "Expression.hpp"

namespace deemath::expression {

class Variable : public Expression {
private:
  std::string name_;
  bool value_;

protected:
  // Output

  void print(std::ostream &stream) const override;

public:
  // Constructors

  explicit Variable(std::string name, bool value);

  // Clone

  std::shared_ptr<Expression> clone() const override;

  // Mutators

  [[nodiscard]] std::string &name() noexcept;

  [[nodiscard]] bool &value() noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;
};

} // namespace deemath::expression

#endif
