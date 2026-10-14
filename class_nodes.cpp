#include "class_nodes.h"

int globNodeId = 0;

ProgramNode:: ProgramNode(ItemListNode* itemlist)
{
	this->NodeId = ++globNodeId;
	this->itemlist = itemlist;
	cout << "exist";
}

SubProgramItemNode::SubProgramItemNode(type Type, string* name, FuncParamListNode* paramlist, TypeNode* varrtype, DeclarationListNode* decllist, StmtListNode* stmtlst)
{
	this->NodeId = ++globNodeId;
	this->Type = Type;
	this->name = name;
	this->paramlist = paramlist;
	this->varrtype = varrtype;
	this->decllist = decllist;
	this->stmtlst = stmtlst;
}


ItemListNode:: ItemListNode(SubProgramItemNode* item)
{
	this->NodeId = ++globNodeId;
	this->items = new list<SubProgramItemNode*>{ item };
}

ItemListNode:: ItemListNode(ItemListNode* list) {
	this->NodeId = ++globNodeId;
	this->items = list->items;
}


ItemListNode* ItemListNode::Append(ItemListNode* list, SubProgramItemNode* item) {
	list->items->push_back(item);
	return list;
}

DeclarationNode* DeclarationNode:: TypeDeclaration(type Type, string* name, RangeNode* rng, TypeNode* varrtype) {
	DeclarationNode* dec = new DeclarationNode(DeclarationNode::type_dec);
	dec->NodeId = ++globNodeId;
	dec->Type = Type;
	dec->name = name;
	dec->rng = rng;
	dec->varrtype = varrtype;
	return dec;
}

DeclarationNode* DeclarationNode::VarDeclaration(type Type, VarListNode* vlist, TypeNode* varrtype) {
	DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
	dec->NodeId = ++globNodeId;
	dec->Type = Type;
	dec->vlist = vlist;
	dec->varrtype = varrtype;
	return dec;
}

DeclarationNode* DeclarationNode::VarDeclarationArray(type Type, VarListNode* vlist, RangeNode* rng, TypeNode* varrtype) {
	DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
	dec->NodeId = ++globNodeId;
	dec->Type = Type;
	dec->vlist = vlist;
	dec->rng = rng;
	dec->varrtype = varrtype;
	return dec;
}

DeclarationNode* DeclarationNode:: VarDeclarationAssignment(type Type, VarListNode* vlist, TypeNode* varrtype, ExprNode* expr) {
	DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
	dec->NodeId = ++globNodeId;
	dec->Type = Type;
	dec->vlist = vlist;
	dec->varrtype = varrtype;
	dec->expr = expr;
	return dec;
}

DeclarationListNode* DeclarationListNode::Append(DeclarationListNode* list, DeclarationNode* dec) {
	list->decs->push_back(dec);
	return list;
}

VarListNode::VarListNode(string* name) {

	VarName* var = new VarName(name);
	this->NodeId = ++globNodeId;
	this->vars = new list<VarName*>{ var };
}

VarListNode::VarListNode(VarListNode* varlst) {
	this->NodeId = ++globNodeId;
	this->vars = varlst->vars;
}
VarListNode* VarListNode:: Append(VarListNode* list, string* name) {
	VarName* var = new VarName(name);
	list->vars->push_back(var);
	return list;
}

VarName::VarName(string* name)
{
	this->NodeId = ++globNodeId;
	this->name = name;
}

FuncParamListNode::FuncParamListNode(DeclarationNode* var_dec)
{
	this->NodeId = ++globNodeId;
	this->params = new list<DeclarationNode*>{ var_dec };
}

FuncParamListNode::FuncParamListNode(FuncParamListNode* list) {
	this->NodeId = ++globNodeId;
	this->params = list->params;
}

FuncParamListNode* FuncParamListNode::Append(FuncParamListNode* list, DeclarationNode* var_dec) {
	list->params->push_back(var_dec);
	return list;
}

StmtNode* StmtNode::StmtFromReturn(ExprNode* Expr)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = return_;
	stmt->Expr = Expr;
	return stmt;
}

StmtNode* StmtNode:: StmtFromWhileLoop(ExprNode* Expr, StmtListNode* list)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = whileloop;
	stmt->Expr = Expr;
	stmt->stmtlst = list;
	return stmt;
}

StmtNode* StmtNode::StmtFromForLoop(string* name, RangeNode* range, StmtListNode* list)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = forloop;
	stmt->Name = name;
	stmt->rng = range;
	stmt->stmtlst = list;
	return stmt;
}

StmtNode* StmtNode::StmtFromSimpleLoop(StmtListNode* list)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = simpleLoop;
	stmt->stmtlst = list;
	return stmt;
}

StmtNode* StmtNode::StmtFromIdAndExpr(string* Name, ExprListNode* Expr_list)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = id_;
	stmt->Name = Name;
	stmt->Expr_list = Expr_list;
	return stmt;
}

StmtNode* StmtNode::StmtFromIfWithElsif(ExprNode* Expr, StmtListNode* list, ElsifStmtListNode* elsif_lst, ElseStmtNode* else_stmt)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = if_;
	stmt->Expr = Expr;
	stmt->stmtlst = list;
	stmt->elsif_lst = elsif_lst;
	stmt->else_stmt = else_stmt;
	return stmt;
}

