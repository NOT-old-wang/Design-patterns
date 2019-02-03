
class Coffee:
    "咖啡"
    def __init__(self, name):
        self.__name = name

    def getName(self):
        return self.__name

    def getTaste(self):
        pass

class CaffeLatte(Coffee):
    "拿铁咖啡"

    def __init__(self, name):
        super().__init__(name)

    def getTaste(self):
        return "轻柔而香醇。"

class MochaCoffee(Coffee):
    "摩卡咖啡"

    def __init__(self, name):
        super().__init__(name)

    def getTaste(self):
        return "丝滑与醇厚。"

class Coffeemaker:
    "咖啡机"

    @staticmethod
    def makeCoffee(coffeeBean):
        coffee = None
        if(coffeeBean == "拿铁风味咖啡豆"):
            coffee = CaffeLatte("拿铁咖啡")
        elif(coffeeBean == "摩卡风味咖啡豆"):
            coffee = MochaCoffee("摩卡咖啡")
        else:
            coffee = Coffee()
        return coffee

def testCoffeeMaker():
    latte = Coffeemaker.makeCoffee("拿铁风味咖啡豆")
    print(latte.getName(), "已为您准备好了，口感：" + latte.getTaste() + "请慢慢享用！")
    mocha = Coffeemaker.makeCoffee("摩卡风味咖啡豆")
    print(mocha.getName(), "已为您准备好了，口感：" + mocha.getTaste() + "请慢慢享用！")

testCoffeeMaker()
