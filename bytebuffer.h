//
// Created by 张林星 on 2022/5/24.
//

#ifndef HELLOWORLD_BYTEBUFFER_H
#define HELLOWORLD_BYTEBUFFER_H

#include <iostream>

class ByteBuffer {

public :
    class out_of_range : public std::exception {
    public:
        out_of_range(uint32_t p, uint32_t l, uint32_t s);

        virtual ~out_of_range() throw() {};

        virtual const char *what() const throw();

    private:
        static const uint32_t MAX_ERROR_MSG_LEN = 256;
        char errmsg_[MAX_ERROR_MSG_LEN];
    };

public:
    explicit ByteBuffer();

    explicit ByteBuffer(uint32_t size);

    explicit ByteBuffer(const ByteBuffer &rhs);

    ByteBuffer(const char *data, uint32_t offset, uint32_t size);

    ByteBuffer &assign(const char *data, uint32_t offset, uint32_t size);

    ByteBuffer &wrap(char *data, uint32_t offset, uint32_t size);

    ByteBuffer &operator=(const ByteBuffer &rhs);

    virtual ~ByteBuffer();

public:
    template <typename T> ByteBuffer & put(const T &e) throw (out_of_range);
    template <typename T> ByteBuffer & get (T & e) throw (out_of_range);
    template <typename T> ByteBuffer & put (const std::vector<T> & v) throw (out_of_range) ;
    template <typename T> ByteBuffer & get (std::vector<T> & v) throw (out_of_range);
    template <typename T> ByteBuffer & operator<<(const T &e) throw (out_of_range) { return put(e); }
    template <typename T> ByteBuffer & operator>>(T &e) throw (out_of_range) { return get(e); }


protected:
    char *data;
    uint32_t size_;
    uint32_t position_;
    bool own_;

};

#endif //HELLOWORLD_BYTEBUFFER_H
