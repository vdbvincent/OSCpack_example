#ifndef PROTOMODEL_H
#define PROTOMODEL_H

template <class T>
class ProtoModel
{
public:
    virtual ~ProtoModel(void){}
    virtual T * Clone(void) const = 0;
};

#endif // PROTOMODEL_H
