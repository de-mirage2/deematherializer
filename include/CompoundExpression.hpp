#ifndef COMPOUNDEXPRESSION_HPP
#define COMPOUNDEXPRESSION_HPP

#include "Connective.hpp"
#include "Expression.hpp"
#include <memory>

class CompoundExpression : public Expression {
private:
  Connective connective_;
  std::shared_ptr<Expression> left_;
  std::shared_ptr<Expression> right_;

protected:
  // Output

  void print(std::ostream &stream) const override;

public:
  // Constructors - std::shared_ptr<Expression>

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left);

  explicit CompoundExpression(Connective connective,
                              std::shared_ptr<Expression> left,
                              std::shared_ptr<Expression> right);

  // Clone

  std::shared_ptr<Expression> clone() const override;

  // Mutators

  [[nodiscard]] Connective connective() const noexcept;

  std::shared_ptr<Expression> left(std::shared_ptr<Expression> left) noexcept;

  std::shared_ptr<Expression> right(std::shared_ptr<Expression> right) noexcept;

  // Getters

  [[nodiscard]] std::shared_ptr<Expression> left() const noexcept;

  [[nodiscard]] std::shared_ptr<Expression> right() const noexcept;

  // Evaluate

  [[nodiscard]] bool evaluate() const override;
};

#endif
