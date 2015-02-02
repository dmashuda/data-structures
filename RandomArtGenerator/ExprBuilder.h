#ifndef _EXPRBUILDER_H_
#define _EXPRBUILDER_H_

class ExprNode;

class ExprBuilder {
private:
    // You can add fields here, but you might not need any

    ExprNode *getCanidate(int level) const;
    // Copy constructor and assignment operator are not allowed:
    // don't implement them
    ExprBuilder(const ExprBuilder &);
    ExprBuilder& operator=(const ExprBuilder &);

public:
    ExprBuilder();    
    ~ExprBuilder();

    // Build a random expression
    ExprNode *build() const;

    // TODO: add additional methods
};


#endif
