#pragma once
//This is where we construct the building blocks for objects such as templates for structs or functions of different return types that can be used muliple times
#ifndef PAIR_H
#define PAIR_H

template <typename T>
struct Pair					// Create a object with two variable types 
{
	T first{};
	T second{};
};

template <typename T>
constexpr T max(Pair<T> p) // Create a function that determines the greater of the two
{
	return (p.first > p.second ? p.first : p.second);
}

#endif