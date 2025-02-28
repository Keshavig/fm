#pragma once

#include "parser.h"
#include "node.h"
#include <cstdint>

class Matek final {
public:
    Matek(void) = default;
    Matek(const Matek& mtk) = delete;

    void expression(const std::string& expr);
    void disableChecks(void);
    std::unique_ptr<BaseAst> parse();

    bool setprecision(size_t precision);

    void printast(void) const;
    real_t evaluate();

private:
    real_t privateEval(const std::unique_ptr<BaseAst>& ast);
    bool m_docheck = true;

    size_t m_Precision = DEFAULT_PRECISION;

    std::string m_expression;
    std::unique_ptr<BaseAst> m_ast;
};
