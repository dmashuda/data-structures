#include <cstdlib>
#include <cassert>
#include "ExprBuilder.h"
#include "ExprNode.h"
#include <cstdio>


// Each random expression tree can have up to this many levels
const int MAX_LEVEL = 12;

ExprBuilder::ExprBuilder()
{
	//srand(1);
}

ExprBuilder::~ExprBuilder()
{
}

ExprNode *ExprBuilder::build() const
{
	
    // Suggestion: call a recursive helper method that takes the
    // maximum number of tree levels as a parameter

    // TODO: return a random expression tree instead of this XNode
    return getCanidate(1);
}

ExprNode *ExprBuilder::getCanidate(int level) const{
	level++;
	//exponential backoff
	if (level >= (MAX_LEVEL))
	{
		//printf("backoff\n");
		int chance = rand() %2;
		if (chance == 0)
		{
			return new YNode();
		}
		else{
			return new XNode();
		}
	}


	ExprNode *newNode;
	int roll = rand() % 10;
	if (roll == 0)
	{
		//printf("XNode\n");
		return new XNode();
	}
	else if (roll == 1)
	{
		//printf("YNode\n");
		return new YNode();
	}
	else if (roll == 2 || roll == 3)
	{
		//printf("AverageNode\n");
		newNode = new AverageNode();
		int numNodes = (rand() %2)+2;// 2 or 3

		for (int i = 0; i < numNodes; ++i)
		{
			newNode->addChild(getCanidate(level));
		}

		return newNode;

	}
	else if (roll == 4 || roll == 5 || roll == 6)
	{
		//printf("SinNode\n");
		newNode = new SinNode();
		newNode->addChild(getCanidate(level));
		return newNode;
	}
	else if (roll == 7 || roll == 8 || roll == 9)
	{
		//printf("CosNode\n");
		newNode = new CosNode();
		newNode->addChild(getCanidate(level));
		return newNode;
	}else{
		printf("tailx should never happen\n");
		newNode = new XNode();
	}

	return newNode;
}
