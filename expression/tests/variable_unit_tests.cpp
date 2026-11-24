#include "deemath/expression/Expression.hpp"
#include <gtest/gtest.h>

#include <deemath/expression/CompoundExpression.hpp>
#include <deemath/expression/Variable.hpp>

#include <memory>
#include <sstream>

TEST(VariableUnitTest, VariableConstructor) {
  deemath::expression::Variable p{"p", true};
  SUCCEED();
}

TEST(VariableUnitTest, VariablePointerConstructor) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  SUCCEED();
}

TEST(VariableUnitTest, VariablePrintsName) {
  const deemath::expression::Variable p{"p", true};
  std::ostringstream out;
  out << p;
  EXPECT_EQ("p", out.str());
}

TEST(VariableUnitTest, VariablePointerPrintsName) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  std::ostringstream out;
  out << *p;
  EXPECT_EQ("p", out.str());
}

TEST(VariableUnitTest, VariableEvaluate) {
  const deemath::expression::Variable p{"p", true};
  std::ostringstream out;
  out << p.evaluate();
  EXPECT_EQ("1", out.str());
}

TEST(VariableUnitTest, VariablePointerEvaluate) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  std::ostringstream out;
  out << p->evaluate();
  EXPECT_EQ("1", out.str());
}

TEST(VariableUnitTest, VariableCloneToPointer) {
  deemath::expression::Variable p{"p", true};
  auto pPrime =
      std::dynamic_pointer_cast<deemath::expression::Variable>(p.clone());
  std::ostringstream out;
  out << pPrime->evaluate() << p.value(false) << pPrime->evaluate()
      << pPrime->value(false) << pPrime->evaluate();
  EXPECT_EQ("11110", out.str());
}

TEST(VariableUnitTest, VariableNameMutability) {
  deemath::expression::Variable named{"foo", true};
  const std::string &ref = named.name();
  std::ostringstream out;
  out << ref << named.name("bar") << ref << named.name("baz") << ref;
  EXPECT_EQ("foofoobarbarbaz", out.str());
}
