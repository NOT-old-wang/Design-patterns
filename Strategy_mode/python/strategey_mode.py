class IVehicle:
    "交通工具的抽象类"

    def running(self):
        pass

class SharedBicycle(IVehicle):
    "共享单车"

    def running(self):
        print("骑共享单车(轻快便捷)", end='')


class ExpressBus(IVehicle):
    "快速公交"

    def running(self):
        print("坐快速公交(经济绿色)", end='')

class Express(IVehicle):
    "快车"

    def running(self):
        print("打快车(快速方便)", end='')


class Subway(IVehicle):
    "地铁"

    def running(self):
        print("坐地铁(高效安全)", end='')

class Classmate:
    "参加聚餐的同学"

    def __init__(self, name, vechicle):
        self.__name = name
        self.__vechicle = vechicle

    def attendTheDinner(self):
        print(self.__name + " ", end='')
        self.__vechicle.running()
        print(" 来参加聚餐！")