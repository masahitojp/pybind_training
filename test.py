import hello

hello.output("Hello, Boost.Python")

obj = hello.SomeObject(100)
print(obj.get_value())
obj.set_value(10)
print(obj.get_value())
