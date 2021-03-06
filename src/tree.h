#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum NodeType
{
	STMT
};

enum StmtType // 一个语句块
{
	MAIN_STMT,
	DECL_STMT,
	ASS_STMT,
	COMP_STMT,
	WHILE_STMT,
	IF_STMT,
	FOR_STMT,
	RETURN_STMT,
	PRINTF_STMT,
	SCANF_STMT,
}
;

enum exprType
{
	TYPE_expr,
	OP_expr,
	ID_expr,
	CONST_expr,
};
enum TYPETYPE
{
	INT,
	CHAR,
	STRING,
};
enum OperatorType
{
	SUM,
	SUB,
	MUL,
	DIV,
	MOD,// 加减乘除
	AND,
	OR,
	NOT,// 与或非
	EQ,
	UEQ,
	BEQ,
	LEQ,
	BQ,
	LQ,
	ASSIGN,//= != >= <= > < =
};



struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    void genNodeId();

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);

public:
    TreeNode(int lineno, NodeType type);
};

#endif
