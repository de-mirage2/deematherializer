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

  // Getters

  [[nodiscard]] const std::string &name() const noexcept;

  [[nodiscard]] const bool &value() const noexcept;

  // Mutators

  std::string name(std::string name) noexcept;

  bool value(bool value) noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;
};

} // namespace deemath::expression

#endif