StmtNode* StmtNode::StmtFromIf(ExprNode* Expr, StmtListNode* list, ElseStmtNode* else_stmt)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = if_;
	stmt->Expr = Expr;
	stmt->stmtlst = list;
	stmt->else_stmt = else_stmt;
	return stmt;
}

StmtNode* StmtNode::StmtFromExit(ExprNode* Expr)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = exit_;
	stmt->Expr = Expr;
	return stmt;
}

StmtNode* StmtNode::StmtFromAssigment(ExprNode* left, ExprNode* right)
{
	StmtNode* stmt = new StmtNode();
	stmt->NodeId = ++globNodeId;
	stmt->Type = assigment_;
	stmt->Left_operator = left;
	stmt->Right_operator = right;
	return stmt;
}

ElsifStmtListNode::ElsifStmtListNode(ElsifStmtNode* elsif)
{
	this->NodeId = ++globNodeId;
	this->elsifs = new list<ElsifStmtNode*>{ elsif };
}

ElsifStmtListNode::ElsifStmtListNode(ElsifStmtListNode* list) {
	this->NodeId = ++globNodeId;
	this->elsifs = list->elsifs;
}

ElsifStmtListNode* ElsifStmtListNode::Append(ElsifStmtListNode* list, ElsifStmtNode* elsif) {
	list->elsifs->push_back(elsif);
	return list;
}

ElsifStmtNode::ElsifStmtNode(ExprNode* expr, StmtListNode* lst)
{
	this->NodeId = ++globNodeId;
	this->Expr = expr;
	this->stmtlst = lst;
}

ElseStmtNode::ElseStmtNode(StmtListNode* lst)
{
	this->NodeId = ++globNodeId;
	this->stmtlst = lst;
}

StmtListNode::StmtListNode(StmtNode* stmt)
{
	this->NodeId = ++globNodeId;
	this->stmts = new list<StmtNode*>{ stmt };
}

StmtListNode::StmtListNode(StmtListNode* list) {
	this->NodeId = ++globNodeId;
	this->stmts = list->stmts;
}

StmtListNode* StmtListNode:: Append(StmtListNode* list, StmtNode* stmt) {
	list->stmts->push_back(stmt);
	return list;
}

ExprNode* ExprNode::ExprFromCharConst(type Type, char value) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Char = value;
	return expr;
}

ExprNode* ExprNode::ExprFromBoolConst(type Type, bool value) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Bool = value;
	return expr;
}

ExprNode* ExprNode::ExprFromStringConst(type Type, string* value) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->String = value;
	return expr;
}

ExprNode* ExprNode::ExprFromIntConst(type Type, int value) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Integer = value;
	return expr;
}

ExprNode* ExprNode::ExprFromFloatConst(type Type, float value) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Float = value;
	return expr;
}

ExprNode* ExprNode::ExprFromId(type Type, string* Name) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Name = Name;
	return expr;
}

ExprNode* ExprNode::ExprOperation(type Type, ExprNode* left, ExprNode* right) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Left_operator = left;
	expr->Right_operator = right;
	return expr;
}

ExprNode* ExprNode::ExprFromFuncCall(type Type, string* Name, ExprListNode* Expr_list) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Name = Name;
	expr->Expr_list = Expr_list;
	return expr;
}

ExprNode* ExprNode::ExprFromExprLiteral(type Type, ExprListNode* Expr_list) {
	ExprNode* expr = new ExprNode();
	expr->NodeId = ++globNodeId;
	expr->Type = Type;
	expr->Expr_list = Expr_list;
	return expr;
}

ExprListNode::ExprListNode(ExprNode* expr) {
	this->NodeId = ++globNodeId;
	this->exprs = new list<ExprNode*>{ expr };
}

ExprListNode::ExprListNode(ExprListNode* exprs_list) {
	this->NodeId = ++globNodeId;
	this->exprs = exprs_list->exprs;
}

ExprListNode* ExprListNode::Append(ExprListNode* list, ExprNode* expr) {
	list->exprs->push_back(expr);
	return list;
}

RangeNode::RangeNode(ExprNode* left, ExprNode* right)
{
	this->NodeId = ++globNodeId;
	this->Left_operator = left;
	this->Right_operator = right;
}

TypeNode::TypeNode(type Type) {
	this->NodeId = ++globNodeId;
	this->Type = Type;
}

TypeNode::TypeNode(type Type, string* Name) {
	this->NodeId = ++globNodeId;
	this->Type = Type;
	this->Name = Name;
}

DeclarationNode::DeclarationNode(type Type)
{
	this->NodeId = ++globNodeId;
	this->Type = Type;
}

DeclarationListNode::DeclarationListNode(DeclarationNode* dec)
{
	this->NodeId = ++globNodeId;
	this->decs = new list<DeclarationNode*>{ dec };
}

DeclarationListNode::DeclarationListNode(DeclarationListNode* list) {
	this->NodeId = ++globNodeId;
	this->decs = list->decs;
}