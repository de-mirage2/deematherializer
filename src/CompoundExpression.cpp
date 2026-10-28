#include "../include/CompoundExpression.hpp"

#include <memory>
#include <stdexcept>

// Constructors - std::shared_ptr<Expression>

CompoundExpression::CompoundExpression(Connective connective,
                                       std::shared_ptr<Expression> left)
    : connective_(connective), left_(std::move(left)), right_(nullptr) {};

CompoundExpression::CompoundExpression(Connective connective,
                                       std::shared_ptr<Expression> left,
                                       std::shared_ptr<Expression> right)
    : connective_(connective), left_(std::move(left)),
      right_(std::move(right)) {};

// Clone

std::shared_ptr<Expression> CompoundExpression::clone() const {
  return std::make_shared<CompoundExpression>(*this);
}

// Mutators

[[nodiscard]] Connective CompoundExpression::connective() const noexcept {
  return connective_;
}

std::shared_ptr<Expression>
CompoundExpression::left(std::shared_ptr<Expression> left) noexcept {
  std::shared_ptr<Expression> old = std::move(left_);
  left_ = std::move(left);
  return old;
}

std::shared_ptr<Expression>
CompoundExpression::right(std::shared_ptr<Expression> right) noexcept {
  std::shared_ptr<Expression> old = std::move(right_);
  right_ = std::move(right);
  return old;
}

// Getters

[[nodiscard]] std::shared_ptr<Expression>
CompoundExpression::left() const noexcept {
  return left_;
}

[[nodiscard]] std::shared_ptr<Expression>
CompoundExpression::right() const noexcept {
  return right_;
}

// Evaluate

[[nodiscard]] bool CompoundExpression::evaluate() const {
  switch (connective_) {
  case Connective::NEGATION: {
    return !left_->evaluate();
  }
  case Connective::CONJUNCTION: {
    return left_->evaluate() && right_->evaluate();
  }
  case Connective::DISJUNCTION: {
    return left_->evaluate() || right_->evaluate();
  }
  case Connective::IMPLICATION: {
    return !left_->evaluate() || right_->evaluate();
  }
  case Connective::CONVERSE: {
    return left_->evaluate() || !right_->evaluate();
  }
  case Connective::BICONDITIONAL: {
    bool leftEval = left_->evaluate(), rightEval = right_->evaluate();
    return (leftEval && rightEval) || (!leftEval && !rightEval);
  }
  case Connective::EXCLUSIVE_DISJUNCTION: {
    return left_->evaluate() ^ right_->evaluate();
  }
  default:
    throw std::runtime_error("Error: Invalid CompoundExpression");
  }
}

// Output

void CompoundExpression::print(std::ostream &stream) const {
  if (connective_ == Connective::NEGATION) {
    stream << '!' << *left_;
  } else {
    stream << '(' << *left_ << ' ' << static_cast<char>(connective_) << ' '
           << *right_ << ')';
  }
};
