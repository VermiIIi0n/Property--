#pragma once

#include <functional>

/**
 * @brief Property Class
 *
 * @tparam T the type of the property
 * @param getter const std::function<T()> getter
 * @param setter const std::function<void(const T)> setter
 */
template <typename T>
class Property
{
protected:
    const std::function<T()> getter;
    const std::function<void(const T)> setter;

public:
    typedef std::function<T()> Getter;
    typedef std::function<void(const T)> Setter;
    Property() = delete;
    /**
     * @brief Construct a new Property object.
     *
     * @param getter
     * @param setter
     */
    Property(std::function<T()> getter, std::function<void(const T)> setter = nullptr)
        : getter(getter), setter(setter)
    {
    }

    operator T() const
    {
        return getter();
    }

    T operator=(const T value)
    {
        setter(value);
        return value;
    }
};

template <typename T>
class Property<T &>
{
protected:
    const std::function<T()> getter;
    const std::function<void(const T &)> setter;

public:
    Property(std::function<T()> getter, std::function<void(const T &)> setter = nullptr)
        : getter(getter), setter(setter)
    {
    }

    operator T() const
    {
        return getter();
    }

    const T &operator=(const T &value)
    {
        setter(value);
        return value;
    }
};
