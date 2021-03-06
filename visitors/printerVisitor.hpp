//  ----------------------------------------------------------------------------
//  Header file for the ExpressionPrinter class.        ExpressionPrinter.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 16, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef EXP_PRINTERVISITOR_HPP
#define EXP_PRINTERVISITOR_HPP

#include "ast.hpp"
#include "visitor.hpp"
#include <sstream>

class ExpressionPrinter : public ExpressionVisitor {
  private:
    std::stringstream os;

    void visitBinaryExpression(const BinaryExpression& binExpr,
                               const std::string& infix) {
        binExpr.left().accept(*this);
        os << infix;
        binExpr.right().accept(*this);
    }

  public:
    ExpressionPrinter() = default;

    std::string print(Expression& expr) {
        expr.accept(*this);
        return os.str();
    }

    void visit(const AddExpression& addExpr) override {
        os << "(";
        visitBinaryExpression(addExpr, " + ");
        os << ")";
    }
    void visit(const MultiplyExpression& mulExpr) override {
        os << "(";
        visitBinaryExpression(mulExpr, " * ");
        os << ")";
    }
    void visit(const NumberExpression& numExpr) override {
        os << numExpr.getNumber();
    }
};

#endif // EXP_PRINTERVISITOR_HPP
