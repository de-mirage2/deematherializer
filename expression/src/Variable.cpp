#include <deemath/expression/Expression.hpp>
#include <deemath/expression/Variable.hpp>

#include <string>

namespace deemath::expression {

// Constructors

Variable::Variable(std::string name, bool value) : name_(name), value_(value) {}

// Clone

std::shared_ptr<Expression> Variable::clone() const {
  return std::make_shared<Variable>(*this);
}

// Getters

[[nodiscard]] const std::string &Variable::name() const noexcept {
  return name_;
}

[[nodiscard]] const bool &Variable::value() const noexcept { return value_; }

[[nodiscard]] bool value(bool value) noexcept;

// Mutators

std::string Variable::name(std::string name) noexcept {
  std::string prev_name = name_;
  name_ = name;
  return prev_name;
}

bool Variable::value(bool value) noexcept {
  bool prev_value = value_;
  value_ = value;
  return prev_value;
}

// Evaluate

[[nodiscard]] bool Variable::evaluate() const { return value_; }

// Output

void Variable::print(std::ostream &stream) const { stream << name_; };

} // namespace deemath::expression
