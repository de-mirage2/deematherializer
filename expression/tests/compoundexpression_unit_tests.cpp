#include <gtest/gtest.h>

#include <deemath/expression/CompoundExpression.hpp>
#include <deemath/expression/Connective.hpp>
#include <deemath/expression/Variable.hpp>

#include <memory>
#include <sstream>

class CompoundExpressionUnitTestFixture : public ::testing::Test {
protected:
  const deemath::expression::Variable P{"_p_", true};
  const deemath::expression::Variable Q{"_q_", false};
  const deemath::expression::Variable R{"_r_", true};
};

TEST(CompoundExpressionUnitTest, CompoundExpressionConstructor) {
  auto p = std::make_shared<deemath::expression::Variable>("p", true);
  auto q = std::make_shared<deemath::expression::Variable>("q", true);
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::BICONDITIONAL, p, q);
  SUCCEED();
}

TEST_F(CompoundExpressionUnitTestFixture,
       CompoundExpressionConstructorFromClones) {
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::DISJUNCTION, P.clone(), Q.clone());
  EXPECT_EQ(alpha.connective(), deemath::expression::Connective::DISJUNCTION);
}

TEST_F(CompoundExpressionUnitTestFixture,
       CompoundExpressionManipulatingSharedPointers) {
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::IMPLICATION, P.clone(), R.clone());
  EXPECT_EQ(alpha.evaluate(), true);
  alpha.right(Q.clone());
  EXPECT_EQ(alpha.evaluate(), false);
  alpha.left(Q.clone());
  EXPECT_EQ(alpha.evaluate(), true);
}

TEST_F(CompoundExpressionUnitTestFixture, CompoundExpressionNested) {
  auto alpha = std::make_shared<deemath::expression::CompoundExpression>(
      deemath::expression::Connective::IMPLICATION, P.clone(), Q.clone());
  auto beta = std::make_shared<deemath::expression::CompoundExpression>(
      deemath::expression::Connective::DISJUNCTION, P.clone(), R.clone());
  deemath::expression::CompoundExpression omega(
      deemath::expression::Connective::IMPLICATION, alpha, beta);
  EXPECT_EQ(omega.evaluate(), true);
}

TEST_F(CompoundExpressionUnitTestFixture, CompoundExpressionChangeInternal) {
  auto p = std::make_shared<deemath::expression::Variable>("p", true);
  auto q = std::make_shared<deemath::expression::Variable>("q", true);
  deemath::expression::CompoundExpression alpha(
      deemath::expression::Connective::BICONDITIONAL, p, q);
  EXPECT_EQ(alpha.evaluate(), true);
  p->value(false);
  EXPECT_EQ(alpha.evaluate(), false);
  q->value(false);
  EXPECT_EQ(alpha.evaluate(), true);
}

TEST_F(CompoundExpressionUnitTestFixture, CompoundExpressionDeMorgansLaws) {
  auto p = std::make_shared<deemath::expression::Variable>("p", true);
  auto q = std::make_shared<deemath::expression::Variable>("q", true);

  deemath::expression::CompoundExpression unexpanded_disjunction(
      deemath::expression::Connective::NEGATION,
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::DISJUNCTION, p, q));

  deemath::expression::CompoundExpression expanded_disjunction(
      deemath::expression::Connective::CONJUNCTION,
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::NEGATION, p),
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::NEGATION, q));

  deemath::expression::CompoundExpression unexpanded_conjunction(
      deemath::expression::Connective::NEGATION,
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::CONJUNCTION, p, q));

  deemath::expression::CompoundExpression expanded_conjunction(
      deemath::expression::Connective::DISJUNCTION,
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::NEGATION, p),
      std::make_shared<deemath::expression::CompoundExpression>(
          deemath::expression::Connective::NEGATION, q));

  for (int i = 0; i < 1 << 2; i++) {
    p->value(i & 1 << 0);
    q->value(i & 1 << 1);
    EXPECT_EQ(unexpanded_disjunction.evaluate(),
              expanded_disjunction.evaluate());
    EXPECT_EQ(unexpanded_conjunction.evaluate(),
              expanded_conjunction.evaluate());
  }
}
