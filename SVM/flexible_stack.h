#pragma once
#ifndef FLEXIBLE_STACK_TYPE_H
#define FLEXIBLE_STACK_TYPE_H

#include <cstdint>
#include <vector>
#include <stdexcept>

class FlexibleStackException : public std::runtime_error
{
public:
	inline explicit FlexibleStackException(char const* const message) noexcept
		: std::runtime_error(message)
	{

	}
	[[nodiscard]] inline char const* what() const noexcept override
	{
		return exception::what();
	}
};

/// <summary>
/// Data container that behaves like std::stack, but is much faster
/// Works on a contiguous block of memory and can store and retrieve any data type, similar to std::any, without the performance drawbacks of std::any or std::variant
/// </summary>
class FlexibleStack
{
	static constexpr unsigned short DEFAULT_STACK_MEM_ALLOC_SIZE = 1024 * sizeof(int);
	static constexpr unsigned short DEFAULT_VECTOR_ALLOC_SIZE = DEFAULT_STACK_MEM_ALLOC_SIZE;

	std::vector<uint32_t> _el_sizes;
	size_t _current_mem_idx;
	uint8_t* _data;
	size_t _max_size;
    bool _top_el_is_cstring;

	inline void throw_if_empty_stack(const char* message) const
	{
		if (this->_current_mem_idx == 0)
		{
			throw FlexibleStackException(message);
		}
	}

    static inline uint32_t cstring_length(const char* str)
    {
        uint32_t length = 0;
        while (str[length] != '\0') length++;

        return length;
    }

    void realloc_if_no_space(const uint32_t& el_size)
    {
        if ((this->_current_mem_idx - 1 + el_size) > this->_max_size)
        {
            const size_t new_size = this->_max_size * 2; // exponential growth memory reallocation
            auto* new_ptr = reinterpret_cast<uint8_t*>(realloc(this->_data, new_size));
            if (new_ptr == nullptr)
                throw FlexibleStackException("Failed to reallocate memory");

            this->_data = new_ptr;
            this->_max_size = new_size;
        }
    }

    template <typename T>
    inline void store_data(T* el, const uint32_t& size)
    {
        memcpy(this->_data + this->_current_mem_idx, el, size);
        this->_current_mem_idx += size;
        this->_el_sizes.emplace_back(size);
    }

public:
	inline FlexibleStack()
	{
		this->_current_mem_idx = 0;
		this->_data = reinterpret_cast<uint8_t*>(malloc(DEFAULT_STACK_MEM_ALLOC_SIZE));
		this->_el_sizes.reserve(DEFAULT_VECTOR_ALLOC_SIZE);
		this->_max_size = DEFAULT_STACK_MEM_ALLOC_SIZE;
        this->_top_el_is_cstring = false;
	}

	inline ~FlexibleStack()
	{
		free(this->_data);
	}

	template <typename T>
	inline T top()
	{
		throw_if_empty_stack("FlexibleStack::top() called on empty stack");

		// base data pointer + start of memory region containing the data
		return *reinterpret_cast<T*>(this->_data + this->_current_mem_idx - this->_el_sizes.back());
	}

    inline const char* top_cstring()
    {
        if (!this->_top_el_is_cstring) throw FlexibleStackException("FlexibleStack::top_cstring() called on a non-string element");

        return reinterpret_cast<const char*>(this->_data + this->_current_mem_idx - this->_el_sizes.back());
    }

	template <typename T>
	inline void push(T el, uint32_t size = 0)
	{
        if (size == 0) size = sizeof(el);

        realloc_if_no_space(size);
        store_data(&el, size);
        this->_top_el_is_cstring = false;
	}

    inline void push_cstring(const char* el, uint32_t size=0)
    {
        if (size == 0) size = cstring_length(el);

        realloc_if_no_space(size);
        store_data(el, size);
        this->_top_el_is_cstring = true;
    }

	inline void pop()
	{
		const uint32_t top_el_size = this->_el_sizes.back();
		this->_current_mem_idx -= top_el_size;
		this->_el_sizes.pop_back();
	}

	[[nodiscard]] inline size_t size() const
	{
		return this->_current_mem_idx;
	}

    [[nodiscard]] inline uint32_t& top_el_size()
    {
        return this->_el_sizes.back();
    }

    [[nodiscard]] inline const bool& top_el_is_cstring() const
    {
        return this->_top_el_is_cstring;
    }
};

#endif // !FLEXIBLE_STACK_TYPE_H
