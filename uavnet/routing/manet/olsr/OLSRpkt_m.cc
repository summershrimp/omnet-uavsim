//
// Generated file, do not edit! Created by nedtool 5.1 from uavnet/routing/manet/olsr/OLSRpkt.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "OLSRpkt_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {
namespace inetmanet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(OLSR_pkt)

OLSR_pkt::OLSR_pkt(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->reduceFuncionality_var = false;
    this->pkt_seq_num_var = 0;
    this->sn_var = 0;
    this->send_time_var = 0;
    msg_arraysize = 0;
    this->msg_var = 0;
}

OLSR_pkt::OLSR_pkt(const OLSR_pkt& other) : ::omnetpp::cPacket(other)
{
    msg_arraysize = 0;
    this->msg_var = 0;
    copy(other);
}

OLSR_pkt::~OLSR_pkt()
{
    delete [] this->msg_var;
}

OLSR_pkt& OLSR_pkt::operator=(const OLSR_pkt& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OLSR_pkt::copy(const OLSR_pkt& other)
{
    this->reduceFuncionality_var = other.reduceFuncionality_var;
    this->pkt_seq_num_var = other.pkt_seq_num_var;
    this->sn_var = other.sn_var;
    this->send_time_var = other.send_time_var;
    delete [] this->msg_var;
    this->msg_var = (other.msg_arraysize==0) ? nullptr : new OLSR_msg[other.msg_arraysize];
    msg_arraysize = other.msg_arraysize;
    for (unsigned int i=0; i<msg_arraysize; i++)
        this->msg_var[i] = other.msg_var[i];
}

void OLSR_pkt::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->reduceFuncionality_var);
    doParsimPacking(b,this->pkt_seq_num_var);
    doParsimPacking(b,this->sn_var);
    doParsimPacking(b,this->send_time_var);
    b->pack(msg_arraysize);
    doParsimArrayPacking(b,this->msg_var,msg_arraysize);
}

void OLSR_pkt::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->reduceFuncionality_var);
    doParsimUnpacking(b,this->pkt_seq_num_var);
    doParsimUnpacking(b,this->sn_var);
    doParsimUnpacking(b,this->send_time_var);
    delete [] this->msg_var;
    b->unpack(msg_arraysize);
    if (msg_arraysize==0) {
        this->msg_var = 0;
    } else {
        this->msg_var = new OLSR_msg[msg_arraysize];
        doParsimArrayUnpacking(b,this->msg_var,msg_arraysize);
    }
}

bool OLSR_pkt::reduceFuncionality() const
{
    return this->reduceFuncionality_var;
}

void OLSR_pkt::setReduceFuncionality(bool reduceFuncionality)
{
    this->reduceFuncionality_var = reduceFuncionality;
}

short OLSR_pkt::pkt_seq_num() const
{
    return this->pkt_seq_num_var;
}

void OLSR_pkt::setPkt_seq_num(short pkt_seq_num)
{
    this->pkt_seq_num_var = pkt_seq_num;
}

long OLSR_pkt::sn() const
{
    return this->sn_var;
}

void OLSR_pkt::setSn(long sn)
{
    this->sn_var = sn;
}

double OLSR_pkt::send_time() const
{
    return this->send_time_var;
}

void OLSR_pkt::setSend_time(double send_time)
{
    this->send_time_var = send_time;
}

void OLSR_pkt::setMsgArraySize(unsigned int size)
{
    OLSR_msg *msg_var2 = (size==0) ? nullptr : new OLSR_msg[size];
    unsigned int sz = msg_arraysize < size ? msg_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        msg_var2[i] = this->msg_var[i];
    msg_arraysize = size;
    delete [] this->msg_var;
    this->msg_var = msg_var2;
}

unsigned int OLSR_pkt::msgArraySize() const
{
    return msg_arraysize;
}

OLSR_msg& OLSR_pkt::msg(unsigned int k)
{
    if (k>=msg_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", msg_arraysize, k);
    return this->msg_var[k];
}

void OLSR_pkt::setMsg(unsigned int k, const OLSR_msg& msg)
{
    if (k>=msg_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", msg_arraysize, k);
    this->msg_var[k] = msg;
}

class OLSR_pktDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OLSR_pktDescriptor();
    virtual ~OLSR_pktDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(OLSR_pktDescriptor)

OLSR_pktDescriptor::OLSR_pktDescriptor() : omnetpp::cClassDescriptor("inet::inetmanet::OLSR_pkt", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

OLSR_pktDescriptor::~OLSR_pktDescriptor()
{
    delete[] propertynames;
}

bool OLSR_pktDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OLSR_pkt *>(obj)!=nullptr;
}

const char **OLSR_pktDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "omitGetVerb",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OLSR_pktDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OLSR_pktDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OLSR_pktDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OLSR_pktDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reduceFuncionality",
        "pkt_seq_num",
        "sn",
        "send_time",
        "msg",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OLSR_pktDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reduceFuncionality")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pkt_seq_num")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sn")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "send_time")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OLSR_pktDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "short",
        "long",
        "double",
        "OLSR_msg",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OLSR_pktDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *OLSR_pktDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int OLSR_pktDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OLSR_pkt *pp = (OLSR_pkt *)object; (void)pp;
    switch (field) {
        case 4: return pp->msgArraySize();
        default: return 0;
    }
}

const char *OLSR_pktDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OLSR_pkt *pp = (OLSR_pkt *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OLSR_pktDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OLSR_pkt *pp = (OLSR_pkt *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->reduceFuncionality());
        case 1: return long2string(pp->pkt_seq_num());
        case 2: return long2string(pp->sn());
        case 3: return double2string(pp->send_time());
        case 4: {std::stringstream out; out << pp->msg(i); return out.str();}
        default: return "";
    }
}

bool OLSR_pktDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OLSR_pkt *pp = (OLSR_pkt *)object; (void)pp;
    switch (field) {
        case 0: pp->setReduceFuncionality(string2bool(value)); return true;
        case 1: pp->setPkt_seq_num(string2long(value)); return true;
        case 2: pp->setSn(string2long(value)); return true;
        case 3: pp->setSend_time(string2double(value)); return true;
        default: return false;
    }
}

const char *OLSR_pktDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(OLSR_msg));
        default: return nullptr;
    };
}

void *OLSR_pktDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OLSR_pkt *pp = (OLSR_pkt *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->msg(i)); break;
        default: return nullptr;
    }
}

} // namespace inetmanet
} // namespace inet

