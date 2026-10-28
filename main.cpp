#include "./include/CompoundExpression.hpp"
#include "./include/Connective.hpp"
#include "./include/Variable.hpp"

#include <iostream>
#include <memory>

int main() {
  std::cout << std::boolalpha;

  auto p = std::make_shared<Variable>("p", true),
       q = std::make_shared<Variable>("q", false),
       r = std::make_shared<Variable>("r", true);
  std::cout << "p->name() p->evaluate() = " << p->name() << ' ' << p->evaluate()
            << '\n';
  std::cout << "q->name() q->evaluate() = " << q->name() << ' ' << q->evaluate()
            << '\n';
  std::cout << "r->name() r->evaluate() = " << r->name() << ' ' << r->evaluate()
            << '\n';

  auto alpha =
      std::make_shared<CompoundExpression>(Connective::CONJUNCTION, p, q);

  std::cout << "*alpha alpha->evaluate() = " << *alpha << ' '
            << alpha->evaluate() << '\n';

  auto omega = std::make_shared<CompoundExpression>(
      Connective::EXCLUSIVE_DISJUNCTION, p, alpha);

  std::cout << "*omega omega->evaluate() = " << *omega << ' '
            << omega->evaluate() << '\n';

  auto beta =
      std::make_shared<CompoundExpression>(Connective::IMPLICATION, q, r);

  std::cout << "*beta beta->evaluate() = " << *beta << ' ' << beta->evaluate()
            << '\n';

  omega->left(beta);

  std::cout << "changed; *omega omega->evaluate() = " << *omega << ' '
            << omega->evaluate() << '\n';
  return 0;
}
