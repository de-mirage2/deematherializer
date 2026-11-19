#pragma once

#ifndef COMPOUNDEXPRESSION_HPP
#define COMPOUNDEXPRESSION_HPP

#include "Connective.hpp"
#include "Expression.hpp"
#include <memory>

namespace deemath::expression {

class CompoundExpression : public Expression {
private:
  Connective connective_;
  std::shared_ptr<Expression> left_;
  std::shared_ptr<Expression> right_;

protected:
  // Output

  void print(std::ostream &stream) const override;

public:
  // Constructors

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left);

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left,
                              std::shared_ptr<Expression> right);

  // Clone

  std::shared_ptr<Expression> clone() const override;

  // Mutators

  std::shared_ptr<Expression> left(std::shared_ptr<Expression> left) noexcept;

  std::shared_ptr<Expression> right(std::shared_ptr<Expression> right) noexcept;

  // Getters

  [[nodiscard]] Connective connective() const noexcept;

  [[nodiscard]] std::shared_ptr<Expression> left() const noexcept;

  [[nodiscard]] std::shared_ptr<Expression> right() const noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;
};

} // namespace deemath::expression

#endif
