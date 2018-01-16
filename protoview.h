#ifndef PROTOVIEW_H
#define PROTOVIEW_H

template <class P>
class ProtoView
{

public:
    virtual ~ProtoView(void) {}
    virtual P * Clone(void) const = 0;
    virtual void Display(void) const = 0;
    virtual void Close(void) const = 0;
};

#endif // PROTOVIEW_H

