#pragma once

//base class 
// itarate thru all init, update and draw functions
// of all derivate classes



#define numberOFComponents 4

class Component;

struct Help_Component
{
    Component** structComponents = new Component * [numberOFComponents];
};

class Component
{
    
public:

    //Array of components!!
    static Help_Component components;
    
    virtual ~Component() {};
    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};
};