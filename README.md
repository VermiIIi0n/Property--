# Property++

## Intro

A simple property implementation for C++

## Usage

```cpp
    #include "property.hpp"

    class Foo {
        int _bar=0;
        public:
            Property<int> bar({
                [this] () -> int { return self->_bar; },
                [this] (int value) { self->_bar = value; }
            });
        });
    };

    int main()
    {
        Foo foo;
        foo.bar = 1;
        std::cout << foo.bar << std::endl; // 1
        return 0;
    }
```

### For readonly

```cpp
    class Foo {
            int _bar=0;
        public:
            const Property<int> bar([this] () -> int { return self->_bar; });
    };
```
