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

// Mutators

[[nodiscard]] std::string &Variable::name() noexcept { return name_; }

[[nodiscard]] bool &Variable::value() noexcept { return value_; }

// Evaluate

[[nodiscard]] bool Variable::evaluate() const { return value_; }

// Output

void Variable::print(std::ostream &stream) const { stream << name_; };

} // namespace deemath::expression
