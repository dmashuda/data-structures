#ifndef _EXPRNODE_H_
#define _EXPRNODE_H_

#include <string>
#include <list>

class ExprNode {
private:
    // TODO: add field(s), e.g., to keep track of child nodes
    

    // copy constructor and assignment are forbidden: do not implement them
    ExprNode(const ExprNode &);
    ExprNode& operator=(const ExprNode &);
protected:
    ExprNode** children;
    int directChildren;
public:
    ExprNode();
    virtual ~ExprNode();

    // Evaluate for given x and y values
    virtual double evaluate(double x, double y) const{return -1;};

    // Generate a textual representation of the function represented
    // by this node and return it as a string.
    virtual std::string exprAsString() const {return "";};

    // TODO: add method(s), e.g., to add a child node, to get a child node, etc.
    void addChild(ExprNode *child);
    int getNumChildren() const;
    ExprNode *getChild(int index) const;
};



// Example ExprNode implementation: XNode, which just returns the
// x coordinate value.
class XNode : public ExprNode {
private:
    // copy constructor and assignment operator are forbidden
    XNode(const XNode &);
    XNode& operator=(const XNode &);

public:
    XNode();
    virtual ~XNode();

    virtual double evaluate(double x, double y) const;
    virtual std::string exprAsString() const;
};

// Y Node
class YNode : public ExprNode {
private:
    // copy constructor and assignment operator are forbidden
    YNode(const YNode &);
    YNode& operator=(const YNode &);

public:
    YNode();
    virtual ~YNode();

    virtual double evaluate(double x, double y) const;
    virtual std::string exprAsString() const;
};

// Sin Node
class SinNode : public ExprNode {
private:
    // copy constructor and assignment operator are forbidden
    SinNode(const SinNode &);
    SinNode& operator=(const SinNode &);

public:
    SinNode();
    virtual ~SinNode();

    virtual double evaluate(double x, double y) const;
    virtual std::string exprAsString() const;
};

//Cosine Node
class CosNode : public ExprNode {
private:
    // copy constructor and assignment operator are forbidden
    CosNode(const CosNode &);
    CosNode& operator=(const CosNode &);

public:
    CosNode();
    virtual ~CosNode();

    virtual double evaluate(double x, double y) const;
    virtual std::string exprAsString() const;
};

//Average Node
class AverageNode : public ExprNode {
private:
    // copy constructor and assignment operator are forbidden
    AverageNode(const AverageNode &);
    AverageNode& operator=(const AverageNode &);

public:
    AverageNode();
    virtual ~AverageNode();

    virtual double evaluate(double x, double y) const;
    virtual std::string exprAsString() const;
};

#endif
