# coding=utf-8

class ReceiveParcel:
    "接收包裹"

    def __init__(self, name):
        self.__name = name

    def getName(self):
        return self.__name

    def receive(self, parcelContent):
        pass

class TonyReception(ReceiveParcel):
    "Tony 接收"

    def __init__(self, name, phoneNum):
        super().__init__(name)
        self.__phoneNum = phoneNum

    def getPhoneNum(self):
        return self.__phoneNum
    
    def receive(self, parcelContent):
        print("货物主人：" + self.getName() + ", 手机号: " + self.getPhoneNum())
        print("接收到 " + parcelContent )

class WendyReception(ReceiveParcel):
    "Wendy接收"

    def __init__(self, name, receiver):
        super().__init__(name)
        self.__receiver = receiver

    def receive(self, parcelContent):
        self.preReceive()
        if(self.__receiver is not None):
            self.__receiver.receive(parcelContent)
        self.afterReceive()

    def preReceive(self):
        print("我是" + self.__receiver.getName() + "的朋友， 我来帮他代收快递！")

    def afterReceive(self):
        print("代收人：" + self.getName())  

def testProxy():
    tony = TonyReception("tony","12345678") 
    wendy = WendyReception("wendy", tony)

    wendy.receive("玩具")


testProxy()

'''
class Subject:
    "主题"

    def request(self):
        pass

class RealSubject(Subject):
    "代理主题"

    def request(self):
        print("RealSubject todo something...")


class ProxySubject(Subject):
    "代理主题"

    def __init__(self, subject):
        self.__realSubject = subject

    def request(self):
        self.preRequest()
        if(self.__realSubject is not None):
            self.__realSubject.request()
        self.afterRequest()

    def preRequest(self):
        print("preRequest")

    def afterRequest(self):
        print("afterRequest")

def client():
    "客户端调用类"
    realObj = RealSubject()
    proxyObj = ProxySubject(realObj)
    proxyObj.request()
'''