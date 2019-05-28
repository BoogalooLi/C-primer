#ifndef SV_H
#define SV_H

#include<memory>
#include<string>
#include<utility>
#include<initializer_list>

class SV
{
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }
    std::pair<std::string*, std::string*>
        alloc_n_copy(const std::string*, const std:: string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
public:
    SV():elements(nullptr), first_free(nullptr), cap(nullptr){};
    SV(std::initialize_list<std::string>);
    SV(const SV&);
    SV& operator=(const SV&);
    ~SV();
    

    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}
};

void SV::push_back(const std::string &s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
    SV::alloc_n_copy(const std::string *b, const std::string *e){
        auto data = alloc.allocate(e - b);
        return {data, std::uninitialized_copy(b, e, data)};
    }

void SV::free(){
    if(elements){
        for(auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

SV::SV(const SV& s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

SV::~SV(){
    free();
}

SV& SV::operator=(const SV& rhs){
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void SV::reallocate(){
    auto newcapacity = size() ? size()*2 : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
     
}

SV::SV(initialize_list<std::string> l){
        auto newdata = alloc_n_copy(l.begin(), l.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }

#endif
