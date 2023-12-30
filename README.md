# Property++

## Intro

A simple property implementation for C++

## Usage

```cpp
    #include "property.hpp"
    using namespace vermils::tricks

    class Foo {
        int _bar=0;
        public:
            Property<int> bar{
                [this] () -> int { return this->_bar; },
                [this] (int value) { this->_bar = value; }
            };
        });

        // or use more a performant version, but is much less elegant
        struct Bar : StaticProperty<int, Foo&>
        {
            Bar(Foo& foo) : StaticProperty<int, Foo&>(foo) {}
            using StaticProperty<int, Foo&>::operator=;
            void setter(int value) const override { this->value = value; }
            int getter() const override { return this->value; }
        }

        Bar static_bar{*this};
    };

    int main()
    {
        Foo foo;
        foo.bar = 1;
        foo.static_bar = 2;
        std::cout << foo.bar << std::endl; // 1
        std::cout << foo.static_bar << std::endl; // 2
        return 0;
    }
```

### For readonly

```cpp
    class Foo {
            int _bar=0;
        public:
            const Property<int> bar([this] () -> int { return this->_bar; });
    };
```
