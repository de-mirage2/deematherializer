#include <gtest/gtest.h>

#include <deemath/expression/CompoundExpression.hpp>
#include <deemath/expression/Variable.hpp>

#include <memory>
#include <sstream>

class CompoundExpressionUnitTestFixture : public ::testing::Test {
protected:
  const deemath::expression::Variable P{"_p_", true};
  const deemath::expression::Variable Q{"_q_", false};
};

TEST(CompoundExpressionUnitTest, CompoundExpressionConstructor) {
  auto p = std::make_shared<deemath::expression::Variable>("p", true);
  auto q = std::make_shared<deemath::expression::Variable>("p", true);
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::BICONDITIONAL, p, q);
  SUCCEED();
}

TEST_F(CompoundExpressionUnitTestFixture, CompoundExpressionConstructor) {
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::DISJUNCTION, P.clone(), Q.clone());
  SUCCEED();
}
