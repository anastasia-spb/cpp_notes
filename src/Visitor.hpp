#pragma once

/*
* Example of a visitor design pattern.
*
* It is easy to add operations but hard to add new classes.
* Instead of defining all operations in the base class,
* one class is defined for each operation - the visitor.
*/

class Visitor;

class Node
{
public:
    virtual void visit(Visitor& visitor) const = 0;
};

class Node_A final : public Node
{
public:
    void visit(Visitor& visitor) const override
    {
        visitor.visit(*this);
    }
};

class Node_B final : public Node
{
public:
    void visit(Visitor& visitor) const override
    {
        visitor.visit(*this);
    }
};

class Visitor
{
public:

    virtual void visit(const Node_A& doc) = 0;
    virtual void visit(const Node_B& doc) = 0;
};

class SubVisitor final : Visitor
{
public:

    void visit(const Node_A& doc) override
    {
        //TODO:
    };

    void visit(const Node_B& doc) override
    {
        //TODO:
    };
};