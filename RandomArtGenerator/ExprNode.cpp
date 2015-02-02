#include <cmath>
#include "ExprNode.h"
#include <cstdio>

// No ExprNode will have more than this number of children
const int MAX = 3;
#define PI 3.14159265

//////////////////////////////////////////////////////////////
// Methods for ExprNode (superclass)
//////////////////////////////////////////////////////////////

ExprNode::ExprNode()
{
	directChildren = 0;
	children = new ExprNode*[MAX+1];
}

ExprNode::~ExprNode()
{
	delete[] children;
}

void ExprNode::addChild(ExprNode *child){
	children[directChildren] = child;
	directChildren++;
}

int ExprNode::getNumChildren() const{
	return directChildren;
}

ExprNode* ExprNode::getChild(int index) const{
	return children[index];
}



// TODO: implement method(s), e.g., to add a child node, to get a child node, etc.


//////////////////////////////////////////////////////////////
// Methods for XNode
//////////////////////////////////////////////////////////////
XNode::XNode()
{
}

XNode::~XNode()
{

}
double XNode::evaluate(double x, double y) const
{
    return x;
}

std::string XNode::exprAsString() const
{
    return "x";
}


//////////////////////////////////////////////////////////////
// Methods for YNode
//////////////////////////////////////////////////////////////
YNode::YNode()
{
}

YNode::~YNode()
{

}

double YNode::evaluate(double x, double y) const
{
    return y;
}

std::string YNode::exprAsString() const
{
    return "y";
}

//////////////////////////////////////////////////////////////
// Methods for SinNode
//////////////////////////////////////////////////////////////
SinNode::SinNode()
{
}

SinNode::~SinNode()
{
}

double SinNode::evaluate(double x, double y) const
{
    double num =sin (PI* children[0]->evaluate(x,y));
    return num;
}

std::string SinNode::exprAsString() const
{
    std::string x = std::string("sin(π *") + children[0]->exprAsString() + std::string(")");
    return x;
}

//////////////////////////////////////////////////////////////
// Methods for CosNode
//////////////////////////////////////////////////////////////
CosNode::CosNode()
{
}

CosNode::~CosNode()
{
}

double CosNode::evaluate(double x, double y) const
{
	double num =cos (PI* children[0]->evaluate(x,y));
    return num;
}

std::string CosNode::exprAsString() const
{
	std::string x = std::string("cos(π *") + children[0]->exprAsString() + std::string(")");
    return x;
}

//////////////////////////////////////////////////////////////
// Methods for AverageNode
//////////////////////////////////////////////////////////////
AverageNode::AverageNode()
{
}

AverageNode::~AverageNode()
{
}

double AverageNode::evaluate(double x, double y) const
{
	double sum = 0;

	for (int i = 0; i < directChildren; ++i)
	{
		sum+= children[i]->evaluate(x,y);
	}
	
    return sum/directChildren;
}

std::string AverageNode::exprAsString() const
{
	std::string build = "";

	for (int i = 0; i < directChildren; ++i)
	{
		build+=children[i]->exprAsString();
		
		if (i != directChildren-1)
		{
			build+=",";
		}
	}
	std::string x = std::string("average(") + build + std::string(")");
    return x;
}
