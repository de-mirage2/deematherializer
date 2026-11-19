#include <gtest/gtest.h>

#include <deemath/expression/CompoundExpression.hpp>
#include <deemath/expression/Variable.hpp>

#include <memory>
#include <sstream>

TEST(ExpressionTest, SmokeTest) { SUCCEED(); }

TEST(ExpressionTest, VariableConstructor) {
  deemath::expression::Variable p("p", true);
  SUCCEED();
}

TEST(ExpressionTest, VariablePointerConstructor) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  SUCCEED();
}

TEST(ExpressionTest, VariablePrintsName) {
  const deemath::expression::Variable p("p", true);
  std::ostringstream out;
  out << p;
  EXPECT_EQ(out.str(), "p");
}

TEST(ExpressionTest, VariablePointerPrintsName) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  std::ostringstream out;
  out << *p;
  EXPECT_EQ(out.str(), "p");
}

TEST(ExpressionTest, VariableEvaluate) {
  const deemath::expression::Variable p("p", true);
  std::ostringstream out;
  out << p.evaluate();
  EXPECT_EQ(out.str(), "1");
}

TEST(ExpressionTest, VariablePointerEvaluate) {
  std::shared_ptr<deemath::expression::Variable> p =
      std::make_shared<deemath::expression::Variable>("p", true);
  std::ostringstream out;
  out << p->evaluate();
  EXPECT_EQ(out.str(), "1");
}
