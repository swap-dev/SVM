#pragma once
#ifndef FLEXIBLE_STACK_TYPE_H
#define FLEXIBLE_STACK_TYPE_H

#include <cstdint>
#include <vector>
#include <stdexcept>

class FlexibleStackException : public std::runtime_error
{
public:
	inline FlexibleStackException(char const* const message) throw()
		: std::runtime_error(message)
	{

	}
	inline virtual char const* what() const throw()
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
	uint64_t _current_mem_idx;
	uint8_t* _data;
	uint64_t _max_size;

	inline void throw_if_empty_stack(const char* message)
	{
		if (this->_current_mem_idx == 0)
		{
			throw FlexibleStackException(message);
		}
	}

public:
	inline FlexibleStack()
	{
		this->_current_mem_idx = 0;
		this->_data = reinterpret_cast<uint8_t*>(malloc(DEFAULT_STACK_MEM_ALLOC_SIZE));
		this->_el_sizes.reserve(DEFAULT_VECTOR_ALLOC_SIZE);
		this->_max_size = DEFAULT_STACK_MEM_ALLOC_SIZE;
	}

	inline ~FlexibleStack()
	{
		free(this->_data);
	}

	template <typename T>
	inline T top()
	{
		throw_if_empty_stack("FlexibleStack::top() called on empty stack");

		// base data pointer + region of memory that contains the data
		return *reinterpret_cast<T*>(this->_data + this->_current_mem_idx - this->_el_sizes.back());
	}

	template <typename T>
	inline void push(T el)
	{
		const uint32_t size = sizeof(el);
		if ((this->_current_mem_idx - 1 + size) > this->_max_size)
		{
			const uint64_t new_size = this->_max_size * 2; // exponential growth memory reallocation
			uint8_t* new_ptr = reinterpret_cast<uint8_t*>(realloc(this->_data, new_size));
			if (new_ptr == nullptr)
				throw FlexibleStackException("Failed to realloc memory during push");

			this->_data = new_ptr;
			this->_max_size = new_size;
		}

		memcpy(this->_data + this->_current_mem_idx, &el, size);
		this->_current_mem_idx += size;
		this->_el_sizes.emplace_back(size);
	}

	inline void pop()
	{
		const uint32_t top_el_size = this->_el_sizes.back();
		this->_current_mem_idx -= top_el_size;
		this->_el_sizes.pop_back();
	}

	inline uint64_t size()
	{
		return this->_current_mem_idx - 1;
	}
};

#endif // !FLEXIBLE_STACK_TYPE_H
