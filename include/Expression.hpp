#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>
#include <ostream>

class Expression {
private:
  friend inline std::ostream &operator<<(std::ostream &stream,
                                         Expression const &expression);

protected:
  virtual void print(std::ostream &stream) const = 0;

public:
  virtual ~Expression() = default;

  virtual std::shared_ptr<Expression> clone() const = 0;

  [[nodiscard]] virtual bool evaluate() const = 0;
};

inline std::ostream &operator<<(std::ostream &stream,
                                Expression const &expression) {
  expression.print(stream);
  return stream;
};

#endif
